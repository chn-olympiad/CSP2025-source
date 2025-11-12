#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin >>s;
	int cnt = 0;
	int n = s.length();
	vector<int>a(n);
	for(int i = 0;i < n;i++){
		if('0' <= s[i] && s[i] <= '9')a[cnt++] = s[i]-'0';
		
	}
	vector<int>b(cnt);
	for(int i = 0;i < cnt;i++)b[i] = a[i]; 
	sort(b.begin(),b.end());
	for(int i = cnt-1;i >= 0;i--)
		cout << b[i];
	return 0;
}
