// Time: 2016.05.26
// Project_name: back-up folder
// Level: simplest
// Function: back-up folder easily
//
//
// back_up.cpp
//
// 1.txt :  the test input

# include <iostream>
# include <string>
# include <boost/filesystem.hpp> // need to install boost
# include <cstdlib>

using namespace std;

int main(void) {
	// source : The path of folder you want to back-up
	// target : The path of destination to place your back_up
	// back_up_name : The name of .zip
	string source;
	string target;
	string back_up_name;
	// if the path does not exist, you should repeated enter the source
	while (true) {
		cout << "Please enter the source of document that you want to back_up:\n";
		cin >> source;
		// exist() used to judge the existence of the path
		if (boost::filesystem::exists(source)) {
			cout << "Good! The path does exist!\n";
			break;
		} else {
			cout << "Sorry, the path does not exist!\n";
		}
	}
	// if the path does not exist, you can choose the way of creating a new folder
	while (true) {
		cout << "Please enter the path of the back_up that you want to place:\n";
		cin >> target;
		if (boost::filesystem::exists(target)) {
			cout << "Good! The path does exist\n";
			break;
		} else {
			cout << "Sorry, the path does not exist!\n";
			cout << "Do you want to creat a new folder?\n";
			char ch;
			cin >> ch; // To make a choice
			if (ch == 'Y' || ch == 'y') { // create new folder
				string command = "mkdir " + target;
				int b  = system(command.c_str());
				if (b == 0) {
					cout << "Successfully creat new folder\n";
				} else {
					cerr << "Unexpected error occurred!\n";
					cout << "The program will be closed!\n";
					return -1;	
				}
				break;
			} // or you should enter repeatedly until you enter a right path
		}
	}
	cout << "Please enter the name of back_up:\n";
	cin >> back_up_name;
	// In unix, the command of press : zip -qr target+back_up_name source
	// -q quiet operation
	// -r recurse into directories 
	string command = "zip -qr ";
	command += target + back_up_name + ".zip" + " " + source;
	int a = system(command.c_str()); // run the command in terminal
	if (a != 0) {
		cerr << "Unexpected error occurred!\n";
		cout << "The program will be closed!\n";
		return -1;		
	} else {
		cout << "Successful back_up " << source << endl;
		cout << "Successful creat " << back_up_name << ".zip in " 
			 << target << endl;
	}
	cout << "The task is over~\n";
	cout << "The program will be closed!\n";
	return 0;
}
