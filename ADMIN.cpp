#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

class AdminPortal
{
private:
    // TaskMonitor For Students
    vector<string> students;
    vector<int> totalPresent;
    vector<int> totalAbsent;
    vector<int> totalAssignments;
    vector<int> submittedAssignments;

    // Budget For Students
    vector<string> budgetStudents;
    vector<double> totalAmount;
    vector<double> payment;
    vector<double> waiver;
    vector<double> due;
    vector<string> paymentStatus;

public:
    void addTaskMonitorData()
    {
        string id;

        int present, absent, totalAssgn, submittedAssgn;

        cout << "Enter details for Student : " << endl;
        cout << endl;
        cout << "ID : ";
        cin >> id;
        cout << "Total Present : ";
        cin >> present;
        cout << "Total Absent : ";
        cin >> absent;
        cout << "Total Assignments : ";
        cin >> totalAssgn;
        cout << "Submitted Assignments : ";
        cin >> submittedAssgn;

        students.push_back(id);                                //push_back is used to add element in the end of the vector. It automatically increases the size of the vector when needed............
        totalPresent.push_back(present);
        totalAbsent.push_back(absent);
        totalAssignments.push_back(totalAssgn);
        submittedAssignments.push_back(submittedAssgn);

        cout << "TaskMonitor data added for Student : " << id << endl;
    }
    void updateTaskMonitorData()
    {
        string id;

        int present, absent, totalAssgn, submittedAssgn, pendingAssgn;

        cout << "Enter updated details for Student : " << endl;
        cout << endl;
        cout << "ID : ";
        cin >> id;
        cout << "Total Present : ";
        cin >> present;
        cout << "Total Absent : ";
        cin >> absent;
        cout << "Total Assignments : ";
        cin >> totalAssgn;
        cout << "Submitted Assignments : ";
        cin >> submittedAssgn;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == id)
            {
                totalPresent[i] = present;
                totalAbsent[i] = absent;
                totalAssignments[i] = totalAssgn;
                submittedAssignments[i] = submittedAssgn;

                cout << "TaskMonitor data updated for Student : " << id << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    void calculateAttendancePercentage(string id)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == id)
            {
                int totalClasses = totalPresent[i] + totalAbsent[i];
                if (totalClasses == 0)
                {
                    cout << "No classes attended or missed for : " << id << endl;
                    return;
                }
                double percentage = (double)totalPresent[i] / totalClasses * 100;
                cout << "Attendance percentage for " << id << ": " << percentage << "%" << endl;
                if (percentage >= 75)
                {
                    cout << id << " is eligible for the exam." << endl;
                }
                else
                {
                    cout << id << " is not eligible for the exam." << endl;
                }
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
    void calculatePendingAssignments(string id)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == id)
            {
                int pending = totalAssignments[i] - submittedAssignments[i];
                cout << "Pending assignments for " << id << ": " << pending << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

    // Budget System Functions
    void addBudgetData()
    {
        string id;

        double totalAmt, pay, waiv;

        cout << "Enter details for Budget : " << endl;
        cout << endl;
        cout << "ID : ";
        cin >> id;
        cout << "Total Amount : ";
        cin >> totalAmt;
        cout << "Waiver : ";
        cin >> waiv;
        cout << "Payment : ";
        cin >> pay;

        budgetStudents.push_back(id);
        totalAmount.push_back(totalAmt);
        waiver.push_back(waiv);
        payment.push_back(pay);

        // Calculate Due
        double calculatedDue = totalAmt - pay - waiv;
        due.push_back(calculatedDue);

        // Determine Payment Status
        if (fabs(calculatedDue) < std::numeric_limits<double>::epsilon()) //  Gives the smallest difference between two numbers represented as double. It's used to avoid problems when comparing floating-point numbersmachine epsilon........
        {
            paymentStatus.push_back("Paid");
        }
        else
        {
            paymentStatus.push_back("Due");
        }
        cout << "Budget data added for Student : " << id << endl;
    }
    void updateBudgetData(string id)
    {
        double totalAmt, pay, waiv;

        cout << "Enter updated budget details for Student: " << endl;
        cout << "Total Amount: ";
        cin >> totalAmt;
        cout << "Waiver: ";
        cin >> waiv;
        cout << "Payment: ";
        cin >> pay;

        for (int i = 0; i < budgetStudents.size(); i++)
        {
            if (budgetStudents[i] == id)
            {
                totalAmount[i] = totalAmt;
                payment[i] = pay;
                waiver[i] = waiv;

                // Calculate Due
                double calculatedDue = totalAmt - pay - waiv;
                due[i] = calculatedDue;

                // Determine Payment Status
                if (fabs(calculatedDue) < std::numeric_limits<double>::epsilon())
                    paymentStatus.push_back("Paid");
            }
            else
            {
                paymentStatus.push_back("Due");
            }
            cout << "Budget data updated for Student: " << id << endl;
            return;
        }
        cout << "Student not found!" << endl;
    }

    // File Handling Functions
    void saveTaskMonitorData()
    {
        ofstream outFile("taskmonitor.txt");
        for (int i = 0; i < students.size(); i++)
        {
            outFile << students[i] << " " << totalPresent[i] << " " << totalAbsent[i] << " "
                    << totalAssignments[i] << " " << submittedAssignments[i] << endl;
        }
        outFile.close();
        cout << "TaskMonitor data saved to taskmonitor.txt" << endl;
    }
    void loadTaskMonitorData()
    {
        ifstream inFile("taskmonitor.txt");
        if (!inFile)
        {
            cout << "No TaskMonitor data found." << endl;
            return;
        }
        string id;

        int present, absent, totalAssgn, submittedAssgn,pendingAssgn;

        while (inFile >> id >> present >> absent >> totalAssgn >> submittedAssgn)
        {
            students.push_back(id);
            totalPresent.push_back(present);
            totalAbsent.push_back(absent);
            totalAssignments.push_back(totalAssgn);
            submittedAssignments.push_back(submittedAssgn);
        }
        inFile.close();
        cout << "TaskMonitor data loaded from taskmonitor.txt" << endl;
    }
    void saveBudgetData()
    {
        ofstream outFile("budget.txt");
        for (int i = 0; i < budgetStudents.size(); i++)
        {
            outFile << budgetStudents[i] << " " << totalAmount[i] << " " << payment[i] << " "
                    << waiver[i] << " " << due[i] << " " << paymentStatus[i] << endl;
        }
        outFile.close();
        cout << "Budget data saved to budget.txt" << endl;
    }
    void loadBudgetData()
    {
        ifstream inFile("budget.txt");
        if (!inFile)
        {
            cout << "No Budget data found." << endl;
            return;
        }
        string id, status;
        double amt, pay, waiv, du;
        while (inFile >> id >> amt >> pay >> waiv >> du >> status)
        {
            budgetStudents.push_back(id);
            totalAmount.push_back(amt);
            payment.push_back(pay);
            waiver.push_back(waiv);
            due.push_back(du);
            paymentStatus.push_back(status);
        }
        inFile.close();
        cout << "Budget data loaded from budget.txt" << endl;
    }

    // Admin Menu
    void adminMenu()
    {
        int choice = 0;

        string id;

        while (true)
        {
            cout << "\n\t\t\t\t\t\t\t                             ----------Admin Portal----------" << endl;
            cout << "\t\t\t\t\t                                                 1. Add Task Monitor Data" << endl;
            cout << "\t\t\t\t\t                                                 2. Update Task Monitor Data" << endl;
            cout << "\t\t\t\t\t                                                 3. Calculate Attendance Percentage" << endl;
            cout << "\t\t\t\t\t                                                 4. Calculate Pending Assignments" << endl;
            cout << "\t\t\t\t\t                                                 5. Add Budget Data" << endl;
            cout << "\t\t\t\t\t                                                 6. Update Budget Data" << endl;
            cout << "\t\t\t\t\t                                                 7. Display Budget Data" << endl;
            cout << "\t\t\t\t\t                                                 8. Save Task Monitor Data" << endl;
            cout << "\t\t\t\t\t                                                 9. Save Budget Data" << endl;
            cout << "\t\t\t\t\t                                                 0. Exit" << endl;
            cout << "\t\t\t\t\t                     Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addTaskMonitorData();
                break;
            case 2:
                updateTaskMonitorData();
                break;
            case 3:
                cout << "Enter student ID: ";
                cin >> id;
                calculateAttendancePercentage(id);
                break;
            case 4:
                cout << "Enter student ID: ";
                cin >> id;
                calculatePendingAssignments(id);
                break;
            case 5:
                addBudgetData();
                break;
            case 6:
                cout << "Enter student ID: ";
                cin >> id;
                updateBudgetData(id);
                break;
            case 7:
                cout << "Enter student ID (or type 'all' to display all students) : ";
                cin >> id;
                if (id == "all")
                {
                    for (int i = 0; i < budgetStudents.size(); i++)
                    {
                        cout <<  "ID : " << budgetStudents[i] << endl;
                        cout <<  "Total Amount : " << totalAmount[i] << endl;
                        cout <<  "Payment : " << payment[i] << endl;
                        cout <<  "Waiver : " << waiver[i] << endl;
                        cout <<  "Due : " << due[i] << endl;
                        cout <<  "Payment Status : " << paymentStatus[i] << endl;
                    }
                }
                else
                {
                    bool found = false;
                    for (int i = 0; i < budgetStudents.size(); i++)
                    {
                        if (budgetStudents[i] == id)
                        {
                            cout <<  "ID : " << budgetStudents[i] << endl;
                            cout <<  "Total Amount : " << totalAmount[i] << endl;
                            cout <<  "Payment : " << payment[i] << endl;
                            cout <<  "Waiver : " << waiver[i] << endl;
                            cout <<  "Due : " << due[i] << endl;
                            cout <<  "Payment Status : " << paymentStatus[i] << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "Student not found!" << endl;
                    }
                }
                break;
            case 8:
                saveTaskMonitorData();
                break;
            case 9:
                saveBudgetData();
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main()
{
    AdminPortal admin;
    admin.adminMenu();
    return 0;
}
