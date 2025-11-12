#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
string s;
char c[N];
ll n;bool f;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;n=s.size();
	for(ll i=0;i<n;i++) c[i+1]=s[i];
	sort(c+1,c+n+1,cmp);
	for(ll i=1;i<=n;i++)
		if(c[i]>='0'&&c[i]<='9') 
		{
			if(!f&&c[i]!='0') f=1;
			if(f) cout<<c[i]-'0';
		}
	return 0;
}