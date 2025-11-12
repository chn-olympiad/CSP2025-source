#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],ans;
bool ui[501];
string s;
void emp(bool q[501],int fq,int d,int tg)
{
	if(n-fq<m-tg)
	{	
	}
	else{
	for(int i=1;i<=n;i++)
	{
		if(c[i]<=fq)
		{
			fq++;
			q[i]=1;
		}
	}
	int uuz=0;
	for(int i=1;i<=n;i++)
	{
		if(q[i]==0)
		{
			uuz=1;
			q[i]=1;
			if(s[d]=='0')
			{
				emp(q,fq+1,d+1,tg);
			}
			else
			{
				emp(q,fq,d+1,tg+1);
			}
		}
	}
	if(uuz==0 ||d==n+1)
	{
		if(tg>=m)
	    {
		ans++;
		ans%=998244353;
	    }
	}
}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	emp(ui,0,1,0);
	cout<<ans;
	return 0;
}
