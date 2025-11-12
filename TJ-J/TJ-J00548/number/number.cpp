#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000006],m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--)cout<<a[i];
	return 0;
} 
