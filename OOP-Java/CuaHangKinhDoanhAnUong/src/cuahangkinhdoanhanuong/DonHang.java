package cuahangkinhdoanhanuong;

import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import utils.CommonInfo;
import utils.CuaHangException;
import utils.IInputOutput;
import utils.InputOutput;

public class DonHang implements IInputOutput {

    private String maDH;
    private KhachHang khachHang;
    private ArrayList<MatHangCanMua> hangCanMua;
    private QuanLyMatHang quanLyMatHang;

    public DonHang() {
        khachHang = new KhachHang();
        this.hangCanMua = new ArrayList();
    }

    public DonHang(String maDH, KhachHang khachHang, ArrayList<MatHangCanMua> hangCanMua) {
        khachHang = new KhachHang();
        this.hangCanMua = new ArrayList();
        this.maDH = maDH;
        this.khachHang = khachHang;
        this.hangCanMua = hangCanMua;
    }

    public String getMaDH() {
        return maDH;
    }

    public void setMaDH(String maDH) throws CuaHangException {
        if (maDH == null || maDH.isBlank() || maDH.isEmpty()) {
            throw new CuaHangException("Ma don hang khong hop le!");
        }
        this.maDH = maDH;
    }

    public KhachHang getKhachHang() {
        return khachHang;
    }

    public void setKhachHang(KhachHang khachHang) throws CuaHangException {
        if (khachHang == null) {
            throw new CuaHangException("Khach hang khong hop le!");
        }
        this.khachHang = khachHang;
    }

    public ArrayList<MatHangCanMua> getHangCanMua() {
        return hangCanMua;
    }

    public void setHangCanMua(ArrayList<MatHangCanMua> hangCanMua) throws CuaHangException {
        if (hangCanMua == null || hangCanMua.isEmpty()) {
            throw new CuaHangException("Danh sach hang can mua khong de trong!");
        }
        this.hangCanMua = hangCanMua;
    }

    public QuanLyMatHang getQuanLyMatHang() {
        return quanLyMatHang;
    }

    public void setQuanLyMatHang(QuanLyMatHang quanLyMatHang) {
        this.quanLyMatHang = quanLyMatHang;
    }

    public void themMatHangCanMua(MatHangCanMua matHangCanMua) throws CuaHangException {
        if (matHangCanMua == null) {
            throw new CuaHangException("Mat hang can mua khong de trong!");
        }
        this.hangCanMua.add(matHangCanMua);
    }

    public double tinhTienDonHang() throws CuaHangException {
        if (this.khachHang == null || this.khachHang.getSoDienThoai().isBlank()) {
            throw new CuaHangException("Can nhap thong tin day du thong tin khach hang de tinh tien!");
        }
        if (this.hangCanMua.isEmpty()) {
            throw new CuaHangException("Can them thong tin nhung mat hang can mua!");
        }
        if (this.khachHang.getLoaiKhachHang().isEmpty()) {
            throw new CuaHangException("Thong tin khach hang thieu thong tin loai khach hang!");
        }
        double tongTienDonHang = 0;
        for (MatHangCanMua matHangCanMua : hangCanMua) {
            if (matHangCanMua.getMatHang() instanceof RuouBia) {
                double tienThueTieuThuDacBiet = matHangCanMua.tongTienMotMatHang() * CommonInfo.THUE_TIEU_THU_DAC_BIET;
                tongTienDonHang += (matHangCanMua.tongTienMotMatHang() + tienThueTieuThuDacBiet);
            } else {
                tongTienDonHang += matHangCanMua.tongTienMotMatHang();
            }
        }
        return tongTienDonHang; 
    }

    public double tinhTienChietKhau(double tongTienDonHang) {
        return InputOutput.formatCurrency(tongTienDonHang * CommonInfo.CHIET_KHAU);
    }

    public double tinhTienThueGiaTriGiaTang(double tongTienDonHang) {
        return InputOutput.formatCurrency(tongTienDonHang * CommonInfo.THUE_GIA_TRI_GIA_TANG);
    }
    
    public double tongTienThanhToan(double tongTienDonHang) {
        if (this.khachHang.getLoaiKhachHang().equals(CommonInfo.VIP)) {
            tongTienDonHang -= tinhTienChietKhau(tongTienDonHang);
        }
        tongTienDonHang += tinhTienThueGiaTriGiaTang(tongTienDonHang);
        return InputOutput.formatCurrency(tongTienDonHang);
    }

    @Override
    public void input() {
        try {
            System.out.println("================ Nhap don hang cho khach hang ===============\n");

            this.setMaDH(InputOutput.inputString("Nhap ma don hang: "));
            khachHang.input();

            int soMatHang = 0;
            soMatHang = InputOutput.inputInteger("Nhap so luong mat hang can mua: ");
            for (int i = 0; i < soMatHang; i++) {
                MatHangCanMua matHangCanMua = new MatHangCanMua();
                System.out.println("Mat hang " + (i + 1));
                String maDonHangCanMua = InputOutput.inputString("Nhap ma mat hang can mua: ");
                MatHang matHangCanTim = new MatHang();
                do {
                    matHangCanTim = this.quanLyMatHang.timMatHangTheoMa(maDonHangCanMua);
                    if (matHangCanTim != null && matHangCanTim.getMa() != null) {
                        matHangCanMua.setMatHang(matHangCanTim);
                        break;
                    }
                } while (matHangCanTim == null || matHangCanTim.getMa().isEmpty());

                matHangCanMua.input();
                themMatHangCanMua(matHangCanMua);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void output() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        try {
            double tongTienDonHang = tinhTienDonHang();
            String donHangInfo = "\n================= Thong tin don hang =================\n";
            donHangInfo += "+ Ma don hang: " + this.getMaDH() + ": ";
            donHangInfo += "\n+ Khach Hang: ";
            donHangInfo += this.khachHang.toString();
            donHangInfo += "\n----------------------------------------\n";
            donHangInfo += "+ Cac mat hang da mua: \n";

            String header = String.format("|%-30s|%-30s|%-30s|%-30s|%-33s|\n", "Ma MH", "Ten MH", "Gia ban", "So luong", "Tong Tien");
            donHangInfo += header;

            for (MatHangCanMua matHangCanMua : hangCanMua) {
                String item = String.format("|%-30s|%-30s|%-30s|%-30s|%-30s VND|\n", matHangCanMua.getMatHang().getMa(), matHangCanMua.getMatHang().getTen(), matHangCanMua.getMatHang().getDonGiaBan(), matHangCanMua.getSoLuong(), matHangCanMua.tongTienMotMatHang());
                donHangInfo += item;

            }
            donHangInfo += "\n*************************************************\n";
            donHangInfo += "+ Tong tien don hang: " + InputOutput.formatCurrency(tongTienDonHang) + " " + CommonInfo.VI_CURRENCY + "\n";
            donHangInfo += "+ Chiet Khau: " + (tinhTienChietKhau(tongTienDonHang)) + " " + CommonInfo.VI_CURRENCY + "\n";
            donHangInfo += "+ Thue GTGT: " + tinhTienThueGiaTriGiaTang(tongTienDonHang)+ " " + CommonInfo.VI_CURRENCY + "\n";
            donHangInfo += "+ Tong tien thanh toan: " + tongTienThanhToan(tongTienDonHang)+ " " + CommonInfo.VI_CURRENCY + "\n";
            
            donHangInfo += "\n --- Don gia da bao gom thue tieu thu dac biet! --- \n";
            donHangInfo += "\n *** Xin cam on quy khach *** \n";
            return donHangInfo;

        } catch (CuaHangException ex) {
            Logger.getLogger(DonHang.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }

}
