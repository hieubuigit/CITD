package cuahangkinhdoanhanuong;

import java.util.Date;
import utils.CuaHangException;
import utils.InputOutput;

public class RuouBia extends MatHang {

    private double dungTich;
    private double doCon;

    public RuouBia() {
    }

    public RuouBia(double dungTich, double doCon) {
        this.dungTich = dungTich;
        this.doCon = doCon;
    }

    public RuouBia(String ma, String ten, Date ngaySanXuat, Date ngayHetHan, double donGiaNhap, double donGiaBan, String donViTinh, String noiSanXuat, int soLuongTonKho, double dungTich, double doCon) {
        super(ma, ten, ngaySanXuat, ngayHetHan, donGiaNhap, donGiaBan, donViTinh, noiSanXuat, soLuongTonKho);
        this.dungTich = dungTich;
        this.doCon = doCon;
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

    public double getDoCon() {
        return doCon;
    }

    public void setDoCon(double doCon) throws CuaHangException {
        if (doCon < 0) {
            throw new CuaHangException("Nhap do con khong hop le!");
        }
        this.doCon = doCon;
    }

    @Override
    public void input() {
        try {
            super.input();
            this.setDungTich(InputOutput.inputDouble("Nhap dung tich: "));
            this.setDoCon(InputOutput.inputDouble("Nhap nong do con: "));
            System.out.println("\n-------------------------------------\n");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void output() {
        System.out.println("RuouBia{" + this.toString() + "\n}");
    }

    @Override
    public String toString() {
        return super.toString() + ", \t\n doCon=" + getDoCon() + ",  \t\n dungTich=" + getDungTich();
    }

}
