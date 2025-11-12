#include<bits/stdc++.h>
using namespace std;
int a[2000010],t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++t]=int(s[i]-'0');
	}
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)cout<<a[i];
}
