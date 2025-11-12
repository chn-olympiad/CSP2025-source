#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int t,n,ex; 
int b[N+10][3];
int js[N+10];
int f[N+10];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		for(int i=1;i<=3;i++) js[i]=n/2;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>b[i][j];
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
			{
				if(js[j]>0)
				{
					f[i]=max(f[i],f[i-1]+b[i][j]); 
					ex=j;
				}
			}
			js[ex]--;
		}
		cout<<f[n]<<endl;
	}

	return 0;
}
