#include <iostream>
using namespace std;

struct HoaDon
{
    int maHD;       // Ma hoa don
    string tenKH;   // Ten khach hang
    int soSP;       // So san pham
    float tongTien; // Tong tien
};
typedef HoaDon HD;

struct Node
{
    HoaDon hd;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *initNode(HD *hd)
{
    Node *newNode = new Node;
    newNode->hd.maHD = hd->maHD;
    newNode->hd.tenKH = hd->tenKH;
    newNode->hd.soSP = hd->soSP;
    newNode->hd.tongTien = hd->tongTien;
    newNode->pNext = NULL;
    return newNode;
}

void initList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

HD *initHD(int maHD, string tenKH, int soSP, float tongTien)
{
    HD *hd = new HD;
    hd->maHD = maHD;
    hd->tenKH = tenKH;
    hd->soSP = soSP;
    hd->tongTien = tongTien;
    return hd;
}



/**
 * Cau 1: chen node chua hoa don vao dau danh sach
 *      + Input:
 *          - List &list: list danh sach hoa don can them.
 *          - Node *newNode: thong tin cua hoa don can them vao danh sach
 *      + Output:
 *          - bool: true neu them thanh cong, nguoc lai false
 */
bool addHead(List &list, Node *newNode)
{
    if (list.pTail == NULL)
    {
        list.pHead = newNode;
        list.pTail = newNode;
    }
    else
    {
        newNode->pNext = list.pHead;
        list.pHead = newNode;
    }
    return newNode->hd.maHD == list.pHead->hd.maHD;
}


/**
 * Cau 2: In danh sach hoa don
 *      + Input:
 *          - List list: list danh sach hoa don can them
 *      + Output: void
 */
void printList(List list)
{
    Node *n = list.pHead;
    while (n != NULL)
    {
        cout << "---------------------------------------\n";
        cout << "\t Ma hoa don: " << n->hd.maHD << endl;
        cout << "\t Ten KH: " << n->hd.tenKH << endl;
        cout << "\t So san pham: " << n->hd.soSP << endl;
        cout << "\t Tong tien: " << n->hd.tongTien << endl;
        cout << "---------------------------------------\n";
        n = n->pNext;
    }
}

/**
 * Cau 3: Tim hoa don
 *      + Input:
 *          - List list: list danh sach hoa don can them
 *          - int maHD: ma hoa don can tim.
 *      + Output:
 *          - Node * : dia chi vung nho hoa don khi tim thay, nguoc lai return NULL
 */
Node *timHoaDon(List list, int maHD)
{
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->hd.maHD == maHD)
        {
            return n;
        }
    }
    return NULL;
}

/**
 * Cau 4: Ham dem hoa don trong danh sach
 *      + Input:
 *          - List list: list danh sach hoa don can them
 *      + Output:
 *          - int: so luong hoa don co trong danh sach
 */
int demHoaDonTrongDanhSach(List list)
{
    int countHD = 0;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        countHD += 1;
    }
    return countHD;
}


/**
 * Cau 5: Tinh tong so luong san pham cua tat ca hoa don trong danh sach
 *      + Input:
 *          - List list: list danh sach hoa don can them.
 *      + Output:
 *          - int: so luong hoa don co trong danh sach
 */
int demTongSPCuaTatCaHD(List list)
{
    int countSP = 0;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        countSP += n->hd.soSP;
    }
    return countSP;
}

/**
 * Cau 6: Tim ma hoa don co so luong san pham lon nhat
 *      + Input:
 *          - List list: list danh sach hoa don can them.
 *      + Output:
 *          - int: so luong so san pham co trong trong danh sach
 */
int timMaHDCoSoSPLonNhat(List list)
{
    int maxSP = list.pHead->hd.soSP;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->hd.soSP > maxSP)
        {
            maxSP = n->hd.soSP;
        }
    }
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->hd.soSP == maxSP)
        {
            return n->hd.maHD;
        }
    }
    return 0;
}

/**
 * Cau 7: Ham tim tong tien nho nhat
 *      + Input:
 *          - List list: list danh sach hoa don can them.
 *      + Output:
 *          - float: tong tien thap nhat trong danh sach
 */
float timTongTienThapNhat(List list)
{
    int minTongTien = list.pHead->hd.tongTien;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->hd.tongTien < minTongTien)
        {
            minTongTien = n->hd.tongTien;
        }
    }
    return minTongTien;
}

/**
 * Cau 8: Ham cap nhat ten khach hang theo ma hoa don.
 *      + Input:
 *          - List list: list danh sach hoa don can them.
 *      + Output:
 *          - bool: tra ve true neu cap nhat thanh cong, nguoc lai tra ve false.
 */
bool capNhatTenKHTheoMaHD(List &list, int maHD, string tenKH)
{
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->hd.maHD == maHD)
        {
            n->hd.tenKH = tenKH;
            return true;
        }
    }
    return false;
}

/**
 * Cau 9: Ham tao danh sach hoa don moi co so san pham < 5
 *      + Input:
 *          - List list: list danh sach hoa don can them.
 *      + Output:
 *          - bool: tra ve true neu cap nhat thanh cong, nguoc lai tra ve false.
 */
void initHoaDonVoiSoSP(List &list) {

}

int main(int argc, char const *argv[])
{

    /**
     * Cau 10: Tao 6 hoa don co du lieu nhu sau
    */
    List list;
    initList(list);

    cout << "\n============== Cau 1 ==============\n";
    cout << "Them danh sach hoa don vao danh sach\n";
    addHead(list, initNode(initHD(800, "Yen Nhi", 8, 5000000)));
    addHead(list, initNode(initHD(801, "Yen Tam", 9, 7000000)));
    addHead(list, initNode(initHD(802, "Chi Thy", 2, 900000)));
    addHead(list, initNode(initHD(803, "Anh Hoa", 9, 70000)));
    addHead(list, initNode(initHD(804, "Bot Heo", 4, 800000)));
    addHead(list, initNode(initHD(805, "Chi Hoa", 9, 5000000)));


    cout << "\n============== Cau 2 ==============\n";
    cout << " In danh sach hoa don\n";
    printList(list);


    cout << "\n============== Cau 3 ==============\n";
    int maHDCanTim = 800;
    Node *result = timHoaDon(list, maHDCanTim);
    if (result != NULL)
    {
        cout << "Tim thay hoa don co ma " << maHDCanTim << " trong danh sach";
    } else {
        cout << "Khong tim thay hoa don co ma " << maHDCanTim << " trong danh sach";
    }
    cout << endl;


    cout << "\n============== Cau 4 ==============\n";
    int soLuongHD = demHoaDonTrongDanhSach(list);
    cout << "So luong hoa don co trong danh sach = " << soLuongHD << endl;


    cout << "\n============== Cau 5 ==============\n";
    int tongSP = demTongSPCuaTatCaHD(list);
    cout << "Tong so luong SP cua tat ca hoa don = " << tongSP << endl;


    cout << "\n============== Cau 6 ==============\n";
    int maHDCoMaxSP = timMaHDCoSoSPLonNhat(list);
    cout << "Ma hoa don co tong so sp lon nhat = " << maHDCoMaxSP << endl;


    cout << "\n============== Cau 7 ==============\n";
    int minTongTien = timTongTienThapNhat(list);
    cout << "Tong tien nho nhat = " << minTongTien << endl;


    cout << "\n============== Cau 8 ==============\n";
    int maHDUpdate = 800;
    string tenKH = "Hieu Bui";
    bool resultUpdate = capNhatTenKHTheoMaHD(list, maHDUpdate, tenKH);
    if (resultUpdate)
    {
        cout << "Cap nhat thanh cong\n";
    } else {
        cout << "Cap nhat that bai\n";
    }
    printList(list);


    cout << "\n============== Cau 9 ==============\n";


    return 0;
}
