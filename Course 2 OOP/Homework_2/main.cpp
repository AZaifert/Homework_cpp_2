#include <iostream>
#include "Names.h"
// Enum and defines
using namespace std;
#define MAX_NAME_SIZE 20
enum menu_options
{
    PRINT_ALL = 1,
    ADD,
    REMOVE,
    ASSIGN,
    IS_EQUAL,
    IS_CONTAIN,
    IS_CONTAINED,
    INTERSECTION,
    BELONG,
    TOTAL_SIZE,
    QUIT
};
// Function prototypes
void PrintAll(const Names* groups, int numGroups);
void Add(Names* groups, int numGroups);
void Remove(Names* groups, int numGroups);
void Assign(Names* groups, int numGroups);
void IsEqual(const Names* groups, int numGroups);
void IsContain(const Names* groups, int numGroups);
void IsContained(const Names* groups, int numGroups);
void Intersection(Names* groups, int numGroups);
void Belong(const Names* groups, int numGroups);
void TotalSize(const Names* groups, int numGroups);

int main() {
    int numGroups;
    cout << "Enter number of groups: ";
    cin >> numGroups;

    Names* groups = new Names[numGroups];
    menu_options choice;

    do {
        cout << "\n1.Print all\n2.Add\n3.Remove\n4.Assign\n5.Is equal\n6.Is contain\n7.Is contained\n8.Intersection\n9.Belong\n10.Total size\n11.Quit\nEnter choice: ";
        int input;
        cin >> input;
        choice = static_cast<menu_options>(input);

        switch (choice) {
            case PRINT_ALL:
                PrintAll(groups, numGroups);
                break;
            case ADD:
                Add(groups, numGroups);
                break;
            case REMOVE:
                Remove(groups, numGroups);
                break;
            case ASSIGN:
                Assign(groups, numGroups);
                break;
            case IS_EQUAL:
                IsEqual(groups, numGroups);
                break;
            case IS_CONTAIN:
                IsContain(groups, numGroups);
                break;
            case IS_CONTAINED:
                IsContained(groups, numGroups);
                break;
            case INTERSECTION:
                Intersection(groups, numGroups);
                break;
            case BELONG:
                Belong(groups, numGroups);
                break;
            case TOTAL_SIZE:
                TotalSize(groups, numGroups);
                break;
            case QUIT:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != QUIT);

    delete[] groups;
    return 0;
}

// Function Definitions
void PrintAll(const Names* groups, int numGroups) {
    for (int i = 0; i < numGroups; ++i) {
        cout << "Group " << i << ": " << groups[i] << endl;
    }
}

void Add(Names* groups, int numGroups) {
    int groupIndex;
    char name[MAX_NAME_SIZE];
    cout << "Enter group number: ";
    cin >> groupIndex;
    if (groupIndex < 0 || groupIndex >= numGroups) {
        cout << "Invalid group number!" << endl;
        return;
    }
    cout << "Enter name: ";
    cin >> name;
    groups[groupIndex] += name;
}

void Remove(Names* groups, int numGroups) {
    int groupIndex;
    char name[MAX_NAME_SIZE];
    cout << "Enter group number: ";
    cin >> groupIndex;
    if (groupIndex < 0 || groupIndex >= numGroups) {
        cout << "Invalid group number!" << endl;
        return;
    }
    cout << "Enter name: ";
    cin >> name;
    groups[groupIndex] -= name;
}

void Assign(Names* groups, int numGroups) {
    int sourceIndex, destinationIndex;
    cout << "Enter source group number: ";
    cin >> sourceIndex;
    cout << "Enter destination group number: ";
    cin >> destinationIndex;
    if (sourceIndex < 0 || sourceIndex >= numGroups || destinationIndex < 0 || destinationIndex >= numGroups) {
        cout << "Invalid group number!" << endl;
        return;
    }
    groups[destinationIndex] = groups[sourceIndex];
}

void IsEqual(const Names* groups, int numGroups) {
    int group1, group2;
    cout << "Enter two group numbers to compare: ";
    cin >> group1 >> group2;

    if (group1 < 0 || group1 >= numGroups || group2 < 0 || group2 >= numGroups) {
        cout << "Invalid group numbers!" << endl;
        return;
    }

    if (groups[group1] == groups[group2]) {
        cout << "Group " << group1 << " is equal to Group " << group2 << "." << endl;
    } else {
        cout << "Group " << group1 << " is not equal to Group " << group2 << "." << endl;
    }
}

void IsContain(const Names* groups, int numGroups) {
    int group1, group2;
    cout << "Enter two group numbers to check containment: ";
    cin >> group1 >> group2;
    if (group1 < 0 || group1 >= numGroups || group2 < 0 || group2 >= numGroups) {
        cout << "Invalid group numbers!" << endl;
        return;
    }

    bool isContained = true;
    for (int i = 0; i < groups[group2].getsSize(); ++i) {
        if (!groups[group1].contains(groups[group2].getName(i))) {
            isContained = false;
            break;
        }
    }

    if (isContained) {
        cout << "Group " << group1 << " contains Group " << group2 << "." << endl;
    } else {
        cout << "Group " << group1 << " does not contain Group " << group2 << "." << endl;
    }
}

void IsContained(const Names* groups, int numGroups) {
    int group1, group2;
    cout << "Enter left group: ";
    cin >> group1;
    cout << "Enter right group: ";
    cin >> group2;
    if (group1 < 0 || group1 >= numGroups || group2 < 0 || group2 >= numGroups) {
        cout << "Invalid group numbers!" << endl;
        return;
    }

    bool isContained = true;
    for (int i = 0; i < groups[group1].getsSize(); ++i) {
        if (!groups[group2].contains(groups[group1].getName(i))) {
            isContained = false;
            break;
        }
    }

    if (isContained) {
        cout << "Group " << group1 << "  is contained in Group " << group2 << "." << endl;
    } else {
        cout << "Group " << group1 << "  is not contained in Group " << group2 << "." << endl;
    }
}

void Intersection(Names* groups, int numGroups) {
    int group1, group2, resultGroup;
    cout << "Enter two source groups: ";
    cin >> group1 >> group2;
    cout << "Enter destination group: ";
    cin >> resultGroup;
    if (group1 < 0 || group1 >= numGroups || group2 < 0 || group2 >= numGroups || resultGroup < 0 || resultGroup >= numGroups) {
        cout << "Invalid group numbers!" << endl;
        return;
    }
    groups[resultGroup] = groups[group1] * groups[group2];
}

void Belong(const Names* groups, int numGroups) {
    char name[MAX_NAME_SIZE];
    cout << "Enter name to check its belonging groups: ";
    cin >> name;
    cout << "Groups containing " << name << ": ";
    for (int i = 0; i < numGroups; ++i) {
        if (groups[i].contains(name)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void TotalSize(const Names* groups, int numGroups) {
    int totalSize = 0;
    for (int i = 0; i < numGroups; ++i) {
        totalSize += groups[i].getsSize();
    }
    cout << "Total size of all groups: " << totalSize << endl;
}