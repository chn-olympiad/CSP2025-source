#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,c,sum=1;
string s;
bool f=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) 
    {
    	cin>>c;
    	if(c>m) ans++;
	}
	for(int i=1;i<=ans;i++)
	{
		sum*=i;
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
