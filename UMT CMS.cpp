//UMT Course Management System
//Developed by Ammar Khalid & Iman Sarwar
#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>

using namespace std;
void regstd(){
	system("cls");
	cout<<"*******Registeration Window********";
	string s,v;
	string course;
	int x;
	float cgpa;
	cout<<"\nEnter Student ID : ";
	cin >> x;
	cout<<"Fee Defauter : ";
	cin >> s;
	if(s=="yes")
	{
		cout<<"can't register student\n";
	}
	else if(s=="no")
	{
		cout<<"Student is not fee defaulter";
		cout<<"\nPre Requisite course status(Pass/Fail) : ";
		cin>>v;

		if(v=="pass"){
		cout<<"register student";
		cout<<"\nEnter CGPA";
		cin >> cgpa;
		if(cgpa > 3.0)
		{
			for(int i=1;i<=5;i++){
				cout<<"Enter Course "<<i<<":"<<endl;
				cin>>course;
		}
		cout<<"Success! All Courses Registered Succesfully!"<<endl;
		}
		else if(cgpa > 2.0 && cgpa <=3.0)
		{
			for(int j=1;j<=3;j++){
				cout<<"Enter Course "<<j<<":"<<endl;
				cin>>course;
		}
		cout<<"Success! 3 Courses Registered Succesfully!"<<endl;
		}
		else if(cgpa <= 2.0)
		{
			for(int k=1;k<=2;k++){
				cout<<"Enter Course "<<k<<":"<<endl;
				cin>>course;
		}
		cout<<"Success! 2 Courses Registered Succesfully!"<<endl;
		}
		}
		else if(v=="fail")
		{
		cout<<"can't register student\n";}
		}
	ofstream myfile("info.txt",ios :: app);
	myfile<<x;
	myfile.close();
	cout<<"File created and saved successfully:)";
	}

void feeDList(){
	cout<<"\t***** List of Fee Defaulters *****"<<endl;
	cout<<"0021	Anwar Ali 	CS"<<endl;
	cout<<"0019 Ahmad Shehzad SE"<<endl;
	cout<<"0017  Yousaf Tanveer IT"<<endl;
	cout<<"0128	Sohail Khan     SE"<<endl;
	cout<<"0039  Amir Javed 	CS"<<endl;
}

float showCGPA(string id){
	float studentGPA = 0.0;
	if(id=="001")
	{
		studentGPA = 0.75;
		return studentGPA;
	}
	else if(id=="002")
	{
		studentGPA = 3.96;
		return studentGPA;
	}
	else if(id=="003")
	{
		studentGPA = 3.48;
		return studentGPA;
	}
	else if(id=="004")
	{
		studentGPA = 1.57;
		return studentGPA;
	}
	else if(id=="005")
	{
		studentGPA = 1.22;
		return studentGPA;
	}
	else
	{
		return -1;
	}
}

string preReqCourse(string c_name){
	string preReq = "NULL";
	if(c_name == "object oriented programming"){
		preReq = "Programming Fundamentals";
		return preReq;
	}

	else if(c_name == "calculus & analytical geometry"){
		preReq = "Math I & II";
		return preReq;
	}
	else if(c_name == "data structures & algorithms"){
		preReq = "Object Oriented Programming";
		return preReq;
	}
	else{
		preReq = "Invalid Course";
		return preReq;
	}
}
void delfile(){
	int status;
	char filename[20];
	cout<<"Enter the name of file : ";
	cin>>filename;
	status = remove(filename);
	if(status == 0){
		cout<<"File Deleted Successfully:)";
	}
	else{
		cout<<"Error Occured:)";
	}
	cout<<endl;
}
void update(){
	int id;
	string find;
	ofstream myfile("info.txt");
	cout<<"Enter name of file that yyou want to update : ";
	cin>>find;
	ifstream file;
	file.open("info.txt");
	cout<<"Enter id : ";
	cin>>id;
	myfile<<id;
	myfile.close();
	cout<<"File Updated Successfully:)";
}
void search(){
	int id;
	bool c;
	ifstream fin("info.txt");
	cout<<"Enter id you want to search : ";
	cin>>id;
	while(fin >> id ){
		cout << "File Data : "<< id << " ";
	}
	fin.close();
}
int main(){   
	int x,z,j,temp;
	bool c=0;
	system("pause");
	system("cls");
	cout << "Login\n";
	cout << "Enter ID : ";
	cin >> x;
	cout << "Enter Password : ";
	cin >> z;
		c=1;
		cout<<"\n\n\n                      ***********UMT Registration System***************";
		p:
		cout<<"\n\n\nPress 1 to register the students\n";
		cout<<"Press 2 to see the list of fee defaulters\n";
		cout<<"Press 3 to see the CGPA of student\n";
		cout<<"Press 4 to see the Pre requisite of a course\n";
		cout<<"Press 5 to delete the file\n";
		cout<<"Press 6 to Update the file\n";
		cout<<"Press 7 to search the File\n";
		cout<<"Press 8 to exit the system\n";
		cout<<"\nEnter your choice : ";
		cin >> j;
		switch(j){
		
			case 1:
				regstd();
				break;

			case 2:
				feeDList();
				break;
			
			case 3:
				{
					cout<<"\t*****Student CGPA Widnow*****"<<endl;
					string inpID;
					cout<<"Enter ID: "<<endl;
					cin>>inpID;
					float getVal = showCGPA(inpID);
					if(getVal==-1){
					cout<<"Invalid ID"<<endl;
				}
				else{
					cout<<"Student CGPA: "<<getVal<<endl;	
				}
				break;
		}
		
			case 4:
				{
				
				cout<<"\t*****Check Pre-Requisite Courses*****"<<endl;
				string inpCr;
				cout<<"Enter Course: "<<endl;
				cin.ignore(256,'\n');
				getline(cin,inpCr,'\n');
				for(int i=0;i<inpCr.length();i++){
					if(inpCr[i]>='A' && inpCr[i]<='Z')
						{
							inpCr[i] = inpCr[i]+32;
						}
					}
				string getCr = preReqCourse(inpCr);
			
				if(getCr == "Invalid Course"){
					cout<<"Invalid Entry! Try Again"<<endl;
				}
				else{
					cout<<"Pre-Requisite Course: "<<getCr<<endl;
				}
				break;	
			}
			case 5:
				delfile();
				break;
			case 6:
				update();
				break;
			case 7:
				search();
				break;
			case 8:
				exit(0);
	    	}
		goto p;
	}



