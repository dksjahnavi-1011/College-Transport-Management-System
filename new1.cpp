#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<sstream>
#include<unordered_map>
#include<windows.h>
#include<unistd.h>

using namespace std;

string notice;

int count=0;
class student{/*Class to read student details for registration*/
    public:
        char name[20];
        char usn[10];
        char sem[5];
        char dept[4];
        char phone[10];
        char fname[20];
        char username[10];
        char password[10];
        char buffer[100];
        char extra[20];
        char complaint[50];

}s;



class staff{/*Class to read staff details for registration*/
    public:
        char name[20];
        char staffid[10];
        char dept[4];
        char phone[10];
        char username[10];
        char password[10];
        char buffer[100];
        char extra[20];
        char complaint[50];
        void pack();
       

}t;

struct index{
    string staf;
    int addr;

}i1[100],temp;

int cnt;
void create_index();
void sort_index();
void search();
int bin_search(string);
void del();





class register_form{
    public:
        int instructions_form();
        int registration_form();
        int confirmation_s_form();
        int confirmation_t_form();
        int staff_register();
        int student_register();
}r;/*Class for registration section*/

class staff_login{
    public:
        int login_staff();
        int authenticate();
        int basic_details();
        int allotment_details();
        int complaint();
       
}sl;

class student_login{
    public:
        int login_student();
        int authenticate();
        int basic_details();
        int allotment_details();
        int fee_structure();
        int complaint();
}stl;

class admin_login{
    public:
        int login_admin();
        int list_of_staff();
        int list_of_student();
        int route_details();
        int general_notices();
        int main_page();
        int list_of_complaints();
}a;


bool authenticate(const std::string& username, const std::string& password) {/*Staff Login Authentication*/
    std::ifstream file("login_staff.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    std::string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool authenticate1(const std::string& username, const std::string& password) {/*Student Login Authentication*/
    std::ifstream file("login_student.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return false;
    }

    std::string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void general_notices();


void start_application(){/*Starting of the application*/
    int ch;
    do{
    cout<<"\t\t\t\t\t-----COLLEGE TRANSPORTATION SYSTEM-----\n";
    cout<<"\t\t\t\t---------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t1.Registration form\n";
    cout<<"\t\t\t\t\t\t2.Student Login\n";
    cout<<"\t\t\t\t\t\t3.Staff Login\n";
    cout<<"\t\t\t\t\t\t4.Admin Login\n";
    cout<<"\t\t\t\t\t\t5.General notices\n";
    cout<<"\t\t\t\t\t\t6.Exit\n\n\n\n";
    cout<<"Enter your choice:";
    cin>>ch;
    switch(ch){
        case 1: r.instructions_form();
                break;
        case 2: {
            std::string username, password;
            cout<<"--------------------------------\n";
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (authenticate1(username, password)) {
                std::cout << "Login successful!" << std::endl;
                stl.login_student();
                
            } else {
                std::cout << "Invalid username or password." << std::endl;
        }

        };
            
            break;
        case 3: {
            std::string username, password;
            cout<<"---------------------------------------\n";
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            if (authenticate(username, password)) {
                std::cout << "Login successful!" << std::endl;
                sl.login_staff();
            } else {
                std::cout << "Invalid username or password." << std::endl;
            }

        };
                
                break;
        case 4: a.login_admin();
                break;
        case 5: general_notices();
                break;
        default:exit(0);
      
               

    }
    }while(ch>0&&ch<6);
    
   
}

int register_form::instructions_form()/*Instructions before registration*/{
    system("cls");
    int i;
    cout<<"\t\t\t-----Read the instructions before registration for college transport-----\n";
    char a;
    string content;
    ifstream file("instructions.txt");
    getline(file,content,'\0');
    cout<<content<<endl;
    file.close();
    cout<<"\t\t\t\t\tTo accept the above instructions press Y: ";
    cin>>a;
    if(a=='y'||a=='Y'){
        system("cls");
        registration_form();
    }
    else{
        system("cls");
        cout<<"Sorry you entered a wrong choice.\n";
      
    }


    return 0;
}

int register_form::registration_form(){/*Registration form for college transport*/
    system("cls");
    int ch;
    cout<<"\t\t\t\t\t-----REGISTRATION FORM-----\n";
    cout<<"\t\t\t\t---------------------------------------------------\n";
    cout<<"\t\t\t\t\t1.STUDENT\t2.STAFF\n\n\n\n";
    cout<<"Enter your choice:";
    cin>>ch;
    if(ch==1){
        system("cls");
        student_register();
    }
    else
    {
        system("cls");
        staff_register();
    }
    return 0;
}

int register_form::student_register(){/*Student details*/
    system("cls");
    fstream fp,fp1;
    int i;
    fp.open("student.txt",ios::out|ios::app);
    if(!fp){
        cout<<"Unable to open the file\n";
    }
    cout<<"\t\t\t\t\t-----STUDENT INFORMATION-----\n";
    cout<<"\t\t\t\t-----------------------------------------------------\n";
    cout<<"\t\t\t\t\t\tEnter your name:";
    cin>>s.name;
    cout<<"\t\t\t\t\t\tEnter your father's name:";
    cin>>s.fname;
    cout<<"\t\t\t\t\t\tEnter your USN:";
    cin>>s.usn;
    cout<<"\t\t\t\t\t\tEnter your department:";
    cin>>s.dept;
    cout<<"\t\t\t\t\t\tEnter your semester:";
    cin>>s.sem;
    cout<<"\t\t\t\t\t\tEnter your phone number:";
    cin>>s.phone;
  

    strcpy(s.buffer,s.name);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.usn);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.fname);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.dept);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.sem);
    strcat(s.buffer,"|");
    strcat(s.buffer,s.phone);
    strcat(s.buffer,"\n");
    fp<<s.buffer;
    fp.close();

    fp1.open("login_student.txt",ios::out|ios::app);
    if(!fp1){
        cout<<"Unable to open the file\n";
    }
    cout<<"\t\t\t\t-------------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\tEnter your username:(Must be your USN)";
    cin>>s.username;
    cout<<"\t\t\t\t\t\tEnter your password:";
    cin>>s.password;
    strcpy(s.extra,s.username);
    strcat(s.extra," ");
    strcat(s.extra,s.password);
    strcat(s.extra,"\n");
    fp1<<s.extra;
    fp1.close();
    system("cls");
    confirmation_s_form();
    return 0;

}

int register_form::staff_register(){/*Staff details*/
    system("cls");
    fstream fp,fp1;
    
    int n;
    fp.open("staff.txt",ios::out|ios::app);
   
    if(!fp){
        cout<<"Unable to open the file\n";
    }
    
    cout<<"\t\t\t\t\t-----STAFF INFORMATION-----\n";
    cout<<"\t\t\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\t\t\tEnter your name:";
    cin>>t.name;
    cout<<"\t\t\t\t\t\tEnter your staff id:";
    cin>>t.staffid;
    cout<<"\t\t\t\t\t\tEnter your department:";
    cin>>t.dept;
    cout<<"\t\t\t\t\t\tEnter your phone number:";
    cin>>t.phone;
   
   
    strcpy(t.buffer,t.name);
    strcat(t.buffer,"|");
    strcat(t.buffer,t.staffid);
    strcat(t.buffer,"|");
    strcat(t.buffer,t.dept);
    strcat(t.buffer,"|");
    strcat(t.buffer,t.phone);
    strcat(t.buffer,"\n");
    fp<<t.buffer;
    
    fp.close();

    fp1.open("login_staff.txt",ios::out|ios::app);
    if(!fp1){
        cout<<"Unable to open the file\n";
    }
    cout<<"\t\t\t\t-------------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\tEnter your username:(Must be your STAFFID)";
    cin>>t.username;
    cout<<"\t\t\t\t\t\tEnter your password:";
    cin>>t.password;
    strcpy(t.extra,t.username);
    strcat(t.extra," ");
    strcat(t.extra,t.password);
    strcat(t.extra,"\n");
    fp1<<t.extra;
    fp1.close();
    system("cls");
    
    confirmation_t_form();
    
    return 0;

}



int register_form::confirmation_s_form(){/*Confirmation of student details*/
    system("cls");
    char ch;
    cout<<"\t\t\t\t\t-----CONFIRMATION FORM-----\n";
    cout<<"\t\t\t\t-----------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\tName:"<<s.name<<endl;
    cout<<"\t\t\t\t\t\tUSN:"<<s.usn<<endl;
    cout<<"\t\t\t\t\t\tFather's Name:"<<s.fname<<endl;
    cout<<"\t\t\t\t\t\tDepartment:"<<s.dept<<endl;
    cout<<"\t\t\t\t\t\tSemester:"<<s.sem<<endl;
    cout<<"\t\t\t\t\t\tPhone Number:"<<s.phone<<endl;
    cout<<"\t\t\t\t----------------------------------------------------------------\n\n\n";
    cout<<"Enter 'C' to confirm the details:";
    cin>>ch;
    if(ch=='c'||ch=='C'){
      system("cls");
      start_application();
    }
}

int register_form::confirmation_t_form(){/*Confirmation of staff details*/ 
    system("cls");
    char ch;
    cout<<"\t\t\t\t\t-----CONFIRMATION FORM-----\n";
    cout<<"\t\t\t\t-------------------------------------------------------------\n";
    cout<<"\t\t\t\t\t\tName:"<<t.name<<endl;
    cout<<"\t\t\t\t\t\tStaff ID:"<<t.staffid<<endl;
    cout<<"\t\t\t\t\t\tDepartment:"<<t.dept<<endl;
    cout<<"\t\t\t\t\t\tPhone Number:"<<t.phone<<endl;
    cout<<"\t\t\t\t--------------------------------------------------------------\n";

    cout<<"Enter 'C' to confirm the details:";
    cin>>ch;
    if(ch=='c'||ch=='C'){
      system("cls");
      start_application();
    }
}

int staff_login::login_staff(){/*Staff main page*/
    system("cls");
    int ch;
    do{
       
    cout<<"\t\t\t\t\t-----PLEASE ENTER YOUR CHOICE-----\n\n";
    cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"\t\t\t\t\t1.Basic Details\n\t\t\t\t\t2.Allotment Details\n\t\t\t\t\t3.Complaint\n\t\t\t\t\t4.Exit\n";
     cout<<"\t\t\t\t-------------------------------------------------------\n";
    cout<<"\t\t\t\t\tEnter your choice:";
    cin>>ch;
    switch(ch){
        case 1: sl.basic_details();
                break;
        case 2: sl.allotment_details();
            break;
        case 3: sl.complaint();
                break;
        case 4: start_application();
                break;
        default:exit(0);

    }
    }while (ch>0&&ch<5);
    return 0;
}

int staff_login::basic_details(){/*Basic general details stored for particular usn */
    system("cls");
    cout<<"\t\t\t\t\t-----BASIC DETAILS-----\n";
    cout<<"\t\t\t\t\t----------------------------------------------------------------\n";
    fstream fp;
    int flag=0;
    int i=0;
    char id[10];
    fp.open("staff.txt",ios::in);
    //fp.open("allot_staff",ios::out);
    cout<<"\t\t\t\t\t\tEnter your staff id:";
    cin>>id;

    while (!fp.eof())
    {
        fp.getline(t.name,10,'|');
        fp.getline(t.staffid,10,'|');
        fp.getline(t.dept,10,'|');
        fp.getline(t.phone,10,'\n');
        fp.getline(t.buffer,45);
        if(strcmp(t.staffid,id)==0){
            flag=1;
            cout<<"\t\t\t"<<t.name<<"\t\t\t"<<t.staffid<<"\t\t\t"<<t.dept<<"\t\t\t"<<t.phone<<endl;
           // fp<<t.staffid<<"|"<<t.name<<"|"<<t.dept<<"|"<<t.phone<<"\n";
            break;
            sleep(10);
            system("cls");
        }

    }
    if(flag==0){
        cout<<"No record found\n";
        system("cls");
    }
    fp.close();
    return 0;
}

int staff_login::allotment_details(){/*Allotment details of staff*/
    system("cls");
    int route,distance;
    
    char pickuppoint[20];

    cout<<"\t\t\t\t\t-----ALLOTMENT DETAILS-----\n";
    cout<<"\t\t\t\t\t------------------------------------------------------------\n";

    
    cout<<"\t\t\t\t\t\t1.Bangalore South\n\t\t\t\t\t\t2.Bangalore North\n\t\t\t\t\t\t3.Bangalore East\n\t\t\t\t\t\t4.Bangalore West\n";
    cout<<"\t\t\t\t\t\tSelect your route\n\n";
    cin>>route;
    cout<<"\t\t\t\t\t\tEnter the bus pickup point\n\n";
    cin>>pickuppoint;
    cout<<"\t\t\t\t\t\tEnter the distance between pickup point and college\n\n\n";
    cin>>distance;
    if(route==1){
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t---------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\t\tDriver Name: Srinivas"<<"\n";
        cout<<"\t\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else if(route==2)
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\t\tDriver Name: Arjun"<<"\n";
        cout<<"\t\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else if(route==3)
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t----------------------------------------------------\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Deepthi"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else 
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t-----------------------------------------------------\n";
        cout<<"\t\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\t\tDriver Name: Varun"<<"\n";
        cout<<"\t\t\t\t\t\tContact Number:123454678"<<"\n";
    }

    cout<<"\t\t\t\t\t-----PICKUP POINT-----\n";
    cout<<"\t\t\t\t-----------------------------------------------------------------\n";
    cout<<"\n\t\t\t\t\tBus pickup point:"<<pickuppoint<<"\n\n";

    cout<<"\t\t\t\t\t-----FEES DETAILS-----\n";
     cout<<"\t\t\t\t-----------------------------------------------------------------\n";
    if(distance>0&&distance<=10){
        cout<<"\t\t\t\t\t\tFees for this academic year:Rs.10000"<<"\n\n";
    }
    else if(distance>11&&distance<=20){
        cout<<"\t\t\t\t\t\tFees for this academic year:Rs.12000"<<"\n\n";
    }
    else if(distance>21&&distance<=30){
        cout<<"\t\t\t\t\t\tFees for this academic year:Rs.14000"<<"\n\n";
    }
    else cout<<"\t\t\t\t\t\tFees for this academic year:Rs.20000"<<"\n\n";
    sleep(10);
    system("cls");

    return 0;

}      

int staff_login::complaint(){/*Staff complaint box*/
    system("cls");
    fstream fp;
    string complaint;
    string staffid;
    string date;
    fp.open("complaint_staff.txt",ios::out|ios::app);
    cout<<"\t\t\t\t\t-----COMPLAINT BOX-----\n\n";
    cout<<"\t\t\t\t------------------------------------------------\n\n";
     getline(cin,staffid);
    cout<<"\t\t\t\t\t\tEnter your Staff ID:";
    getline(cin,staffid);
     //getline(cin,complaint);
    cout<<"\t\t\t\t\t\tEnter your complaint:";
     getline(cin,complaint);
     cout<<"\t\t\t\t\t\tEnter the date:";
     getline(cin,date);

     string v=staffid + "|" + date + "|" + complaint + "\n";
     fp<<v;
    sleep(5);
    system("cls");
    return 0;
}

int student_login::login_student(){/*Student main page*/
    system("cls");
    int ch;
    do{
       
    cout<<"\t\t\t\t\t-----PLEASE ENTER YOUR CHOICE-----\n\n";
    cout<<"\t\t\t\t\t--------------------------------------------------------------\n";
    cout<<"\t\t\t\t\t1.Basic Details\n\t\t\t\t\t2.Allotment Details\n\t\t\t\t\t3.Complaint Box\n\t\t\t\t\t4.Exit\n";
    cout<<"\t\t\t\t\tEnter your choice:";
    cin>>ch;
    switch(ch){
        case 1: stl.basic_details();
                break;
        case 2: stl.allotment_details();
            break;
        case 3: stl.complaint();
                break;
        case 4: start_application();
                break;
        default:exit(0);

    }
    }while (ch>0&&ch<5);
    return 0;
}

int student_login::basic_details(){/*Basic general details stored for particular usn */
    system("cls");
    cout<<"\t\t\t\t\t-----BASIC DETAILS-----\n\n";
    cout<<"\t\t\t\t\t-----------------------------------------------------\n";
    fstream fp;
    int flag=0;
    int i=0,j;
    char usn[10];
    student s;
    fp.open("student.txt",ios::in);
    cout<<"\t\t\t\t\tEnter your USN:";
    cin>>usn;
 
    while (!fp.eof())
    {
        fp.getline(s.name,10,'|');
        fp.getline(s.usn,10,'|');
        fp.getline(s.fname,10,'|');
        fp.getline(s.dept,10,'|');
        fp.getline(s.sem,10,'|');
        fp.getline(s.phone,10,'\n');
        fp.getline(s.buffer,45);
        
    
    
        if(strcmp(s.usn,usn)==0){
            flag=1;
            cout<<"\t\t"<<s.name<<"\t\t"<<s.usn<<"\t\t"<<s.fname<<"\t\t"<<s.dept<<"\t\t"<<s.sem<<"\t\t"<<s.phone<<endl;
            //break;
            sleep(5);
            system("cls");
          
        }
    
    }
    if(flag==0){
        cout<<"No record found\n";
       // system("cls");
    }
    
 
    fp.close();
    return 0;
}


int student_login::allotment_details(){/*Allotment details of student*/
    system("cls");
    int route,distance;
    char pickuppoint[20];
    cout<<"\t\t\t\t\t-----ALLOTMENT DETAILS-----\n\n";
    cout<<"\t\t\t\t\t-------------------------------------------------------\n\n";
    //cout<<"\t\t\t\t\tSelect your route\n";
    cout<<"\t\t\t\t\t1.Bangalore South\n\t\t\t\t\t2.Bangalore North\n\t\t\t\t\t3.Bangalore East\n\t\t\t\t\t4.Bangalore West\n\n";
    cout<<"\t\t\t\t\tSelect your route\n";
    cin>>route;
    cout<<"\t\t\t\t\tEnter the bus pickup point\n";
    cin>>pickuppoint;
    cout<<"\t\t\t\t\tEnter the distance between pickup point and college\n";
    cin>>distance;
    if(route==1){
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Srinivas"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else if(route==2)
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Arjun"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else if(route==3)
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Deepthi"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else 
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Varun"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
     cout<<"\t\t\t\t\t---------------------------------------------------\n\n";

    cout<<"\t\t\t\t\t-----PICKUP POINT-----\n";
     cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
    cout<<"\t\t\t\t\tBus pickup point:"<<pickuppoint<<"\n";

     cout<<"\t\t\t\t\t---------------------------------------------------\n\n";

    cout<<"\t\t\t\t\t-----FEES DETAILS-----\n";
     cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
    if(distance>0&&distance<=10){
        cout<<"\t\t\t\t\tFees for this academic year:Rs.10000"<<"\n";
    }
    else if(distance>11&&distance<=20){
        cout<<"\t\t\t\t\tFees for this academic year:Rs.12000"<<"\n";
    }
    else if(distance>21&&distance<=30){
        cout<<"\t\t\t\t\tFees for this academic year:Rs.14000"<<"\n";
    }
    else cout<<"\t\t\t\t\tFees for this academic year:Rs.20000"<<"\n";
    sleep(5);
    system("cls");
    return 0;

}      

int student_login::complaint(){/*Student complaint box*/
    system("cls");
    fstream fp;
    string complaint;
    string usn;
    string date;
    cout<<"\t\t\t\t\t-----COMPLAINT BOX-----\n\n";
    cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
    
    fp.open("complaint_student.txt",ios::out|ios::app);
     getline(cin,usn);
    cout<<"\t\t\t\t\tEnter your USN:";
    getline(cin,usn);
     //getline(cin,complaint);
    cout<<"\t\t\t\t\tEnter your complaint:";
     getline(cin,complaint);
       cout<<"\t\t\t\t\tEnter the date:";
     getline(cin,date);

     string w="\n" + usn + "|" + date + "|" + complaint + "\n";
     fp<<w;
     sleep(5);
     system("cls");
    
    return 0;
}

bool authenticate2(const std::string& username, const std::string& password) {/*Admin authentication*/
    // Replace this with your own authentication logic
    // For demonstration purposes, we are using a hardcoded username and password
    const std::string expectedUsername = "admin";
    const std::string expectedPassword = "password";

    return (username == expectedUsername && password == expectedPassword);
}
    
int admin_login::login_admin(){/*Admin login*/
    std::string username, password;
    cout<<"\t\t\t\t\t-----LOGIN DETAILS-----\n";
    cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
    // Get username and password from the user
    std::cout << "\t\t\t\t\tEnter username: ";
    std::cin >> username;
    std::cout << "\t\t\t\t\tEnter password: ";
    std::cin >> password;
    cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
    // Authenticate the login details
    if (authenticate2(username, password)) {
        std::cout << "Login successful!" << std::endl;
        a.main_page();
    } else {
        std::cout << "Invalid username or password." << std::endl;
    }

    return 0;
}  



int admin_login::main_page(){/*Admin main page*/
    system("cls");
    int ch;
    do{
       
    cout<<"\t\t\t\t\t-----PLEASE ENTER YOUR CHOICE-----\n\n";
    cout<<"\t\t\t\t\t---------------------------------------------------\n\n";
    cout<<"\t\t\t\t\t1.List of Staff\n\t\t\t\t\t2.List of Student\n\t\t\t\t\t3.Routes Details\n\t\t\t\t\t4.General Notices\n\t\t\t\t\t5.Complaints Box\n\t\t\t\t\t6.Exit\n";
    cout<<"\t\t\t\t\tEnter your choice:";
    cin>>ch;
    switch(ch){
        case 1:a.list_of_staff();
                break;
        case 2: a.list_of_student();
            break;
        case 3: a.route_details();
                break;
        case 4: a.general_notices();
                break;
        case 5: a.list_of_complaints();
                break;
        case 6: start_application();
                break;
        default:exit(0);

    }
    }while (ch>0&&ch<5);
    return 0;
}

int admin_login::list_of_staff(){/*Total Staff list*/
     system("cls");
    int i;
    cout<<"\t\t\t\t\t-----THE STAFF LIST WHO AVAILED THE TRANSPORT-----\n";
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------\n\n";
    char b;
    string content;
    ifstream file("staff.txt");
    getline(file,content,'\0');
    cout<<content<<endl;
    file.close();
    cout<<"\t\t\t\t\tTo go back press E: ";
    cin>>b;
    if(b=='e'||b=='E'){
        system("cls");
        a.main_page();
    }
    else{
        system("cls");
        cout<<"Sorry you entered a wrong choice.\n";
      
    }


    return 0;
}

int admin_login::list_of_student(){/*Total Student list*/
     system("cls");
    int i;
    cout<<"\t\t\t\t\t-----THE STUDENT LIST WHO AVAILED THE TRANSPORT-----\n";
    cout<<"\t\t\t\t\t----------------------------------------------------------------------------\n";
    char b;
    string content;
    ifstream file("student.txt");
    getline(file,content,'\0');
    cout<<content<<endl;
    file.close();
    cout<<"\t\t\t\t\tTo go back press E: ";
    cin>>b;
    if(b=='e'||b=='E'){
        system("cls");
        a.main_page();
    }
    else{
        system("cls");
        cout<<"Sorry you entered a wrong choice.\n";
      
    }


    return 0;
}
 
int admin_login::route_details(){/*Route Details*/
    int route;
    cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n\n\n";
    cout<<"\t\t\t\t\t--------------------------------------------------------\n";
    cout<<"\t\t\t\t\tSelect your route\n";
    cout<<"\t\t\t\t\t1.Bangalore South\n\t\t\t\t\t2.Bangalore North\n\t\t\t\t\t3.Bangalore East\n\t\t\t\t\t4.Bangalore West\n";
    
    cin>>route;
     if(route==1){
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t--------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Srinivas"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else if(route==2)
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t--------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Arjun"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else if(route==3)
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t--------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Deepthi"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    else 
    {
        cout<<"\t\t\t\t\t-----ROUTE DETAILS-----\n";
        cout<<"\t\t\t\t\t--------------------------------------------------------------\n";
        cout<<"\t\t\t\t\tYour selected route:"<<route<<"\n";
        cout<<"\t\t\t\t\tDriver Name: Varun"<<"\n";
        cout<<"\t\t\t\t\tContact Number:123454678"<<"\n";
    }
    sleep(5);
    system("cls");
}



int admin_login::general_notices(){
    fstream fp;
   
    int n,i;
    fp.open("notice.txt",ios::out|ios::app);
  
    cout<<"\t\t\t\t\t-----NOTICE DASHBOARD-----\n";
    cout<<"\t\t\t\t\t--------------------------------------------------------------\n";
    //for(i=0;i<n;i++){
    getline(cin,notice);
    cout<<"\t\t\t\t\tEnter the notice to be added:\n";
    getline(cin,notice);
    fp<<notice;

   
    fp.close();
}

void general_notices(){
    system("cls");
    int i;
    cout<<"\t\t\t\t\t-----GENERAL NOTICES-----\n";
    cout<<"\t\t\t\t\t------------------------------------------------------------------\n";
    char b;
    string content;
    ifstream file("notice.txt");
    getline(file,content,'\0');
    cout<<"\t\t\t\t\t"<<content<<endl;
    file.close();
    cout<<"\t\t\t\t\tTo go back press E: ";
    cin>>b;
    if(b=='e'||b=='E'){
        system("cls");
        a.main_page();
    }
    else{
        system("cls");
        cout<<"Sorry you entered a wrong choice.\n";
      
    }
}

int admin_login::list_of_complaints(){/*Complaints Box*/
    system("cls");
    int i;
    cout<<"\t\t\t\t\t-----COMPLAINTS BOX-----\n";
    cout<<"\t\t\t\t\t---------------------------------------------------------\n";
    char b;
    string content;
    ifstream file("complaint_student.txt");
    getline(file,content,'\0');
    cout<<"\t\t\t\t\t"<<content<<endl;
    file.close();
    cout<<"\t\t\t\t\tTo accept the above instructions press E: ";
    cin>>b;
    if(b=='e'||b=='E'){
        system("cls");
        a.main_page();
    }
    else{
        system("cls");
        cout<<"Sorry you entered a wrong choice.\n";
      
    }
}


int main(){
   start_application();
   
}