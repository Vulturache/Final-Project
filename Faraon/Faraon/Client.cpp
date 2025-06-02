#include "Client.h"

Client::Client() {}
void Client::main_menu()
	{

		int alegere;
		cout << "\t\t ___________________________________FARAON___________________________________ \n\n\n";
		cout << "\t\tBine ati venit pe aplicatia noastra de banking, alegeti  optiunea dorita                 \n" << endl;
		cout << "\t\t\t                                                                                                                  \n\n\n";
		cout << "1.Interogare Sold" << endl;
		cout << "2.Retragere Numerar" << endl;
		cout << "4.Placeholder" << endl;
		cout << "5.Placeholder" << endl;
		cout << "6.Placeholder" << endl;
		cout << "7.DEBUG" << endl;
		cout << "8.Iesire" << endl;
		cout << "Optiunea: ";
		cin >> alegere;

		switch (alegere)
		{
		case 1:
		{
			cout << endl;
			cout << nume << "Sold-ul dumneavoastra este: " << banii << endl;
			cout << endl;
			system("PAUSE");
			main_menu();
			break;
		}
		case 2:
		{

		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6:
		{

		}
		case 7:
		{

		}
		case 8:
		{
			cout << "Multumim";
			exit;
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
			cout << "Multumim";
			exit;
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
		string username, parola, uid, pass;
		system("cls");
		cout << "Introduceti un Username si o Parola" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Parola: ";
		cin >> parola;

		fstream input("Conturi.txt");
		if (!input)
		{
			cout << "eroare la deschiderea fisierului";
		}
		else {
			while (input >> uid >> pass)
			{
				if (username == uid && pass == parola)
				{
					n = 1;
				}
				input.close();
			}
			if (n == 1)
			{
				cout << username << "\nAti fost loghat cu success";
				main_menu();
			}
			else
			{
				cout << "eroare de loghare";
				log();
			}
		}
		

	}
	void Client::reg()
	{
		string username_r, parola_r, uid_r, pass_r;
		system("cls");
		cout << "Alegeti un Username: ";
		cin >> username_r;
		cout << "Alegeti o Parola: ";
		cin >> parola_r;
		ofstream reg1("Conturi.txt", ios::app);
		reg1 << username_r << ' ' << parola_r << endl;
		cout << "Intregistrare completa";
		log_in();

	}