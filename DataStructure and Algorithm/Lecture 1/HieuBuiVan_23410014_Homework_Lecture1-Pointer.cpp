/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Bai tap ve nha buoi 1: con tro va cap phat dong
 *      Bai 3: Quan ly quan ly va  tinh tien luong cho cac nhan vien trong mot cong ty
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct NhanVien
{
    string maNV;
    string hoTen;
    double luongCB;
    float soNgayLamViec;
    double luongHangThang;
};

void addListNhanVien(NhanVien *nv, int &sizeOfList)
{
    sizeOfList = 10;
    for (int i = 0; i < sizeOfList; i++)
    {
        double luongCB = 200000.0 + (100 + i);
        *(nv + i) = {"NV0" + to_string(i), "Nguyen Van " + to_string(i), luongCB, (float)(20 + i), 0};
    }
}

void printMotNhanVien(NhanVien nv)
{
    cout << "{\t MaNV: " + nv.maNV;
    cout << "\n\t TenNV: " + nv.hoTen;
    cout << fixed;
    cout << "\n\t Luong can ban: ";
    cout << nv.luongCB;
    cout << "\n\t So ngay lam viec: ";
    cout << nv.soNgayLamViec;
    cout << "\n\t Luong hang thang: ";
    cout << nv.luongHangThang;
    cout << "\n } \n\n";
}

void printListNhanVien(NhanVien *nv, int &sizeOfList)
{
    for (int i = 0; i < sizeOfList; i++)
    {
        printMotNhanVien(*(nv + i));
    }
}

void tinhLuongHangThang(NhanVien &nv)
{
    nv.luongHangThang = nv.luongCB + nv.soNgayLamViec * 180000;
    if (nv.luongHangThang > 8000000)
    {
        nv.luongHangThang += nv.luongHangThang * 0.05; // 5%
    }
    else if (nv.luongCB < 5000000)
    {
        nv.luongHangThang += nv.luongHangThang * 0.1; // 10%
    }
}

void calculateAndUpdateSalaryEachNhanVien(NhanVien *nv, int &sizeOfList)
{
    for (int i = 0; i < sizeOfList; i++)
    {
        tinhLuongHangThang(*(nv + i));
    }
}

double totalSalaryWillPayOnMonth(NhanVien *nv, int &sizeOfList)
{
    double total = 0;
    for (int i = 0; i < sizeOfList; i++)
    {
        total += (nv + i)->luongHangThang;
    }
    return total;
}

double tongLuongNVCoLuongCBNhoHonNamTrieu(NhanVien *nv, int &sizeOfList)
{
    double total = 0;
    for (int i = 0; i < sizeOfList; i++)
    {
        if ((nv + i)->luongCB < 5000000)
        {
            total += (nv + i)->luongHangThang;
        }
    }
    return total;
}

void timNhanVienTheoMaNV(NhanVien *nv, int &sizeOfList, string keyword)
{
    for (int i = 0; i < sizeOfList; i++)
    {
        if ((nv + i)->maNV == keyword)
        {
            printMotNhanVien(*(nv + 1));
            return;
        }
        if (i == sizeOfList - 1)
        {
            cout << "Khong tim thay nhan vien nao co ma: " << keyword << endl;
        }
    }
}

/**
 * Tim cac nhan vien co luong cao nhat va thap nhat
 *      condition: 1: luong cao nhat. 0: luong thap nhat
 */
void timNhanVienTheoLuong(NhanVien *nv, int &sizeOfList, int condition)
{
    double luongHangThang = (nv + 0)->luongHangThang;
    for (int i = 0; i < sizeOfList; i++)
    {
        switch (condition)
        {
        case 0: // Min
            if ((nv + i)->luongHangThang < luongHangThang)
            {
                luongHangThang = (nv + i)->luongHangThang;
            }
            break;
        case 1: // Max
            if ((nv + i)->luongHangThang > luongHangThang)
            {
                luongHangThang = (nv + i)->luongHangThang;
            }
            break;
        }
    }
    for (int i = 0; i < sizeOfList; i++) {
        if ((nv + i)->luongHangThang == luongHangThang)
        {
            printMotNhanVien(*(nv + i));
        }
    }
}

int main(int argc, char const *argv[])
{
    cout << "================ Chuong trinh quan ly thong tin nhan vien va tien luong ================" << endl;

    cout << "1.2. Them va in danh sach nhan vien: " << endl;
    int sizeOfList = 100;
    NhanVien *nv = new NhanVien[sizeOfList];
    addListNhanVien(nv, sizeOfList);
    printListNhanVien(nv, sizeOfList);

    cout << "\n3. Danh sach nhan vien sau khi tinh luong: " << endl;
    calculateAndUpdateSalaryEachNhanVien(nv, sizeOfList);
    printListNhanVien(nv, sizeOfList);

    cout << "\n4. Tong luong phai tra cho toan bo nhan vien: " << endl;
    cout << totalSalaryWillPayOnMonth(nv, sizeOfList) << endl;

    cout << "\n5. Tong luong can ban nhan vien hang thang < 5 trieu: " << endl;
    cout << tongLuongNVCoLuongCBNhoHonNamTrieu(nv, sizeOfList) << endl;

    cout << "\n6. Tim nhan vien theo maNV: " << endl;
    timNhanVienTheoMaNV(nv, sizeOfList, "NV01");

    cout << "\n7. Tim nhan vien co luong hang thang thap nhat: " << endl;
    timNhanVienTheoLuong(nv, sizeOfList, 0);

    cout << "\n8. Tim nhan vien co luong hang thang cao nhat: " << endl;
    timNhanVienTheoLuong(nv, sizeOfList, 1);

    return 0;
}
