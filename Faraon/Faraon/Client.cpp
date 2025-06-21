#include "Client.h"

Client::Client() {}
void Client::main_menu()
	{

		int alegere;
		cout << "\t\t ___________________________________FARAON___________________________________ \n\n\n";
		cout << nume << "," << "Bine ati venit pe aplicatia noastra de banking, alegeti optiunea dorita\n" << endl;
		cout << "\n\n\n";
		cout << "1.Interogare Sold" << endl;
		cout << "2.Retragere Numerar" << endl;
		cout << "3.Transfer catre un alt cont" << endl;
		cout << "4.Adaugati banii in cont" << endl;
		cout << "5.Iesire" << endl;
		cout << "Optiunea: ";
		cin >> alegere;

		switch (alegere)
		{
		case 1:
		{
			cout << endl;
			cout << nume << ",\n" << " Sold-ul dumneavoastra este: " << banii << endl;
			cout << endl;
			system("PAUSE");
			system("cls");
			main_menu();
			break;
		}
		case 2:
		{
			double ex;
			cout << "Cati banii ati dorii extrasi?\n";
			cin >> ex;
			cout << "Ati retras suma de: " << ex << endl;
			system("PAUSE");
			system("cls");
			retragereBanii(ex);
			main_menu();
			break;
		}
		case 3:
		{
			double suma_transferata;
			string username_ales;
			cout << "Introduceti username-ul persoanei: \n"; cin >> username_ales;
			cout << "Ce suma transferati: \n"; cin >> suma_transferata;
			if (suma_transferata > banii)
			{
				cout << "Fonduri insuficiente" << endl;
				system("PAUSE");
				system("cls");
				main_menu();
			}
			ifstream ales("Conturi.txt");
			if (!ales)
			{
				cout << "Eroare la deschiderea fisierului";
				return;
			}
			vector<string> lines; // pentru a rescrie in fisier tot text
			string u, p;
			double b;
			bool user_exista = false; // daca gasim user
			while (ales >> u >> p >> b)
			{
				if (u == username_ales)
				{
					b = b + suma_transferata;
					user_exista = true;
				}                        // suma contului gasit se schimba
				if (u == nume)
				{
					b = b - suma_transferata;
					banii = b;
				}                               //suma de pe contul curent se schimba
				lines.push_back(u + " " + p + " " + to_string(b)); // se pun datele in vector ca si string
			
			}

			ales.close();
			if (!user_exista)
			{
				cout << "Acest user nu exista" << endl;
				system("PAUSE");
				system("cls");
				main_menu();
			}
			ofstream transfer("Conturi.txt");
			if (!transfer)
			{
				cout << "Eroare la deschiderea fisierului";
				return;
			}
			for (const auto& el : lines)
			{
					transfer << el << endl; // se scriu datele din vector
			}
			transfer.close();
			cout << "Transfer facut cu success!" << endl;
			system("PAUSE");
			system("cls");
			main_menu();
			break;
		}
		case 4:
		{
			double add;
			cout << "Cati banii depuneti?\n";
			cin >> add;
			banii = banii + add;
			cout << "Ati adaugat: " << add << " la contul dumneavoastra" << endl;
			cout << "Total-ul din cont este de: " << banii << endl;
			system("PAUSE");
			system("cls");
			modificareBanii(add);
			main_menu();
			break;

		}
		case 5:
		{
			cout << "Multumim" << endl;
			log_in();
			break;
		}
		default:
			system("cls");
			cout << "Va rog alegeti o optiune valida" << endl;
			system("PAUSE");
			main_menu();
			break;
		}
	}

	void Client::log_in()
	{
		int al;
		cout << "\t\t\t                              Bine ati venit pe aplicatia Faraon                       \n\n\n";
		cout << "\t\t\t                  Va rog introduceti User-ul si Parola pentru a va autentifica             \n\n\n";
		cout << endl;
		cout << "1.Autentificare" << endl;
		cout << "2.Inregistrare" << endl;
		cout << "3.Iesire" << endl;
		cout << "Optiunea: ";
		cin >> al;
		switch (al)
		{
		case 1:
		{
			log();
			break;
		}
		case 2:
		{
			reg();
			break;
		}
		case 3:
		{
			cout << "Multumim" << endl;
			system("PAUSE");
			exit;
			break;
		}
		default:
			system("cls");
			cout << "Va rog alegeti o optiune valida" << endl;
			system("PAUSE");
			log_in();
			break;
		}

	}

	void Client::log()
	{
		int n = 0; // counter pentru a tracka daca logarea este reusita
		string username, parola; // variabile temporare pentru user input
		system("cls");
		cout << "Introduceti Username-ul si o Parola de la cont" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Parola: ";
		cin >> parola;

		fstream input("Conturi.txt"); // read and write in fisierul conturi
		if (!input) // error la deschiderea fisierului
		{ 
			cout << "Eroare la deschiderea fisierului";
			return;
		}

		string u, p;
		double b; // variabile locale temporare pentru a citi username, password si bani

		while (input >> u >> p >> b) // citeste user, parola si valoarea
		{
			if (username == u && parola == p)
			{
				nume = u;   
				banii = b;     // variabilele de clasa au valoarea user-ului logat
				n = 1; // login reusit
				break;       
			}
		}
		input.close(); // inchidem fisiser

		if (n == 1)
		{
			cout << username << ",\nAti fost logat cu succes\n";
			system("PAUSE");
			system("cls");
			main_menu();
		}
		else
		{
			cout << "Eroare de logare\n";
			system("PAUSE");
			log(); // daca login e reusit trecem la main menu daca nu reapelam logarea
		}
	}
	void Client::reg()
	{
		string username_r, parola_r; //variabile pentru a citi user si parola noua
		system("cls");
		cout << "Alegeti un Username: ";
		cin >> username_r;
		cout << "Alegeti o Parola: ";
		cin >> parola_r;
		cout << "Cati banii aveti in cont? ";
		cin >> banii; 
		ofstream reg1("Conturi.txt", ios::app); // scriem in fisiser, una sub alta
		reg1 << username_r << ' ' << parola_r << ' ' << banii << endl; // scrie in fisier username parola si bani
		cout << "Intregistrare completa";
		log_in(); // trece la meniu de logare

	}

	void Client::modificareBanii(double banii_c)
	{
		ifstream cit("Conturi.txt"); // deschidem fisier
		if (!cit)
		{
			cout << "Eroare la deschiderea fisierului";
			return;
		}

		vector<string> lines; //variabile temporare si vector pentru a stoca liniile din conturi.txt
		string u, p;
		double b;

		while (cit >> u >> p >> b)
		{
			if (u == nume)
			{
				b = b + banii_c;
				banii = b;
			}//citeste liniile din doc si updateaza banii pentru userul logat

			lines.push_back(u + " " + p + " " + to_string(b)); // salveaza datele modificate in vector, to_string convert numere in string
		}
		cit.close();

		ofstream modif("Conturi.txt");
		for (const string& line : lines)
		{
			modif << line << '\n';
		}
		modif.close(); // foloseste liniile salvate in vector si le scrie in fisiser
	}

	void Client::retragereBanii(double banii_c) // la fel ca aia de sus doar ca cu -
	{
		ifstream cit("Conturi.txt");
		if (!cit)
		{
			cout << "Eroare la deschiderea fisierului";
			return;
		}

		vector<string> lines;
		string u, p;
		double b;

		while (cit >> u >> p >> b)
		{
			if (u == nume)
			{
			  if (b < banii_c) 
			  {
					cout << "Fonduri insuficiente!\n";
					system("PAUSE");
					system("cls");
					return;
			  }
			  else 
			  {
				  b = b - banii_c;
				  banii = b;
			  }
			}

			lines.push_back(u + " " + p + " " + to_string(b));
		}
		cit.close();

		ofstream modif("Conturi.txt");
		for (const string& line : lines)
		{
			modif << line << '\n';
		}
		modif.close();
	}