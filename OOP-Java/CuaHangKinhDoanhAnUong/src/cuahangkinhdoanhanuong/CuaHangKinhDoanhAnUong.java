package cuahangkinhdoanhanuong;

import java.util.Date;
import utils.InputOutput;

public class CuaHangKinhDoanhAnUong {

    public static void main(String[] args) {

        // Them danh sach don hang vao kho truoc khi ban ra cho khach hang
        ThucAn thucAn = new ThucAn("TA01", "Thuc An 01", new Date(2023, 12, 10), new Date(2023, 12, 12), 20, 25, "Phan", "Binh Duong", 5000);
        RuouBia ruouBia = new RuouBia("RB01", "Ruou Bia 01", new Date(2023, 12, 11), new Date(2024, 02, 12), 10, 15, "phan", "Thu Duc", 10000, 250, 1.9);
        NuocUongDongChai nuocUongDongChai = new NuocUongDongChai("NUDC01", "Aquafina", new Date(2023, 12, 10), new Date(2024, 12, 11), 10, 12, "Thung", "TP.HCM", 7000, 500);

        // Nhap hang vao kho
        QuanLyMatHang qlyMatHang = new QuanLyMatHang();
        // qlyMatHang.menuNhapMatHang();        // Co the nhap thong tin don hang tu ban phim
        qlyMatHang.themMatHang(thucAn);
        qlyMatHang.themMatHang(ruouBia);
        qlyMatHang.themMatHang(nuocUongDongChai);
        qlyMatHang.toString();

        // Them va xuat thong tin don hang cho khach hang
        DonHang donHang = new DonHang();
        donHang.setQuanLyMatHang(qlyMatHang);
        donHang.input();
        donHang.output();
    }

}
