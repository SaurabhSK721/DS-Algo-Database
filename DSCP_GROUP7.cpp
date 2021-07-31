//S.Y Electrical
// Data Structures and Computer Programming

//DSCP project-Dead Stock Register for Power Systems Laboratory


// Include all the Headers
#include<fstream>
#include<limits>
#include<windows.h>
#include<iostream>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<cstdlib>
#include<conio.h>

using namespace std;

int count =0;
int l=1;

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void load()
{
    int r,q;
    gotoxy(75,25);
    printf("LOADING...");
    gotoxy(79,28);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",177);
    }

}


void login()
{char ch;
    int count;
    string user,pass,u,p;
    system("cls");

    cout<<"Please enter the following details "<<endl;
    cout<<"USERNAME :";
    cin>>user;
    cout<<"PASSWORD :";
  //  cin>>pass;
     ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }

    ifstream input("User.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)

        {
            count=1;
            l=2;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {

        cout<<"Hello  "<<user<<", Password Matched !";
        cin.get();
        cin.get();

    }
    else
    {
        cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        getchar();

    }
}

void registr()
{

    string reguser,regpass,ru,rp;
    system("cls");

    cout<<"Enter the username :"<<endl;
    cin>>reguser;
    cout<<"Enter the password :"<<endl;
    cin>>regpass;

    ofstream reg("User.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");

    cout<<"Registration Sucessful\n";
    getchar();


}

void forgot()
{
    int ch;
    system("cls");

    cout<<"Forgot your password ? We're here for help\n";
    cout<<"1.Search your id by username"<<endl;

    cout<<"2.Return Login Page"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        int count=0;
        string searchuser,su,sp;
        cout<<"\nEnter your Username :";
        cin>>searchuser;

        ifstream searchu("User.txt");
        while(searchu>>su>>sp)
        {
            if(su==searchuser)
            {
                count=1;
            }
        }
        searchu.close();
        if(count==1)
        {
            cout<<"The account is found in the Database!\n";
            cout<<"\nYour password is "<<sp;
            cin.get();
            cin.get();
            system("cls");

        }
        else
        {
            cout<<"\nSorry, Your userID is not found in our database\n";
            cout<<"\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();

        }
        break;
    }

    case 2:
    {
        cin.get();

    }
    default:
        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
        forgot();
    }
}



class equipment
{
private:

    string UID;
    string name;
    string desc;
    int day;
    int mon;
    int year;

    string purc_info;
    int quant;
    int cost;
    string grant;
    bool working;     //If the Equipment is in working condition then returns True else it returns False
    string lab_inc;
    string hod;
    string remark;

public:
    equipment(string UID,string name,string desc, int day,int mon,int year,string purc_info,int quant,int cost,string grant,bool working,string lab_inc,string hod,string remark )
    {
        this ->UID=UID;
        this ->name=name;
        this ->desc=desc;
        this ->day=day;
        this ->mon=mon;
        this ->year=year;
        this ->purc_info=purc_info;
        this ->quant=quant;
        this ->cost=cost;
        this ->grant=grant;
        this ->working=working;
        this ->lab_inc=lab_inc;
        this ->hod=hod;
        this ->remark=remark;
    }

//Now we define Getter functions to take the values of private variables in the class from the user.
    string getUID()
    {
        return UID;
    }
    string getname()
    {
        return name;
    }
    string getdes()
    {
        return desc;
    }

    int getday()
    {
        return day;
    }
    int getmon()
    {
        return mon;
    }
    int getyear()
    {
        return year;
    }
    string getpurc_info()
    {
        return purc_info;
    }
    int getnum()
    {
        return quant;
    }
    int getcost()
    {
        return cost;
    }
    string getgrant()
    {
        return grant;
    }
    bool getstat()
    {
        return working;
    }
    string getlabinc()
    {
        return lab_inc;
    }
    string gethod()
    {
        return hod;
    }
    string getremark()
    {
        return remark;
    }
    void setname(string name)
    {
        this ->name=name;
    }

};

int main()
{

    int i,length;
    int temp1, digits;
    system("cls");


    gotoxy(75,20);


    cout<<"WELCOME TO ELECTRICAL ENGINEERING DEPARTMENT, POWER SYSTEM LABORATORY"<<endl;
    cout<<"*****************************************************************************************************************************************************************************************************************"<<endl;
    getchar();
    system("cls");




    int choice;

    load();
    system("cls");


    while(l==1)
    {
        system("cls");


        cout<<"***********************************************************************"<<endl;;

        cout<<"                      WELCOME TO LOGIN PAGE                           "<<endl;;

        cout<<"********************        MENU        *******************************"<<endl;

        cout<<"1.LOGIN"<<endl;

        cout<<"2.REGISTER"<<endl;

        cout<<"3.FORGOT PASSWORD "<<endl;

        cout<<"Enter your choice :";

        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:
            l++;
            cout<<"Thanks\n";
            break;
        default:
            getchar();
            system("cls");
            cout<<"Please Try again.\n"<<endl;

        }

    }


    vector<equipment> PSLab;

    string UID;
    string name;
    string desc;
    int day;
    int mon;
    int year;
    string purc_info;
    int quant;
    int cost;
    string grant;
    string working;
    bool Working;
    string lab_inc;
    string hod;
    string remark;
    int input;
    string line;

    ostringstream oss;


//Read existing data from file
    ifstream fin; // input stream
    char ch;
    fin.open("database.csv"); // open the file
    // Execute a loop until EOF (End of File)
    while (fin)
    {
        getline(fin, UID, ',');
        if (UID == "\n")
            break;
        if (UID[0] != 'P')
            UID = "P" + UID;
        getline(fin, name, ',');
        getline(fin, desc, ',');
        fin >> day;
        fin >> ch; // take comma as input
        fin >> mon;
        fin >> ch;
        fin >> year;
        fin >> ch;
        getline(fin, purc_info, ',');
        fin >> quant;
        fin >> ch;
        fin >> cost;
        fin >> ch;
        getline(fin, grant, ',');
        fin >> Working;
        fin >> ch;
        getline(fin, lab_inc, ',');
        getline(fin, hod, ',');
        getline(fin, remark);
        PSLab.push_back(equipment(UID,name,desc,day,mon,year,purc_info,quant,cost,grant,Working,lab_inc,hod,remark));
        count++;
        fin >> ch;
    }

    fin.close();
    do

    {
        //gotoxy(1,2);
        cout<<"************************************************************************************************************************************************************************"<<endl;
        cout<<"\n";
        cout<<"                                     WELCOME TO THE HOME PAGE                                        "<<endl;
        cout<<"\n";
        cout<<"************************************************************************************************************************************************************************"<<endl;

        cout << "1. Insert Record" << endl;

        // cout << "2. Delete Record" << endl;

        cout << "2. Display Database" << endl;

        cout << "3. Modify" << endl;

        cout<<"4. Search Record"<<endl;

        cout<<"5. Quit"<<endl;
        cin >> input;

        switch (input)
        {

        case 1:
            count++;
            UID = "PS";
            temp1 = count, digits=0;
            while (temp1 !=0)
            {
                digits ++;
                temp1 = temp1/10;
            }
            if(digits ==1 )
            {
                UID +="00";
            }
            else if(digits ==2)
            {
                UID += "0";
            }
            else if (digits ==4)
            {
                cout<<"The maximum Limit of storage is reached! \n";
                return 0;
            }


            oss << count;
            UID += oss.str();//UID =UID+ to_string(count); //UID +count




            cout << "Enter Name of the Equipment : ";

            getchar();
            getline(cin,name);
            cout << "Enter Description of the Equipment : ";

            getline(cin,desc);

            cout<<"Enter day :";
            cin>>day;
            //VALIDATION FOR DAY
            while(day<=0 || day>31)
            {
                if (cin.fail())   // user entered string value instead of integer
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                cout<<"Invalid day. Enter again\n";
                cin>>day;
            }

            //VALIDATION FOR MONTH
            cout<<"Enter month: ";
            cin >> mon;
            while(mon <=0 || mon>12)
            {
                if (cin.fail())   // user entered string value instead of integer
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                cout<<"Invalid month. Enter again\n";
                cin>>mon;
            }

            //VALIDATION FOR YEAR
            cout<<"Enter year: ";
            cin >> year;
            while(year<=0)
            {
                if (cin.fail())   // user entered string value instead of integer
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                cout<<"Invalid year. Enter again\n";
                cin>>year;
            }

            cout << "Enter purchase information : ";

            getchar();
            getline(cin,purc_info);



            cout << "Enter quantity : ";
            cin>>quant;

            //VALIDATION
            while(quant < 0 || cin.fail())
            {
                if (cin.fail())   // user entered string value instead of integer
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid Quantity\n";
                }
                else
                    cout<<"Quantity cannot be negative.Enter again.\n";
                cin>>quant;

            }

            //VALIDATION
            cout<<"Enter cost : ";
            cin >> cost;
            while(cost <0 || cin.fail())
            {

                if (cin.fail())   // user entered string value instead of integer
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Invalid Cost\n";
                }
                else
                    cout<<"Cost cannot be negative.Enter  again.\n";
                cin>>cost;
            }

            cout << "Enter Grant:";

            getchar();
            getline(cin,grant);

            cout << "Press 1 if the Equipment is in working condition else press 2 :  ";
            cin >> input;
            if (cin.fail())   // user entered string value instead of integer
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            if (input == 1)
                Working = true;
            else
                Working = false;


            cout<<"Enter the name of lab incharge : ";

            getchar();
            getline(cin,lab_inc);


            cout<<"Enter the name of Head of Department : ";

            getline(cin,hod);


            cout<<"Remarks : ";

            getline(cin,remark);


            PSLab.push_back(equipment(UID,name,desc,day,mon,year,purc_info,quant,cost,grant,Working,lab_inc,hod,remark));
            cout << endl << "Record inserted Successfully" << endl;
            oss.str("");
            break;


        case 2:

            cout << "|------------------------------------------------------------------------------COLLEGE OF ENGINEERING,PUNE-------------------------------------------------------------------------------|" << endl;
            cout << "|----------------------------------------------------------------------------ELECTRICAL ENGINEERING DEPARTMENT---------------------------------------------------------------------------|" << endl;
            cout << "__________________________________________________________________________________________________________________________________________________________________________________________" << endl;
            cout<<"\n";
            cout << "|--------------------------------------------------------------------------DEADSTOCK REGISTER-Power System  Lab--------------------------------------------------------------------------|" << endl;
            cout << "|________________________________________________________________________________________________________________________________________________________________________________________|" << endl;
            cout << "__________________________________________________________________________________________________________________________________________________________________________________________" << endl;
            cout << "| UID  |        Equipment         |     Description     | Date     |  Purchase Information   | Quantity|  Cost |     Grant    |   Status  |  Lab Incharge |      H.O.D    |     Remarks   |" << endl;
            cout << "|______|__________________________|_____________________|__________|_________________________|_________|_______|______________|___________|_______________|_______________|_______________| "<< endl;
            length = PSLab.size();
            for (i = 0; i < length; i++)
            {
                if (PSLab[i].getstat() == 1)
                    working = "Working";
                else
                    working = "Not Working";


                printf("|%-6s|%-26s|%-21s|%-2d-%-2d-%-4d|%-25s|%-9d|%-7d|%-14s|%-11s|%-15s|%-15s|%-15s|\n",
                       (PSLab[i].getUID()).c_str(), (PSLab[i].getname()).c_str(), (PSLab[i].getdes()).c_str(), (PSLab[i].getday()),(PSLab[i].getmon()),
                       (PSLab[i].getyear()), (PSLab[i].getpurc_info()).c_str(), (PSLab[i].getnum()), (PSLab[i].getcost()), (PSLab[i].getgrant()).c_str(),
                       working.c_str(), (PSLab[i].getlabinc()).c_str(),(PSLab[i].gethod()).c_str(),(PSLab[i].getremark()).c_str());
                cout << "|______|__________________________|_____________________|__________|_________________________|_________|_______|______________|___________|_______________|_______________|_______________|" << endl;
            }
            break;

        case 3:
            cout << "Enter Unique ID : ";
            cin >> UID;


            length = PSLab.size();  //returns the current size of the database
            for (i = 0; i < length; i++)
                if (UID == PSLab[i].getUID())
                    break;
            if (i != length)
            {


                getchar();
                getline(cin,name);
                PSLab[i].setname(name);
                cout << "Enter Description of the Equipment : ";

                getline(cin,desc);

                cout<<"Enter day :";
                cin>>day;
                //VALIDATION
                while(day<=0 || day>31)
                {
                    cout<<"Invalid day. Enter again\n";
                    cin>>day;
                }

                //VALIDATION
                cout<<"Enter month: ";
                cin >> mon;
                while(mon <=0 || mon>12)
                {
                    cout<<"Invalid month. Enter again\n";
                    cin>>mon;
                }

                cout<<"Enter year: ";
                cin >> year;

                //VALIDATION
                while(year<=0)
                {
                    cout<<"Invalid year. Enter again\n";
                    cin>>year;
                }

                cout << "Enter purchase information : ";

                getchar();
                getline(cin,purc_info);



                cout << "Enter quantity : ";
                cin>>quant;

                //VALIDATION
                while(quant <0)
                {


                    cout<<"Quantity cannot be negative.Enter again.\n";
                    cin>>quant;



                }

                //VALIDATION
                cout<<"Enter cost : ";
                cin >> cost;
                while(cost <0)
                {

                    cout<<"Cost cannot be negative.Enter  again.\n";
                    cin>>cost;


                }

                cout << "Enter Grant:";

                getchar();
                getline(cin,grant);

                cout << "Press 1 if the Equipment is in working condition else press 2 :  ";
                cin >> input;
                if (input == 1)
                    Working = true;
                else
                    Working = false;


                cout<<"Enter the name of lab incharge : ";

                getchar();
                getline(cin,lab_inc);


                cout<<"Enter the name of Head of Department : ";

                getline(cin,hod);


                cout<<"Remarks : ";

                getline(cin,remark);


                PSLab[i]=equipment(UID,name,desc,day,mon,year,purc_info,quant,cost,grant,Working,lab_inc,hod,remark);
                cout << endl << "Record inserted Successfully" << endl;
                oss.str("");
                break;


            }
            else
                cout << "Record not found, Please enter a valid Unique ID." << endl;


            break;
        case 4:
            cout << "Enter Unique ID : ";
            cin >> UID;

            length = PSLab.size();  //returns the current size of the database
            for (i = 0; i < length; i++)
                if (UID == PSLab[i].getUID())
                    break;
            if (i != length)
            {

                cout<<"**************************************************************************************"<<endl;
                cout<<"UID                      :"<<(PSLab[i].getUID()).c_str()<<endl;
                cout<<endl;
                cout<<"Name of the Equipment    :"<<(PSLab[i].getname()).c_str()<<endl;
                cout<<endl;
                cout<<"Description of Equipment :"<<(PSLab[i].getdes()).c_str()<<endl;
                cout<<endl;
                cout<<"Date of Purchase         :"<<(PSLab[i].getday())<<"-"<<(PSLab[i].getmon())<<"-"<<(PSLab[i].getyear())<<endl;
                cout<<endl;
                cout<<"Purchase Information     :"<<(PSLab[i].getpurc_info()).c_str()<<endl;
                cout<<endl;
                cout<< "Quantity                 :"<<(PSLab[i].getnum())<<endl;
                cout<<endl;
                cout<< "Cost                     :"<<(PSLab[i].getcost())<<endl;
                cout<<endl;
                cout<< "Grant                    :"<<(PSLab[i].getgrant()).c_str()<<endl;
                cout<<endl;
                cout<<"Status                   :"<<working.c_str()<<endl;
                cout<<endl;
                cout<<"Name of Lab Incharge     :"<<(PSLab[i].getlabinc()).c_str()<<endl;
                cout<<endl;
                cout<<"Name of H.O.D            :"<<(PSLab[i].gethod()).c_str()<<endl;
                cout<<endl;
                cout<<"Remarks                  :"<<(PSLab[i].getremark()).c_str()<<endl;
                cout<<endl;
                //break;
                cout<<"***************************************************************************************"<<endl;
            }
            else
                cout << "Record not found, Please enter a valid Unique ID." << endl;

            break;
        case 5:
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }


        if (input != 1)
            getchar();
        cout << "Press any key to continue : ";
        getchar();




// Special and Unique thing of the project !

// For the program to be Operating System Indepentedent, we have used the following:

//This program will be executable on Windows, Mac and Linux Opearting Systems!

#ifdef _WIN32              //WIN32 is a macro - Windows 32 bits
        system("cls");
#elif _WIN64              //WIN64 is a macro - Windows 64 bits
        system("cls");
#elif _unix_
        system("clear");
#elif _linux_
        system("clear");
#else
        system("clear");
#endif




    }
    while (input != 5);

    ofstream fout;
    fout.open("database.csv");

    length = PSLab.size();
    cout << length << endl;

    for (i = 0; i < length; i++)
    {
        fout << PSLab[i].getUID() << ",";
        fout << PSLab[i].getname() << ",";
        fout << PSLab[i].getdes() << ",";
        fout << PSLab[i].getday() << ",";
        fout << PSLab[i].getmon() << ",";
        fout << PSLab[i].getyear() << ",";
        fout << PSLab[i].getpurc_info() << ",";
        fout << PSLab[i].getnum() << ",";
        fout << PSLab[i].getcost() << ",";
        fout << PSLab[i].getgrant() << ",";
        fout << PSLab[i].getstat() << ",";
        fout << PSLab[i].getlabinc() << ",";
        fout << PSLab[i].gethod() << ",";
        fout << PSLab[i].getremark() << endl;

    }

    fout.close();

    return 0;

}




