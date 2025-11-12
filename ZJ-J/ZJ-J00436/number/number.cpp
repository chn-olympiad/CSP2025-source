#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
string s;
int len,a[10];
int main(){
	fre();
	cin>>s;
	len=s.size();
	for(int i=1;i<=len;++i)
		if('0'<=s[i-1]&&s[i-1]<='9')
			++a[s[i-1]-'0'];
	for(int i=9;i>=0;--i)
		while(a[i]--)
			cout<<i;
	return 0;
}
