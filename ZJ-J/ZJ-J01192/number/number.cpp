#include<bits/stdc++.h>
using namespace std;

int s[1000010] = {0};

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	int cnt = 0;
	cin >> a;
	int lena = a.length();
	for(int i = 0; i < lena; i++){
		if((a[i]-'0')>=0&&(a[i]-'0')<=9){
			s[cnt] = a[i]-'0';
			cnt++;
		}
	}
	sort(s,s+cnt);
	for(int i = cnt-1; i >= 0; i--){
		cout << s[i];
	}
	return 0;
}
