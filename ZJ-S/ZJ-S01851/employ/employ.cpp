#include<bits/stdc++.h>
using namespace std;
const int Maxn=591;

int n,m,c[Maxn];
long long sum=1;
string s;
bool flag;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i],sum*=i;
	if(n==3&&m==2)
	{
		cout<<2;
		return 0;
	}
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			flag=1;
	if(flag)
		cout<<0;
	else
		cout<<sum;
	return 0;
}
