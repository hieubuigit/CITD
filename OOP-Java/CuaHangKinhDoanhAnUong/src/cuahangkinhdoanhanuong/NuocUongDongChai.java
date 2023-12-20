package cuahangkinhdoanhanuong;

import java.util.Date;
import utils.CuaHangException;
import utils.InputOutput;

public class NuocUongDongChai extends MatHang {

    private double dungTich;

    public NuocUongDongChai() {
    }

    public NuocUongDongChai(double dungTich) {
        this.dungTich = dungTich;
    }

    public NuocUongDongChai(String ma, String ten, Date ngaySanXuat, Date ngayHetHan, double donGiaNhap, double donGiaBan, String donViTinh, String noiSanXuat, int soLuongTonKho, double dungTich) {
        super(ma, ten, ngaySanXuat, ngayHetHan, donGiaNhap, donGiaBan, donViTinh, noiSanXuat, soLuongTonKho);
        this.dungTich = dungTich;
    }

    public double getDungTich() {
        return dungTich;
    }

    public void setDungTich(double dungTich) throws CuaHangException {
        if (dungTich < 0) {
            throw new CuaHangException("Nhap dung tich khong hop le!");
        }
        this.dungTich = dungTich;
    }

    @Override
    public void input() {
        try {
            super.input();
            this.setDungTich(InputOutput.inputDouble("Nhap dung tich: "));
            System.out.println("\n-------------------------------------\n");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void output() {
        System.out.println("NuocUongDongChai{" + this.toString() + "\n}");
    }

    @Override
    public String toString() {
        return super.toString() + "\t\n dungTich=" + getDungTich();
    }

}
