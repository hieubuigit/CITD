/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Bai tap ve nha buoi 1: con tro va cap phat dong
 *      Bai 3: Use Doubly Linkedin List to build project about Student Management;
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * 1. Build Student data structure.
 */
struct Student
{
    string studentId;
    string fullName;
    double avgScore;
    string rank;
    bool gender; // 1 : Male and 0: Female
};

/**
 * 2. Build node and list to contain student data.
 */
struct Node
{
    Student student;
    Node *pPre;
    Node *pNext;
};
struct List
{
    Node *pHead;
    Node *pTail;
};

/**
 * 3. Init node and doubly linked list
 */
void initStudentList(List &studentList)
{
    studentList.pHead = NULL;
    studentList.pTail = NULL;
}
Node *initNode(Student *student)
{
    Node *p = new Node;
    p->student = *(student);
    p->pPre = NULL;
    p->pNext = NULL;
    return p;
}

/**
 * 5. Add student into tail of list
 */
void addStudentToTailOfList(List &studentList, Node *node)
{
    if (studentList.pHead == NULL)
    {
        studentList.pHead = node;
        studentList.pTail = node;
    }
    else
    {
        studentList.pTail->pNext = node;
        node->pPre = studentList.pTail;
        studentList.pTail = node;
    }
}

/**
 * 4. Add student into head of list
 */
void addStudentToHeadOfList(List &studentList, Node *node)
{
    if (studentList.pTail == NULL)
    {
        studentList.pHead = node;
        studentList.pTail = node;
    }
    else
    {
        node->pNext = studentList.pHead;
        studentList.pHead->pPre = node;
        studentList.pHead = node;
    }
}

/**
 * 6. Init data for student list
 */
string getRankByAvgScore(double avgScore)
{
    if (avgScore > 0 && avgScore < 5)
    {
        return "Yeu";
    }
    else if (avgScore >= 5 && avgScore < 6.5)
    {
        return "Trung Binh";
    }
    else if (avgScore >= 6.5 && avgScore < 8)
    {
        return "Kha";
    }
    else if (avgScore >= 8 && avgScore < 9)
    {
        return "Gioi";
    }
    else if (avgScore >= 9 && avgScore <= 10)
    {
        return "Xuat sac";
    }
    else
    {
        return "Khong ro";
    }
}
void initStudentToList(List &studentList, int studentNumber)
{
    for (int i = 0; i < studentNumber; i++)
    {
        Student *student = new Student;
        student->studentId = to_string(123 + i);
        student->fullName = "Nguyen Van " + to_string(65 + i);
        student->avgScore = 0.5 + i;
        student->rank = getRankByAvgScore(0.5 + i);
        student->gender = 0;
        Node *p = initNode({student});
        addStudentToTailOfList(studentList, p);
    }
}

void printOneStudent(Node *n)
{
    cout << "Student {\n"
         << endl;
    cout << "\t Student Id: " << n->student.studentId << endl;
    cout << "\t Full Name: " << n->student.fullName << endl;
    cout << "\t Average Score: " << n->student.avgScore << endl;
    cout << "\t Rank: " << n->student.rank << endl;
    cout << "\t Gender: " << (n->student.gender == false ? "Female" : "Male") << endl;
    cout << "}\n---------------------------------------------" << endl;
}

/**
 * 7. Print student list
 */
void printStudentList(List studentList, bool isReverse = false)
{
    if (isReverse)
    {
        for (Node *n = studentList.pTail; n != NULL; n = n->pPre)
        {
            printOneStudent(n);
        }
    }
    else
    {
        for (Node *n = studentList.pHead; n != NULL; n = n->pNext)
        {
            printOneStudent(n);
        }
    }
}

/**
 * 8. Get biggest or lowest average score
 */
double getBiggestOrLowestAvgScore(List studentList, bool isBiggest = true)
{
    double avgScore = studentList.pHead->student.avgScore;
    for (Node *n = studentList.pHead; n != NULL; n = n->pNext)
    {
        if (isBiggest)
        {
            if (n->student.avgScore > avgScore)
            {
                avgScore = n->student.avgScore;
            }
        }
        else
        {
            if (n->student.avgScore < avgScore)
            {
                avgScore = n->student.avgScore;
            }
        }
    }
    return avgScore;
}

/**
 * 9. Find student by student ID
 */
void findStudentByStudentId(List studentList, string studentId)
{
    for (Node *n = studentList.pHead; n != NULL; n = n->pNext)
    {
        if (n->student.studentId == studentId)
        {
            printOneStudent(n);
            return;
        }
        else
        {
            cout << "Don't have any student by " + studentId << endl;
            break;
        }
    }
}

/**
 * 10 + 11 Find and print student list have biggest average score.
 */
void findStudentsHaveBiggestOrLowestAvgScore(List studentList, bool isBiggest = true)
{
    double avgScore = getBiggestOrLowestAvgScore(studentList, isBiggest);
    for (Node *n = studentList.pHead; n != NULL; n = n->pNext)
    {
        if (n->student.avgScore == avgScore)
        {
            printOneStudent(n);
        }
    }
}

int main(int argc, char const *argv[])
{
    // 1 + 2 + 3: build student list
    List studentList;
    initStudentList(studentList);



    // 6. Auto add student to list
    initStudentToList(studentList, 10);



    // 4. Add a student to head of student list
    Student *student1 = new Student;
    student1->studentId = "000";
    student1->fullName = "Nguyen Van 000";
    student1->gender = 0;
    student1->avgScore = 10.0;
    student1->rank = getRankByAvgScore(9.0);
    Node *node1 = initNode(student1);
    addStudentToHeadOfList(studentList, node1);



    // 5. Add a student to tail of student list
    Student *student2 = new Student;
    student2->studentId = "999";
    student2->fullName = "Nguyen Van 999";
    student2->gender = 1;
    student2->avgScore = 10.0;
    student2->rank = getRankByAvgScore(10.0);
    Node *node2 = initNode(student2);
    addStudentToTailOfList(studentList, node2);



    // 7. Print student list without rank
    cout << "==================== 7. Student List ==================" << endl;
    printStudentList(studentList);
    cout << "====================================================\n\n\n\n\n";



    // 8. Get biggest or lowest average score
    cout << "==================== 8. Find highest average score of list ==================" << endl;
    cout << "Highest AVG Score = " << getBiggestOrLowestAvgScore(studentList) << endl;
    cout << "====================================================\n\n\n\n\n";



    // 9. Find Student with student ID
    cout << "==================== 9. Find Student with student Id  ==================" << endl;
    findStudentByStudentId(studentList, "000");
    findStudentByStudentId(studentList, "1111111");
    cout << "====================================================\n\n\n\n\n";



    // 10. Find students have the highest avg score in student list
    cout << "==================== 10. Find students have the highest avg score in student list ==================" << endl;
    findStudentsHaveBiggestOrLowestAvgScore(studentList);
    cout << "====================================================\n\n\n\n\n";



    // 11. Find students have the lowest avg score in student list
    cout << "==================== 11. Find students have the lowest avg score in student list ==================" << endl;
    findStudentsHaveBiggestOrLowestAvgScore(studentList, false);
    cout << "====================================================\n\n\n\n\n";

    return 0;
}
