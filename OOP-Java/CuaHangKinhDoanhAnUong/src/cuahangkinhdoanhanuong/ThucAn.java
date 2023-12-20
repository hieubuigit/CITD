package cuahangkinhdoanhanuong;

import java.util.Date;

public class ThucAn extends MatHang {

    public ThucAn() {
    }

    public ThucAn(String ma, String ten, Date ngaySanXuat, Date ngayHetHan, double donGiaNhap, double donGiaBan, String donViTinh, String noiSanXuat, int soLuongTonKho) {
        super(ma, ten, ngaySanXuat, ngayHetHan, donGiaNhap, donGiaBan, donViTinh, noiSanXuat, soLuongTonKho);
    }

    @Override
    public String toString() {
        return "ThucAn{" + super.toString() + "\n}";
    }
}
