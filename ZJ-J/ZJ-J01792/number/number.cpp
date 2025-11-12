#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,f[20];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			f[s[i]-48]++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=f[i];j++)	
			cout<<i;
}
/*
*/