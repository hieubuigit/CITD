package cuahangkinhdoanhanuong;

import java.util.Date;
import utils.*;

public class MatHang implements IInputOutput {

    private String ma;
    private String ten;
    private Date ngaySanXuat;
    private Date ngayHetHan;
    private double donGiaNhap;
    private double donGiaBan;
    private String donViTinh;
    private String noiSanXuat;
    private int soLuongTonKho;

    public MatHang() {
    }

    public MatHang(String ma, String ten, Date ngaySanXuat, Date ngayHetHan, double donGiaNhap, double donGiaBan, String donViTinh, String noiSanXuat, int soLuongTonKho) {
        this.ma = ma;
        this.ten = ten;
        this.ngaySanXuat = ngaySanXuat;
        this.ngayHetHan = ngayHetHan;
        this.donGiaNhap = donGiaNhap;
        this.donGiaBan = donGiaBan;
        this.donViTinh = donViTinh;
        this.noiSanXuat = noiSanXuat;
        this.soLuongTonKho = soLuongTonKho;
    }

    public String getMa() {
        return ma;
    }

    public void setMa(String ma) throws CuaHangException {
        if (ma == null || ma.isBlank() || ma.isEmpty()) {
            throw new CuaHangException("Nhap ma khong hop le!");
        }
        this.ma = ma;
    }

    public String getTen() {
        return ten;
    }

    public void setTen(String ten) throws CuaHangException {
        if (ten == null || ten.isBlank() || ten.isEmpty()) {
            throw new CuaHangException("Ten khong hop le!");
        }
        this.ten = ten;
    }

    public Date getNgaySanXuat() {
        return ngaySanXuat;
    }

    public void setNgaySanXuat(Date ngaySanXuat) {
        this.ngaySanXuat = ngaySanXuat;
    }

    public Date getNgayHetHan() {
        return ngayHetHan;
    }

    public void setNgayHetHan(Date ngayHetHan) {
        this.ngayHetHan = ngayHetHan;
    }

    public double getDonGiaNhap() {
        return donGiaNhap;
    }

    public void setDonGiaNhap(double donGiaNhap) throws CuaHangException {
        if (donGiaNhap < 0) {
            throw new CuaHangException("Don gia nhap khong hop le");
        }
        this.donGiaNhap = donGiaNhap;
    }

    public double getDonGiaBan() {
        return donGiaBan;
    }

    public void setDonGiaBan(double donGiaBan) throws CuaHangException {
        if (donGiaBan < 0) {
            throw new CuaHangException("Don gia ban khong hop le");
        }
        this.donGiaBan = donGiaBan;
    }

    public String getDonViTinh() {
        return donViTinh;
    }

    public void setDonViTinh(String donViTinh) throws CuaHangException {
        if (donViTinh == null || donViTinh.isBlank() || donViTinh.isEmpty()) {
            throw new CuaHangException("Don vi tinh khong hop le!");
        }
        this.donViTinh = donViTinh;
    }

    public String getNoiSanXuat() {
        return noiSanXuat;
    }

    public void setNoiSanXuat(String noiSanXuat) throws CuaHangException {
        if (noiSanXuat == null || noiSanXuat.isBlank() || noiSanXuat.isEmpty()) {
            throw new CuaHangException("Noi san xuat khong hop le!");
        }
        this.noiSanXuat = noiSanXuat;
    }

    public int getSoLuongTonKho() {
        return soLuongTonKho;
    }

    public void setSoLuongTonKho(int soLuongTonKho) throws CuaHangException {
        if (soLuongTonKho < 0) {
            throw new CuaHangException("So luong ton kho khong hop le!");
        }
        this.soLuongTonKho = soLuongTonKho;
    }

    @Override
    public void input() {
        try {
            this.setMa(InputOutput.inputString("Nhap ma mat hang: "));
            this.setTen(InputOutput.inputString("Nhap ten mat hang: "));
            this.setNgaySanXuat(InputOutput.inputDate("Nhap ngay san xuat " + InputOutput.DATE_FORMAT + ": "));
            this.setNgayHetHan(InputOutput.inputDate("Nhap ngay het han " + InputOutput.DATE_FORMAT + ": "));
            this.setDonGiaNhap(InputOutput.inputDouble("Nhap don gia nhap: "));
            this.setDonGiaBan(InputOutput.inputDouble("Nhap don gia ban: "));
            this.setDonViTinh(InputOutput.inputString("Nhap don vi tinh: "));
            this.setNoiSanXuat(InputOutput.inputString("Nhap noi san xuat: "));
            this.setSoLuongTonKho(InputOutput.inputInteger("Nhap so luong ton kho: "));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void output() {
        System.out.println("MatHang{" + this.toString() + "\n}");
    }

    @Override
    public String toString() {
        return "\t\n ma=" + ma + ", "
                + "\t\n ten=" + ten + ", "
                + "\t\n ngaySanXuat=" + ngaySanXuat + ", "
                + "\t\n ngayHetHan=" + ngayHetHan + ", "
                + "\t\n donGiaNhap=" + donGiaNhap + ", "
                + "\t\n donGiaBan=" + donGiaBan + ", "
                + "\t\n donViTinh=" + donViTinh + ", "
                + "\t\n noiSanXuat=" + noiSanXuat + ", "
                + "\t\n soLuongTonKho=" + soLuongTonKho;
    }

}
