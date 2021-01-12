#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

void server_selection();
void save(int& t, std::string &s, std::string &title);
void file_support(int& t, std::string& s, std::string& title);

int main() {

	std::string x, s, title;
	int t;
	int w = 0;

	file_support(t, s, title);

	std::stringstream ss;
	ss << "netsh advfirewall firewall add rule name = lolchat dir = out remoteip = " << s << " protocol = TCP action = block";
	std::string stmp = ss.str();

	const char* command = stmp.c_str();

	while (w == 0)
	{
		system("cls");
		std::cout << "********************" << std::endl;
		std::cout << "* LoL Chat Blocker *" << std::endl;
		std::cout << "********************" << std::endl;
		std::cout << "Do you want to block (b) or unlock (u) LoL [" << title << " - server] chat ?" << std::endl << "You can also change server (c)." << std::endl;
		std::cout << std::endl << "What is your option (b/u/c) ?: ";
		std::cin >> x;
		
		if (x == "b" || x == "B")
		{
			system(command);
			Sleep(10);
			system("cls");
			std::cout << "LoL Chat is Offline now." << std::endl;
			Sleep(800);
			break;
		}
		if (x == "u" || x == "U")
		{
			system("netsh advfirewall firewall delete rule name = lolchat");
			Sleep(500);
			system("cls");
			std::cout << "LoL Chat is Online now." << std::endl;
			Sleep(800);
			break;
		}
		if (x == "c" || x == "C")
		{
			system("del lolchat_save /A S H");
			file_support(t, s, title);
		}
		else
		{
			std::cout << "No valid option selected.";
			Sleep(500);
		}
	}
}

void file_support(int& t, std::string& s, std::string& title) {
	std::ifstream file("lolchat_save");
	if (!file) {
		server_selection();
		std::cin >> t;
		std::ofstream file("lolchat_save");
		file << t;
		file.close();
		system("attrib +s +h lolchat_save");
		save(t, s, title);

	}
	else {
		file >> t;
		save(t, s, title);
	}
}

void save(int &t, std::string &s, std::string& title) {
	
	switch (t) {
	case 0:
		s = "172.65.223.136"; //eun1.chat.si.riotgames.com
		title = "EUNE";
		break;
	case 1:
		s = "172.65.252.238"; //euw1.chat.si.riotgames.com
		title = "EUW";
		break;
	case 2:
		s = "172.65.244.155"; //na2.chat.si.riotgames.com
		title = "NA";
		break;
	case 3:
		s = "172.65.192.156"; //ru1.chat.si.riotgames.com
		title = "RU";
	case 4:
		s = "172.65.202.166"; //tr1.chat.si.riotgames.com
		title = "TR";
		break;
	case 5:
		s = "172.65.250.49"; //la1.chat.si.riotgames.com
		title = "LAN";
		break;
	case 6:
		s = "172.65.194.233"; //la2.chat.si.riotgames.com
		title = "LAS";
		break;
	case 7:
		s = "172.65.208.61"; //oc1.chat.si.riotgames.com
		title = "OC";
		break;
	case 8:
		s = "172.65.217.212"; //jp1.chat.si.riotgames.com
		title = "JP";
		break;
	case 9:
		s = "172.65.212.1"; //br.chat.si.riotgames.com
		title = "BR";
		break;
	}
}

void server_selection() {
	system("cls");
	std::cout << "Select LoL server: " << std::endl;
	std::cout << "0. EUNE" << std::endl << "1. EUW" << std::endl << "2. NA" << std::endl << "3. RU" << std::endl << "4. TR" << std::endl;
	std::cout << "5. LAN" << std::endl << "6. LAS" << std::endl << "7. OCE" << std::endl << "8. JP" << std::endl << "9. BR" << std::endl;
	std::cout << "Server: ";
}