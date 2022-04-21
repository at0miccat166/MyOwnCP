/*	
 * 	author: Hiu 
 *  Handle: at0miccat
 */
#include "bits/stdc++.h"

using namespace std;


string add(string a, string b){
  while(a.length() < b.length()) a= '0' +a;
  while(b.length() < a.length()) b= '0' +b;
  string ans="";
  int carry= 0;
  for(int i= a.length()-1; i>=0; i--){
    int sum= (a[i]-'0' + b[i] -'0') + carry;
    carry= 0;
    ans= char(sum%10 +'0') + ans;
    carry+= sum/10;
  }
  if(carry > 0) ans= '1' + ans;
  while(ans[0] == '0' && ans.length() > 1) ans.erase(0,1);
  return ans;
}

string sub(string a, string b){
  while(a.length() < b.length()) a= '0' +a;
  while(b.length() < a.length()) b= '0' +b;
  string big="";
  string sml="";
  if(a > b){
    big+=a;
    sml+= b;
  }
  else {
    big+= b;
    sml+= a;
  }
  string ans="";
  int borrow= 0;
  for(int i= big.length()-1; i>=0; i--){
      int dif= (big[i] - sml[i]) - borrow;
      if(dif < 0){
        dif+= 10;
        borrow = 1;
      }
      else borrow = 0;
      ans= char(dif+'0') + ans;
  }
  while(ans[0] == '0' && ans.length() > 1) ans.erase(0,1);
  if(a < b) ans= '-'+ ans;
  return ans;
}

string multi(string a, string b){
  string res = "", tmp;
  int m = -1;
  for(int i = a.length() - 1; i >= 0; i--){
    m++;
    tmp = "";
    for(int j = 0; j <= (a[i]-'0') - 1; j++) tmp = add(tmp,b);
    for(int j = 0; j <= m-1; j++) tmp += '0';
      res = add(tmp, res);
  }
  while (res[0] == '0' && res.length() > 1) res.erase(0, 1);
  return res;
}

int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	cout << add(a, b) << "\n";
	cout << sub(a, b) << "\n";
	if (a == "0" || b == "0") cout << 0;
	else cout << multi(a, b) << "\n";
	return 0;
}
