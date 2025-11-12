#include<bits/stdc++.h>
using namespace std;
unsigned long long int i,j,k,n,m,c[1000005],fang,ans,t,e=0;
string s;
char p[100005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(i=1;i<=n;i++)
	{
		scanf("%ulld",&c[i]); 
		p[i]=i+48;
		e*=i;
	}
	cout<<e%998244353;
	return 0;
}
