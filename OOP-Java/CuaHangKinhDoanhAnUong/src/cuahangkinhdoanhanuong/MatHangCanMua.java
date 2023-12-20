package cuahangkinhdoanhanuong;

import utils.CommonInfo;
import utils.CuaHangException;
import utils.IInputOutput;
import utils.InputOutput;

public class MatHangCanMua implements IInputOutput {

    private MatHang matHang;
    private int soLuong;

    public MatHangCanMua() {
        matHang = new MatHang();
    }

    public MatHangCanMua(MatHang matHang, int soLuong) {
        matHang = new MatHang();
        this.matHang = matHang;
        this.soLuong = soLuong;
    }

    public MatHang getMatHang() {
        return matHang;
    }

    public void setMatHang(MatHang matHang) throws CuaHangException {
        if (matHang == null) {
            throw new CuaHangException("Mang hang khong hop le!");
        }
        this.matHang = matHang;
    }

    public int getSoLuong() {
        return soLuong;
    }

    public void setSoLuong(int soLuong) throws CuaHangException {
        if (soLuong < 0) {
            throw new CuaHangException("So luong khong hop le!");
        }
        this.soLuong = soLuong;
    }
    
    public double tongTienMotMatHang() {
        double tongTienMotDH = this.matHang.getDonGiaBan() * getSoLuong();
        return InputOutput.formatCurrency(tongTienMotDH);
    }

    @Override
    public void input() {
        try {
            this.setSoLuong(InputOutput.inputInteger("Nhap so luong can mua: "));
            System.out.println("\n-------------------------------------\n");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public void menuChonMatHang() throws CuaHangException {
        int option = -1;
        String optionsMenu = "-------------- Nhap lua chon don hang can nhap (nhap so): --------------";
        optionsMenu += "\n\t 1. Thuc An";
        optionsMenu += "\n\t 2. Ruou Bia";
        optionsMenu += "\n\t 3. Nuoc uong dong chai \n";
        optionsMenu += "========================================\n";
        option = InputOutput.inputInteger(optionsMenu);
        switch (option) {
            case CommonInfo.THUC_AN:
                ThucAn thucAn = new ThucAn();
                thucAn.input();
                this.setMatHang(thucAn);
                break;
            case CommonInfo.RUOU_BIA:
                RuouBia ruouBia = new RuouBia();
                ruouBia.input();
                this.setMatHang(ruouBia);
                break;
            case CommonInfo.NUOC_UONG_DONG_CHAI:
                NuocUongDongChai nuocUongDongChai = new NuocUongDongChai();
                nuocUongDongChai.input();
                this.setMatHang(nuocUongDongChai);
                break;
            default:
                System.out.println("Lua chon khong hop le!");
                break;
        }
    }

    @Override
    public void output() {
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        return "MatHangCanMua{"
                + "\t\n matHang=" + matHang.toString()
                + "\t\n soLuong=" + soLuong
                + "\t\n tongTien=" + tongTienMotMatHang()
                + "\n}";
    }

}
