#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <conio.h>

const int SIZE = 5;
int LIMIT[SIZE] = { 60, 24, 30, 11, 10000};

using namespace std;

class Time {
public:
	string h, m, dd, mm, yy;
	Time() {
		h = "00"; m = "00"; dd = "00"; mm = "00"; yy = "0000";
	}
	Time(const string & h_0, const string & m_0, const string & dd_0, const string & mm_0, const string & yy_0) {
		h = h_0; m = m_0; dd = dd_0; mm = mm_0; yy = yy_0;
	}
	void show() {
		cout << h << ":" << m << " " << dd << "/" << mm << "/" << yy << endl;;
	}
};

class TimeInterval {
public:
	string h, m, dd, mm, yy;
	TimeInterval() {
		h = "00"; m = "00"; dd = "00"; mm = "00"; yy = "0000";
	}
	TimeInterval(const string & h_0, const string & m_0, const string & dd_0, const string & mm_0, const string & yy_0) {
		h = h_0; m = m_0; dd = dd_0; mm = mm_0; yy = yy_0;
	}
	void show() {
		cout << h << " hours, " << m << " minutes, " << dd << " days, " << mm << " months, " << yy << " years" << endl;;
	}
};

Time operator+(Time & t, TimeInterval & ti) {
	int m = 0;
	string result[SIZE];
	//int  M = stoi(t.m) + stoi(ti.m), H = stoi(t.h) + stoi(ti.h), MM = stoi(t.mm) + stoi(ti.mm), DD = stoi(t.dd) + stoi(ti.dd), YY = stoi(t.yy) + stoi(ti.yy);
	int time[SIZE]= {stoi(t.m) + stoi(ti.m), stoi(t.h) + stoi(ti.h), stoi(t.dd) + stoi(ti.dd), stoi(t.mm) + stoi(ti.mm), stoi(t.yy) + stoi(ti.yy)};
	for (int i = 0; i < SIZE - 1; i++) {
		if (time[i] >= LIMIT[i]) {
			m = time[i] / LIMIT[i];
			time[i+1] = time[i+1] + m;
			time[i] -= m * time[i];
			if (i == 2 || i == 3)
				time[i]++;
			if (time[i] < 10)
				result[i] = "0" + to_string(time[i]);
			else
				result[i] = to_string(time[i]);
		}
		if (time[i] < 10)
			if (time[i] == 0)
				result[i] = "00";
			else
				result[i] = "0" + to_string(time[i]);
		else
			result[i] = to_string(time[i]);
	}
	if (time[4] >= LIMIT[4])
	{
		m = time[4] / LIMIT[4];
		time[4] -= m * time[4];
	}
	if (time[4] == 0)
		result[4] = "0000";
	else if (time[4] < 10)
		result[4] = "0" + to_string(time[4]);
	else if (time[4] < 100)
		result[4] = "00" + to_string(time[4]);
	else if (time[4] < 1000)
		result[4] = "000" + to_string(time[4]);
	else
		result[4] = to_string(time[4]);
	Time t1(result[1], result[0], result[2], result[3], result[4]);
	return t1;
}

int main() {
	Time t1("00", "00", "00", "00", "2019");
	TimeInterval ti1("00", "00", "00", "00", "0000");
	Time t2;
	t2 = t1 + ti1;
	t2.show();
	_getch();
	return 0;
}