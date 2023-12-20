/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Buoi 2: Linked List
 * Homework: Use Linkedin List to build project about student management;
 */

#include <iostream>
#include <string>
using namespace std;

// 1. Build Student data structure.
struct Student
{
    string studentId;
    string fullName;
    double avgScore;
    string rank;
    bool gender; // 1 : Male and 0: Female
};

// 2. Build node and list to contain student data.
struct Node
{
    Student student;
    Node *pNext;
};
struct List
{
    Node *pHead;
    Node *pTail;
};

void initStudentList(List &studentList)
{
    studentList.pHead = NULL;
    studentList.pTail = NULL;
}

Node *initNode(Student *student)
{
    Node *p = new Node;
    p->student = *(student);
    p->pNext = NULL;
    return p;
}

void addStudentToTailOfList(List &studentList, Node *node)
{
    if (studentList.pHead == NULL)
    {
        studentList.pHead = node;
        studentList.pTail = node;
        node->pNext = NULL;
    }
    else
    {
        studentList.pTail->pNext = node;
        studentList.pTail = node;
        node->pNext = NULL;
    }
}

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
        studentList.pHead = node;
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
        student->rank = "Medium";
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
    cout << "}\n---------------" << endl;
}

void printStudentList(List studentList)
{
    for (Node *n = studentList.pHead; n != NULL; n = n->pNext)
    {
        printOneStudent(n);
    }
}

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
    cout << "================= 3. Init list =================" << endl;
    List studentList;
    initStudentList(studentList);

    cout << "\n\n================= 4. Add student to head of list =================" << endl;
    Node *studentNode1 = new Node;
    studentNode1->student.studentId = "222";
    studentNode1->student.fullName = "Hieu Bui Van";
    studentNode1->student.avgScore = 8.0;
    studentNode1->student.rank = "Good";
    studentNode1->student.gender = true;
    addStudentToHeadOfList(studentList, studentNode1);

    cout << "\n\n================= 6. Init student list =================" << endl;
    initStudentToList(studentList, 10);

    cout << "\n\n================= 5. Add student to end of list =================" << endl;
    Node *studentNode2 = new Node;
    studentNode2->student.studentId = "555";
    studentNode2->student.fullName = "Le An";
    studentNode2->student.avgScore = 9.0;
    studentNode2->student.rank = "Good";
    studentNode2->student.gender = false;
    addStudentToTailOfList(studentList, studentNode2);

    cout << "\n\n================= 7. Print student list =================" << endl;
    printStudentList(studentList);

    cout << "\n\n================= 8. Find highest avgScore =================" << endl;
    cout << "Highest average score in student list = " << getBiggestOrLowestAvgScore(studentList) << endl;

    cout << "\n\n================= 9. Find student by student ID =================" << endl;
    findStudentByStudentId(studentList, "2222");

    cout << "\n\n================= 10. Find students with highest average score =================" << endl;
    findStudentsHaveBiggestOrLowestAvgScore(studentList);

    cout << "\n\n================= 11. Find students with lowest average score =================" << endl;
    findStudentsHaveBiggestOrLowestAvgScore(studentList, false);

    return 0;
}
