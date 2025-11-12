#include<bits/stdc++.h>
using namespace std;
char s[50005];
int n,m;
int c[50005];
int flag[500];
long long ans=1;
const int modd=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int flag1=0,flag2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];	
		if(s[i]!='1')
		{
			flag1=1;
		}
		if(s[i]=='1')
		{
			flag2++;
		}		
	}
	int ci=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]>=ci)
		{
			n--;
			ci++;
		} 
	}
//	cout<<n<<endl;
	if(flag1==0)
	{	
	//	cout<<n<<"    "<<m<<endl;	
		int k=n;
		for(int i=1;i<=m;i++)
		{
			ans=(ans*k)%modd;
		//	cout<<k<<"              "<<ans<<endl;	
			k--;
		}
		for(int i=1;i<=m;i++)
		{
			ans=(ans/i)%modd;
		//	cout<<ans<<endl;
			
		}
		cout<<ans;
		return 0;
	}
		if(flag2<m)
	{
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;

}