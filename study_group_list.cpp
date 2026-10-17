/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [Date]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Define a Node with string groupCode, int meetingRoom, and Node *next.
    struct Node
    {
        string groupCode; 
        int meetingRoom;  
        Node *next;       
    };
    // TODO (Part C): Declare a Node *head data member for the first node address.
    Node *head;
    // TODO (Part C): Declare an int groupCount data member for the number of stored groups.
    int groupCount;

public:
    // TODO (Part C): Write a constructor that creates an empty list and sets groupCount to zero.
    StudyGroupList()
    {
        head = nullptr;
        groupCount = 0;
    }

    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write addGroup. It receives a group code and room number, adds one node at the end, and updates groupCount.
    int addGroup(const string& newGroupCode, int newMeetingRoom)
    {
        Node *newNode = new Node;
        newNode->groupCode = newGroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }

        groupCount++;
        return groupCount;
    }
    // TODO (Part D): Write displayGroups as a const member function.
    void displayGroups() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << "Group Code: " << currentNode->groupCode
                 << ", Meeting Room: " << currentNode->meetingRoom << endl;
            currentNode = currentNode->next;
        }
    }
    // TODO (Part D): Write size as a const member function that returns groupCount.
    int size() const
    {
        return groupCount;
    }

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
    bool containsGroup(const string& searchGroupCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->groupCode == searchGroupCode)
            {
                return true;
            }
            currentNode = currentNode->next;
        }

        return false;
    }
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Create a StudyGroupList object.
    StudyGroupList studyGroups;

    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    studyGroups.addGroup("SG-105", 105);
    studyGroups.addGroup("SG-230", 230);
    studyGroups.addGroup("SG-303", 303);

    // TODO (Part E): Display every stored group and print the result of size().
    studyGroups.displayGroups();
    cout << "Number of groups: " << studyGroups.size() << endl;
    
    // TODO (Part E): Search for one stored group code and one missing group code; print both bool results.
    cout << "Contains SG-230: " << studyGroups.containsGroup("SG-230") << endl;
    cout << "Contains SG-999: " << studyGroups.containsGroup("SG-999") << endl;

    return 0;
}