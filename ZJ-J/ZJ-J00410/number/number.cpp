#include<bits/stdc++.h>
using namespace std;
int i,j,f[66];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9') f[s[i]-'0']++;
	for(i=9;i>=0;i--)
		for(j=1;j<=f[i];j++)
			cout<<i;
	return 0;
}

