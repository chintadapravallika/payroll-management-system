#include <iostream>
#include <string>
using namespace std;

class employee
{
    int pre_s;
    int bonus;
    int tax;
    
public:
    string name;
    int id;
    int total;
    long long int number;
    string address;
    void input();
    void display();
    void update();
    void remove();
    void payslip()
    {
        cout << "------EMPLOYEE SALARY SLIP--------\n";
        cout << "Employee Present Salary    :-" << pre_s;
        cout << "\nEmployee Bonus  :-" << bonus;
        cout << "\nEmployee Tax :-" << tax;
    }
} e[100],e1;

int i = 0, ch;
string user,pass;
void employee::input()
{
    int temp_id;
    cout << "Enter Employee Id:-  \n ";
    cin >> temp_id;

    for (int j = 0; j < i; j++)
    {
        if (e[j].id == temp_id)
        {
            cout << "This employee ID is already entered. Please enter a unique ID.\n";
            return; 
        }
    }

    id = temp_id;

    cout << "Enter Employee Name          : \n ";
    cin >> name;
    cout << "Enter Employee phone Number  : \n";
    cin >> number;
    cout << "Enter Employee Address       : \n";
    cin >> address;
    cout << "Enter Employee Present Salary: \n";
    cin >> pre_s;
    cout << "Enter Employee Bonus         : \n";
    cin >> bonus;
    cout << "Enter Employee Tax           : \n";
    cin >> tax;
    int s,m;
    s=12*pre_s+bonus;
    m=tax*pre_s/100;
    total=s+m;
    i++; 
}

void employee::display()
{
    
        cout << "------EMPLOYEE DETAILS--------\n";
        cout << "Employee Id              :-" << id;
        cout << "\nEmployee Name          :-" << name;
        cout << "\nEmployee phone Number  :-" << number;
        cout << "\nEmployee Address:      :-" << address;
        cout << "\n total salary per annum:- "<<total;
    
    
}

void menu()
{
    cout << "-------------PAYROLL---------------\n";
    cout << "1. Add Employee Details\n";
    cout << "2. View Employee Details\n";
    cout << "3. Update Employee Details\n";
    cout << "4. Remove Employee Details\n";
    cout << "0. Exit\n";
}

void employee::update()
{
    int up, ch = 1, ch1;
    while (ch != 0)
    {
        cout << "Enter the employee ID to update their payslip: ";
        cin >> up;
        bool id_found = false;

        for (int j = 0; j < i; j++)
        {
            if (up == e[j].id)
            {
                id_found = true;
                cout << "\nThe employee details are:-  \n";
                e[j].display();
                cout << "\n";
                e[j].payslip();
                cout << "\n Enter 1 to update present salary or 0 to stop: ";
                cin >> ch1;
                if (ch1 == 1)
                {
                    cout << "Enter new present salary: ";
                    cin >> e[j].pre_s;
                }
                cout << "\n Enter 1 to update bonus or 0 to stop: ";
                cin >> ch1;
                if (ch1 == 1)
                {
                    cout << "Enter new bonus: ";
                    cin >> e[j].bonus;
                }
                cout << "\n Enter 1 to update tax or 0 to stop: ";
                cin >> ch1;
                if (ch1 == 1)
                {
                    cout << "Enter new tax: ";
                    cin >> e[j].tax;
                }
                int s,m;
                s=12*e[j].pre_s+e[j].bonus;
                m=e[j].tax*e[j].pre_s*12/100;
                e[j].total=s+m;
                cout << "\n-------------SUCCESSFULLY UPDATED----------------\n";
                break;
            }
        }

        if (!id_found)
        {
            cout << "\nPlease enter the correct ID\n";
        }
        else
        {
            cout << "\nDo you want to update another employee's details?";
            cout << "\nPress 1 to update, 0 to stop: ";
            cin >> ch;
        }
    }
}

void employee::remove()
{
    int rem_id;
    cout << "Enter the employee ID to remove: ";
    cin >> rem_id;
    bool id_found = false;

    for (int j = 0; j < i; j++)
    {
        if (e[j].id == rem_id)
        {
            id_found = true;
            for (int k = j; k < i - 1; k++)
            {
                e[k] = e[k + 1]; 
            }
            i--; 
            cout << "Employee with ID " << rem_id << " removed successfully.\n";
            break;
        }
    }

    if (!id_found)
    {
        cout << "Employee with ID " << rem_id << " not found.\n";
    }
}

int main()  
{
  user="Aeries";
  pass="1234";
string n1,n2;
   cout<<"username:";
   cin>>n1;
   cout<<"password:";
   cin>>n2;
if(n1==user&&n2==pass)
{    cout<<"\n-------- LOGIN SUCCESSFULLY---------\n";
    menu();
    cout << "\nEnter your choice: ";
    cin >> ch;
    while (ch != 0)
    {
        switch (ch)
        {
        case 1:
            e[i].input();
            break;
        case 2:
           
           if(i<=0)
           {
                cout<<"\n No List to Display\n";
           }
           else{ 
           for (int j = 0; j < i; j++)
            {
                e[j].display();
                cout << "\n";
            }
           }
            break;
        case 3:
            e1.update(); 
            break;
        case 4:
           e1.remove();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        menu();
        cout << "\nEnter your choice: ";
        cin >> ch;
    }
}
    else{
        cout<<"\n Invalid userid and password!! Try Again!!\n";
        main();
        }
    
    return 0;
}