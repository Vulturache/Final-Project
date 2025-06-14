#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Client
{
private:
	double banii = 0;
	string nume;
	string uid, pass;
public:
	Client();
	void main_menu();
	void log_in();
	void log();
	void reg();
	void modificareBanii(double);
	void retragereBanii(double);
};