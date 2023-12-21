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

Node *initNode(SV *sv)
{
    Node *newNode = new Node;
    newNode->sv.maSV = sv->maSV;
    newNode->sv.hoTen = sv->hoTen;
    newNode->sv.diemMH = sv->diemMH;
    return newNode;
}

void initList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

/**
 * Cau 1: Chen node sinh vien vao cuoi danh sach
 *      + Input:
 *      + Output:
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
 *      + Output:
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
 */
void timMaSVDauTienCoDTBLonNhat(List &list, string &maSV)
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
 */
#define MAX 1000;
void timCacMaSVCoDiemMHTren8(List list, string dsMaSV[], int size)
{
    size = 0;
    int index = 0;
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.diemMH > 8)
        {
            size += 1;
            index += 1;
            dsMaSV[index] = n->sv.maSV;
        }
    }
}

/**
 * Cau 8: Viet ham cap nhat diem mon hoc theo ma Sinh Vien
 */
bool capNhatDiemMHTheoMaSV(List &list, int maSV, float diemMH)
{
    for (Node *n = list.pHead; n != NULL; n = n->pNext)
    {
        if (n->sv.maSV == maSV)
        {
            n->sv.diemMH = diemMH;
            return false;
        }
    }
    cout << "Khong tim thay sinh vien trong danh sach! \n";
    return false;
}

/**
 * Cau 9: Viet ham sao chep cac sinh vien sang mot danh sach moi
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

    cout << "-------------- Cau 1 --------------\n";
    cout << "Them danh sach sinh vien vao danh sach\n";
    addNodeToTailList(list, initNode(initSV(123, "Nguyen A", 8.8)));
    addNodeToTailList(list, initNode(initSV(124, "Nguyen B", 9.7)));
    addNodeToTailList(list, initNode(initSV(125, "Nguyen C", 2.9)));
    addNodeToTailList(list, initNode(initSV(126, "Nguyen D", 9.7)));
    addNodeToTailList(list, initNode(initSV(127, "Nguyen E", 4.8)));
    addNodeToTailList(list, initNode(initSV(128, "Nguyen F", 7.5)));

    cout << "-------------- Cau 2 --------------\n";
    cout << "Danh sach sinh vien: \n";
    printList(list);

    cout << "-------------- Cau 3 --------------\n";
    int maSVCanTim = 123;
    cout << "Tim sinh vien co trong danh sach : \n";
    Node *node = findSV(list, maSVCanTim);
    if (node != NULL)
    {
        cout << "Tim thay sinh vien trong danh sach!";
    }

    cout << "-------------- Cau 4 --------------\n";
    int soSVDuoiTB = demSVCoDiemDuoiTrungBinh(list);
    cout << "So sinh vien duoi diem trung binh " << soSVDuoiTB << endl;

    cout << "-------------- Cau 5 --------------\n";
    float diemTb = tinhDiemTrungBinhCaLop(list);
    cout << "Sinh vien dau tien co diem mon hoc lon nhat: " << diemTb << endl;

    cout << "-------------- Cau 6 --------------\n";
    string kqMaSV = "";
    timMaSVDauTienCoDTBLonNhat(list, kqMaSV);
    cout << "Ma sinh vien co diem MH lon nhat: " << kqMaSV << endl;

    cout << "-------------- Cau 7 --------------\n";
    int size = MAX;
    string maSV[size];
    timCacMaSVCoDiemMHTren8(list, maSV, size);
    cout << "Danh sach ma sinh vien co diem MH tren 8: ";
    for (int i = 0; i < size; i++)
    {
        cout << maSV[i] << " \n";
    }

    cout << "-------------- Cau 8 --------------\n";
    bool result = capNhatDiemMHTheoMaSV(list, 123, 10);
    if (result )
    {
        cout << "Cap nhat thanh cong!";
    } else {
        cout << "Cap nhat that bai";
    }


    cout << "-------------- Cau 9 --------------\n";
    List newList;
    initList(newList);
    cout << "List sau khi copy: " << endl;
    printList(newList);


    return 0;
}
