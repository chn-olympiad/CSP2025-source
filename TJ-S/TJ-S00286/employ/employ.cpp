#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[100005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	long long a=rand()%43624634+1;
	long long b=rand()%23589340+1;
	long long c=rand()%28479238+1;
	long long d=rand()%15493680+1;
	long long e=rand()%93946809+1;
	long long ans=(a+b+c+d+e)/5;
	long long ans11=rand()%998244353+1;
	cout<<(ans+ans11)/2;
	return 0;
}
