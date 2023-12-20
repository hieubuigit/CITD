package cuahangkinhdoanhanuong;

import utils.CuaHangException;
import utils.IInputOutput;
import utils.InputOutput;

public class KhachHang implements IInputOutput {

    private String soDienThoai;
    private String tenKhachHang;
    private String diaChi;
    private String loaiKhachHang;

    public KhachHang() {
    }

    public KhachHang(String soDienThoai, String tenKhachHang, String diaChi, String loaiKhachHang) {
        this.soDienThoai = soDienThoai;
        this.tenKhachHang = tenKhachHang;
        this.diaChi = diaChi;
        this.loaiKhachHang = loaiKhachHang;
    }

    public String getSoDienThoai() {
        return soDienThoai;
    }

    public void setSoDienThoai(String soDienThoai) throws CuaHangException {
        if (soDienThoai == null || soDienThoai.isBlank() || soDienThoai.isEmpty()) {
            throw new CuaHangException("So dien thoai khong hop le!");
        }
        this.soDienThoai = soDienThoai;
    }

    public String getTenKhachHang() {
        return tenKhachHang;
    }

    public void setTenKhachHang(String tenKhachHang) {
        this.tenKhachHang = tenKhachHang;
    }

    public String getDiaChi() {
        return diaChi;
    }

    public void setDiaChi(String diaChi) {
        this.diaChi = diaChi;
    }

    public String getLoaiKhachHang() {
        return loaiKhachHang;
    }

    public void setLoaiKhachHang(String loaiKhachHang) throws CuaHangException {
        if (loaiKhachHang == null || loaiKhachHang.isBlank() || loaiKhachHang.isEmpty()) {
            throw new CuaHangException("Loai khach hang khong hop le!");
        }
        this.loaiKhachHang = loaiKhachHang;
    }

    @Override
    public void input() {
        try {
            this.setSoDienThoai(InputOutput.inputString("Nhap so dien thoai: "));
            this.setTenKhachHang(InputOutput.inputStringNotRequired("Nhap ten khach hang: "));
            this.setDiaChi(InputOutput.inputStringNotRequired("Nhap dia chi: "));
            this.setLoaiKhachHang(InputOutput.inputString("Nhap loai khach hang: "));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void output() {
        System.out.println("KhachHang{" + this.toString() + "\n}");
    }

    @Override
    public String toString() {
        return "\t\n So Dien Thoai: " + soDienThoai + ", "
                + "\t\n Ten Khach Hang: " + tenKhachHang + ","
                + "\t\n Dia Chi: " + diaChi + ","
                + "\t\n Loai Khach Hang: " + loaiKhachHang;
    }

}
