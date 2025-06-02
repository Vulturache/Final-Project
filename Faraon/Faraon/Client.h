#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Client
{
private:
	double banii;
	string nume;
public:
	Client();
	void main_menu();
	void log_in();
	void log();
	void reg();
};