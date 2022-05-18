/*
1) Дан текст и подстрока - IP-адрес по формату v6. 
Определить, сколько раз упомянут этот IP-адрес в 
исходном тексте.
Кнута-МорисаПратта
2) В тексте найти все строки со значением IP-адреса 
по формату v6 и заменить его элементы числами в 16-
тиричной системе счисления.
*/

#include <iostream>
#include <string>
#include <vector> 
#include <regex>
using namespace std;

vector<int> prefix_function(const string& s) {
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];

		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];

		if (s[i] == s[j]) 
			pi[i] = j + 1;
		else
			pi[i] = j;
	}
	return pi;
} 
vector<string> delitel(string num) 
{
	string delim = ":";   
	size_t pos = 0;
	size_t base_str_size = num.size();
	size_t delim_size = delim.size();
	string temp;
	vector<string> arr;
	while (pos < base_str_size) {
		temp = temp.assign(num, pos, num.find(delim, pos) - pos);
		if (temp.size() > 0)
			arr.push_back(temp);
		pos += temp.size() + delim_size;
	}
	return arr;
}
string FromDec(int number) 
{
	string answer;
	while (number > 0) 
	{
		if (number % 16 > 9) 
		{
			switch (number % 16) {
				case 10:
					answer = "A" + answer;
					break;
				case 11:
					answer = "B" + answer;
					break;
				case 12:
					answer = "C" + answer;
					break;
				case 13:
					answer = "D" + answer;
					break;
				case 14:
					answer = "E" + answer;
					break;
				case 15:
					answer = "F" + answer;
					break;
			}
		}
		else
			answer = to_string(number % 16) + answer;
		number /= 16;
	}
	if (answer.length() == 0) answer = "0";
	return answer;
}

string perevod(vector<string> arr)
{
	vector<string> perevod_arr;
	string perevod_stroke = "";
	for (int i = 0; i < arr.size(); i++) 
	{
		int current = stoi(arr[i]);
		perevod_arr.push_back(FromDec(current));
	}
	for (int i = 0; i < perevod_arr.size() - 1; i++)
	{
		perevod_stroke += perevod_arr[i] + ":";
	}
	perevod_stroke += perevod_arr[perevod_arr.size() - 1];
	return perevod_stroke;
}



int main() {
	setlocale(LC_ALL,"Ru");
	string text = "Рассмотрим для примера адрес: 9735:63664:1693:2069:0:0:0:8206. "
		"В нем первые три поля в адресе протокола IPv6 указывают на префикс сайта — 21DA:7654:DE12. "
		"Глобальный префикс указывает в сети какого провайдера находится данный адрес. Четвертое поле — 2F3B — идентификатор подсети.\n"
		"9735:63664:1693:2069:0:0:0:8206 \n"
		"Оставшиеся 4 поля — 02AA:EF98:FE28:9C5A — идентификатор интерфейса — аналогичен Host ID в IPv4 и определяет уникальный адрес хоста вашей сети.";
	string pattern = "9735:63664:1693:2069:0:0:0:8206";
	vector<int> pi = prefix_function(pattern + '#' + text);

	int pattern_len = pattern.length();
	int count = 0;
	
	for (int i = 0; i < text.length(); i++)
		if (pi[pattern_len + 1 + i] == pattern_len)
			count++;
	cout << "Количество совпадений: " << count << endl;
	regex ipv6("((([0-9a-fA-F]){1,5})\\:){7}([0-9a-fA-F]){1,5}");
	smatch match;
	string result = text;
	size_t pos = 0;
	while (regex_search(text, match, ipv6)) {
		string ip = match[0];
		text = match.suffix();
		string ip_perevod = perevod(delitel(ip));
		while ((pos = result.find(ip, pos)) != string::npos)
		{
			result.replace(pos, ip.size(), ip_perevod);
			pos += ip_perevod.size();
		}
	}

	cout << result;
	return 0;
}
