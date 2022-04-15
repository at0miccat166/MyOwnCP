/*	
PROG: ride
LANG: C++ 
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MOD = 47;
using ll = long long;
using ull = unsigned long long;

// Functions here! 

// Main
int main(){
    ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	string s1, s2;
	fin >> s1 >> s2;
	long long p1 = 1, p2 = 1;
	for(int i = 0; i <= (int) s1.length()-1; i++){
		p1 *= (long long)(s1[i] - 'A' + 1);
	}
	for(int i = 0; i <= (int) s2.length()-1; i++){
		p2 *= (long long)(s2[i] - 'A' + 1);
	}
	if(p1 % MOD == p2 % MOD) fout << "GO" << "\n";
	else fout << "STAY" << "\n";

	return 0;
}
