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
			banii = banii - ex;
			cout << "Ati retras suma de: " << ex << endl;
			cout << "In contul dumneavoastra au ramas: " << banii << endl;
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
			retragereBanii(suma_transferata);
			ifstream ales("Conturi.txt");
			if (!ales)
			{
				cout << "eroare la deschiderea fisierului";
			}
			while (ales >> username_ales >> pass >> banii)
			{
				banii = banii + suma_transferata;
			}
			ofstream transfer("Conturi.txt");
			transfer << username_ales << ' ' << pass << ' ' << banii << endl;
			transfer.close();
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
			system("PAUSE");
			exit;
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
		int n = 0;
		string username, parola;
		system("cls");
		cout << "Introduceti Username-ul si o Parola de la cont" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Parola: ";
		cin >> parola;

		fstream input("Conturi.txt");
		if (!input)
		{
			cout << "Eroare la deschiderea fisierului";
			return;
		}

		string u, p;
		double b;

		while (input >> u >> p >> b)
		{
			if (username == u && parola == p)
			{
				nume = u;   
				banii = b;    
				n = 1;
				break;       
			}
		}
		input.close();

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
			log();  // try again
		}
	}
	void Client::reg()
	{
		string username_r, parola_r;
		system("cls");
		cout << "Alegeti un Username: ";
		cin >> username_r;
		cout << "Alegeti o Parola: ";
		cin >> parola_r;
		cout << "Cati banii aveti in cont? ";
		cin >> banii;
		ofstream reg1("Conturi.txt", ios::app);
		reg1 << username_r << ' ' << parola_r << ' ' << banii << endl;
		cout << "Intregistrare completa";
		log_in();

	}

	void Client::modificareBanii(double banii_c)
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
				b = b + banii_c;
				banii = b;
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

	void Client::retragereBanii(double banii_c)
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
			  if (b < banii_c) {
					cout << "Fonduri insuficiente!\n";
					return;
				}
				b = b - banii_c;
				banii = b;
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