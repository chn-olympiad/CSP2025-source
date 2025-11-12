#include <bits/stdc++.h>
using namespace std;
string s;
int a[10],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	s=" "+s;
	for(int i = 1;i <= len;i++){
		if(s[i]-'0'<=9)a[s[i]-'0']++;
	}
	for(int i = 9;i >= 0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
2 2
99 100 97 98
*/
