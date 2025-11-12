#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int M=1e3+10;
const int P=998244353;
int a,b,c;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n=0;
		cin>>n;
		int ans=0;
		int numa=0,numb=0,numc=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a>>b>>c;
			if(a>=b)
			{
				if(b>=c)
				{
					if(numa+1<=n/2)
					{
						numa+=1;
						ans+=a;
						continue;
					}
					else if(numb+1<=n/2)
					{
						numb+=1;
						ans+=b;
						continue;
					}
					else if(numc+1<=n/2)
					{
						numc+=1;
						ans+=c;
						continue;
					}
				}
				else 
				{
					if(a>=c)
					{
						if(numa+1<=n/2)
						{
							numa+=1;
							ans+=a;
							continue;
						}
						else if(numc+1<=n/2)
						{
							numc+=1;
							ans+=c; 
							continue;
						}
						else if(numb+1<=n/2)
						{
							numb+=1;
							ans+=b;
							continue;
						}
					}
					else
					{
						if(numc+1<=n/2)
						{
							numc+=1;
							ans+=c;
							continue;
						}
						else if(numa+1<=n/2)
						{
							numa+=1;
							ans+=a; 
							continue;
						}
						else if(numb+1<=n/2)
						{
							numb+=1;
							ans+=b;
							continue;
						}
					}
				}
			}
			else
			{
				if(b<c)
				{
					if(numc+1<=n/2)
					{
						numc+=1;
						ans+=c;
						continue;
					}
					else if(numb+1<=n/2)
					{
						numb+=1;
						ans+=b; 
						continue;
					}
					else if(numa+1<=n/2)
					{
						numa+=1;
						ans+=a;
						continue;
					}
				}
				else
				{
					if(c>=a)
					{
						if(numb+1<=n/2)
						{
							numb+=1;
							ans+=b;
							continue;
						}
						else if(numc+1<=n/2)
						{
							numc+=1;
							ans+=c; 
							continue;
						}
						else if(numa+1<=n/2)
						{
							numa+=1;
							ans+=a;
							continue;
						}
					}
					else
					{
						if(numb+1<=n/2)
						{
							numb+=1;
							ans+=b;
							continue;
						}
						else if(numa+1<=n/2)
						{
							numa+=1;
							ans+=a; 
							continue;
						}
						else if(numc+1<=n/2)
						{
							numc+=1;
							ans+=c;
							continue;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;//Ren5Jie4Di4Ling5%
}
