/*
	TASK : friday
	LANG : C++
*/
#include "bits/stdc++.h"

using namespace std;

int day[9];

	map<int, int> months= {{1, 31}, {2, 28}, {3, 31}, {4, 30}, 
		{5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30},
		{10, 31}, {11, 30}, {12, 31}};


bool isLeap(int year){
        if(year % 100 ==0)
                return year % 400 ==0;
        else
                return year % 4 ==0;
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	ifstream fin ("friday.in");
	ofstream fout ("friday.out");

	int n; fin >> n;
	int start = 1900, end = 1900 + n;
	int f_m = 1;
	int range = 12;
	int date = 2;
	while (start < end){
		date = (date + range % 7);
		if(date > 8) date -= 7;
		// fout << date << " " << range << " " << f_m << "\n";
		if(date == 0) day[date + 8]++;
		day[date]++;
		range = months[f_m];
		if(f_m == 2){
			if(isLeap(start)) range++;
		}
		f_m++;
		if(f_m == 13){
			f_m = 1;
			start++;
		}
	}


	fout << day[7] << " " << day[8] << " ";
	for(int i = 2; i <= 6; i++){
		if(i == 6){
			fout << day[i] << "\n";
			break;
		}
		fout << day[i] << " ";
	}
	return 0;
}
