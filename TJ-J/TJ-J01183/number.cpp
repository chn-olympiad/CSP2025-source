#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e6 + 5;
ll n,m,num = 1;
char a[maxn],b[maxn];
string s;
//int cmp(int a,int b){
//	return a > b;
//}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 1;i <= s.size();i++){
		if("0" <= s[i] + " "){
			if(s[i] + " " <= "9"){
				a[num] = s[i]; 
				cout << s[i];
				num ++;
			}
		}
	}
	char mx = s[1],um = 2;
	for(int j = 1;j <= s.size();j++){
		for(int i = um;i <= s.size();i++){
			if(s[i] > mx){
				mx = s[i];
				s[i] = 0;
			}
		}
		s[j] = mx;
		um ++;
		mx = s[um - 1];
	}
	cout << s;
	return 0; 
}
