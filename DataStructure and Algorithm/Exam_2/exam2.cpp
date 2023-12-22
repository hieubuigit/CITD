/**
 * Name: Hieu Bui Van
 * StudentId: 23410014
 * Class: LT.2023.01
 * Des: Exam 2
 */

#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    int maSV;
    string hoTen;
    float diemMH;
};
typedef SinhVien SV;

struct Node
{
    SinhVien sv;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

/**
 * + Input:
 *      - SV sv: thong tin cua mot sinh vien
 * + Output:
 *      - Node: 1 node dia chi vung nho chua thong tin sinh vien
*/
Node *initNode(SV *sv)
{
    Node *newNode = new Node;
    newNode->sv.maSV = sv->maSV;
    newNode->sv.hoTen = sv->hoTen;
    newNode->sv.diemMH = sv->diemMH;
    newNode->pNext = NULL;
    return newNode;
}

/**
 * + Input:
 *      - List &list: danh sach singly linked list can luu tru thong tin sinh vien
 * + Output:
 *      - void
*/
void initList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

/**
 * Cau 1: Chen node sinh vien vao cuoi danh sach
 *      + Input:
 *          - List &list: list danh sach sinh vien can them
 *          - Node *newNode: thong tin cua mot sinh vien can them vao danh sach
 *      + Output:
 *          - bool: true neu them thanh cong, nguoc lai false
 */
bool addNodeToTailList(List &list, Node *newNode)
{
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = newNode;
    }
    else
    {
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
    return newNode->sv.maSV == list.pTail->sv.maSV;
}

/**
 * Cau 2: In danh sach sinh vien
 *      + Input:
 *          - List list: list danh sach sinh vien can them
 *      + Output:
 *          - void
 */
void printList(List list)
{
    Node *n = list.pHead;
    while (n != NULL)
    {
        cout << "---------------------------------------\n";
        cout << "\t MaSV: " << n->sv.maSV << endl;
        cout << "\t Ho Ten: " << n->sv.hoTen << endl;
        cout << "\t DiemMH: " << n->sv.diemMH << endl;
        cout << "---------------------------------------\n";
        n = n->pNext;
    }
}

/**
 * Cau 3: Tim SV theo ma SV
 *      + Input:
 *          - List list: list danh sach sinh vien can them
 *      + Output:
 *          - Node: dia chi vung nho cua sinh vien can tim
 */
Node *findSV(List list, int maSV)
{
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.maSV == maSV)
        {
            return n;
        }
    }
    return NULL;
}

/**
 * Cau 4: Viet am dem Sv co diem mon hoc duoi trung binh
 *      + Input:
 *          - List list: list danh sach sinh vien can them
 *      + Output:
 *          - int: so sinh vien co diem trung binh trong danh sach.
 */
int demSVCoDiemDuoiTrungBinh(List list)
{
    int countSV = 0;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.diemMH < 5)
        {
            countSV += 1;
        }
    }
    return countSV;
}

/**
 * Cau 5: Viet ham tinh diem trung binh cho ca lop
 *      + Input:
 *          - List list: list danh sach sinh vien can them
 *      + Output:
 *          - float: diem trung binh cua ca lop
 */
float tinhDiemTrungBinhCaLop(List list)
{
    int numberOfSv = 0;
    float sumDiemTrungBinh = 0.0;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        numberOfSv += 1;
        sumDiemTrungBinh += n->sv.diemMH;
    }
    return sumDiemTrungBinh / numberOfSv;
}

/**
 * Cau 6: Viet ham tim ma SV dau tien co ma diem mon hoc lon nhat
 *      + Input:
 *          - List list: list danh sach sinh vien can them
 *          - int &maSV: ma sinh vien dau tien co diem MH cao nhat
 *      + Output:
 *          - void
 */
void timMaSVDauTienCoDTBLonNhat(List list, int &maSV)
{
    float maxDiemMH = list.pHead->sv.diemMH;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.diemMH > maxDiemMH)
        {
            maxDiemMH = n->sv.diemMH;
        }
    }
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.diemMH == maxDiemMH)
        {
            maSV = n->sv.maSV;
            return;
        }
    }
}

/**
 * Cau 7: Function tra ve ca ma SV co diem mon hoc tren 8
 *      + Input:
 *          - List list: list danh sach sinh vien can them
 *          - int dsMaSV[]: danh sach ma sinh vien co diem trung binh tren 8
 *          - int &size: kich thuoc cua array dsMaSV
 *      + Output:
 *          - void
 */
#define MAX 100;
void timCacMaSVCoDiemMHTren8(List list, int dsMaSV[], int &size)
{
    size = 0;
    int index = 0;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.diemMH > 8)
        {
            dsMaSV[index] = n->sv.maSV;
            size += 1;
            index += 1;
        }
    }
}

/**
 * Cau 8: Viet ham cap nhat diem mon hoc theo ma Sinh Vien
 *      + Input:
 *          - List &list: list danh sach sinh vien can them
 *          - int maSV: ma sinh vien can cap nhat diem
 *          - float diemMH: diem mon hoc se cap nhat cho sinh vien
 *      + Output:
 *          - bool: return true neu cap nhat thanh cong! Nguoc lai return false.
 */
bool capNhatDiemMHTheoMaSV(List &list, int maSV, float diemMH)
{
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.maSV == maSV)
        {
            n->sv.diemMH = diemMH;
            return true;
        }
    }
    cout << "Khong tim thay sinh vien trong danh sach! \n";
    return false;
}

/**
 * Cau 9: Viet ham sao chep cac sinh vien sang mot danh sach moi
 *      + Input:
 *          - List oldList: nguon - danh sach sinh vien cu
 *          - List &newList: dich - danh sach sinh vien moi
 *      + Output:
 *          - void
 */
void copyList(List oldList, List &newList)
{
    for (Node *n = oldList.pHead; n != NULL; n = n->pNext)
    {
        addNodeToTailList(newList, n);
    }
}

SV *initSV(int maSV, string hoTen, float diemMH)
{
    SV *sv = new SV;
    sv->maSV = maSV;
    sv->hoTen = hoTen;
    sv->diemMH = diemMH;
    return sv;
}

int main(int argc, char const *argv[])
{
    /**
     * Cau 10: Tao 6 SV vao danh sach
     */
    List list;
    initList(list);

    cout << "\n============== Cau 1 ==============\n";
    cout << "Them danh sach sinh vien vao danh sach\n";
    addNodeToTailList(list, initNode(initSV(123, "Nguyen A", 8.8)));
    addNodeToTailList(list, initNode(initSV(124, "Nguyen B", 9.7)));
    addNodeToTailList(list, initNode(initSV(125, "Nguyen C", 2.9)));
    addNodeToTailList(list, initNode(initSV(126, "Nguyen D", 9.7)));
    addNodeToTailList(list, initNode(initSV(127, "Nguyen E", 4.8)));
    addNodeToTailList(list, initNode(initSV(128, "Nguyen F", 7.5)));

    cout << "\n============== Cau 2 ==============\n";
    cout << "Danh sach sinh vien: \n";
    printList(list);

    cout << "\n============== Cau 3 ==============\n";
    int maSVCanTim = 129;
    cout << "Tim sinh vien co trong danh sach : \n";
    Node *node = findSV(list, maSVCanTim);
    if (node != NULL)
    {
        cout << "Tim thay sinh vien trong danh sach!";
    } else {
        cout << "Khong tim thay sinh vien co ma sv: " << maSVCanTim << " trong danh sach!\n";
    }

    cout << "\n============== Cau 4 ==============\n";
    int soSVDuoiTB = demSVCoDiemDuoiTrungBinh(list);
    cout << "So sinh vien duoi diem trung binh = " << soSVDuoiTB << endl;

    cout << "\n============== Cau 5 ==============\n";
    float diemTb = tinhDiemTrungBinhCaLop(list);
    cout << "Diem trung binh ca lop = " << diemTb << endl;

    cout << "\n============== Cau 6 ==============\n";
    int kqMaSV;
    timMaSVDauTienCoDTBLonNhat(list, kqMaSV);
    cout << "Ma sinh vien dau tien co diem MH lon nhat: " << kqMaSV << endl;

    cout << "\n============== Cau 7 ==============\n";
    int size = MAX;
    int maSV[size];
    timCacMaSVCoDiemMHTren8(list, maSV, size);
    cout << "Danh sach ma sinh vien co diem MH tren 8: ";
    for (int i = 0; i < size; i++)
    {
        cout << maSV[i] << " ";
    }
    cout << "\n";

    cout << "\n============== Cau 8 ==============\n";
    bool result = capNhatDiemMHTheoMaSV(list, 123, 10);
    if (result)
    {
        cout << "Cap nhat thanh cong!\n";
    } else {
        cout << "Cap nhat that bai!\n";
    }
    // printList(list);

    cout << "\n============== Cau 9 ==============\n";
    List newList;
    initList(newList);
    copyList(list, newList);
    cout << "List sau khi copy: " << endl;
    printList(newList);

    return 0;
}
