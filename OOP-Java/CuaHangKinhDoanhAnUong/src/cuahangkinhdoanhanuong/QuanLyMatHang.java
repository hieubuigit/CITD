package cuahangkinhdoanhanuong;

import java.util.ArrayList;
import utils.CommonInfo;
import utils.InputOutput;

public class QuanLyMatHang {

    private ArrayList<MatHang> dsMatHang;

    public QuanLyMatHang() {
        dsMatHang = new ArrayList();
    }

    public QuanLyMatHang(ArrayList<MatHang> dsMatHang) {
        this.dsMatHang = dsMatHang;
    }

    public ArrayList<MatHang> getDsMatHang() {
        return dsMatHang;
    }

    public void setDsMatHang(ArrayList<MatHang> dsMatHang) {
        this.dsMatHang = dsMatHang;
    }

    public void themMatHang(MatHang matHang) {
        this.dsMatHang.add(matHang);
    }

    public void xoaMatHangTheoMa(String maMatHang) {
        for (MatHang matHang : dsMatHang) {
            if (matHang.getMa().equals(maMatHang)) {
                this.dsMatHang.remove(matHang);
            }
        }
    }

    public MatHang timMatHangTheoMa(String maMatHang) {
        for (int i = 0; i < this.dsMatHang.size(); i++) {
            for (MatHang matHang : dsMatHang) {
                if (matHang.getMa().equals(maMatHang)) {
                    return matHang;
                }
            }
        }
        return null;
    }

    public void menuNhapMatHang() {

        int numberMH = 0;
        numberMH = InputOutput.inputInteger("\n Nhap so luong mat hang can nhap: ");
        for (int i = 0; i < numberMH; i++) {
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
                    this.themMatHang(thucAn);
                    break;
                case CommonInfo.RUOU_BIA:
                    RuouBia ruouBia = new RuouBia();
                    ruouBia.input();
                    this.themMatHang(ruouBia);
                    break;
                case CommonInfo.NUOC_UONG_DONG_CHAI:
                    NuocUongDongChai nuocUongDongChai = new NuocUongDongChai();
                    nuocUongDongChai.input();
                    this.themMatHang(nuocUongDongChai);
                    break;
                default:
                    System.out.println("Lua chon khong hop le!");
                    break;
            }
        }
    }

    @Override
    public String toString() {
        return "QuanLyMatHang{" + "dsMatHang=" + dsMatHang + '}';
    }

}
