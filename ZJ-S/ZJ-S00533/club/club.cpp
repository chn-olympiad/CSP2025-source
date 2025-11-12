#include<bits/stdc++.h>
using namespace std;
long long n,t,ans=0;
long long a[100015][6];
long long b[4][100015],maxn,s;
bool cmp(long long x,long long y)
{
	return a[x][5]>a[y][5];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;b[1][0]=b[2][0]=b[3][0]=0;
		cin>>n;
		for(long long i=1;i<=n;i++)
		{
			b[1][i]=b[2][i]=b[3][i]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxn=max(max(a[i][1],a[i][2]),a[i][3]);
			if(maxn==a[i][1])
			{
				a[i][0]=1;
				if(a[i][2]>=a[i][3]) a[i][4]=2;
				else a[i][4]=3;
			}
			else if(maxn==a[i][2])
			{
				a[i][0]=2;
				if(a[i][1]>=a[i][3]) a[i][4]=1;
				else a[i][4]=3;
			}
			else if(maxn==a[i][3])
			{
				a[i][0]=3;
				if(a[i][2]>=a[i][1]) a[i][4]=2;
				else a[i][4]=1;
			}
			a[i][5]=a[i][a[i][0]]-a[i][a[i][4]];
		}
		if(n>=1000)
		{
			long long flag=0;
			for(long long i=1;i<=n;i++) if(a[i][2]) flag=1;
			if(!flag)
			{
				for(long long i=1;i<=n;i++) 
					b[1][i]=a[i][1];
				sort(b[1]+1,b[1]+n+1);
				for(long long i=n;i*2>=n+2;i--) ans+=b[1][i];
			}
			else
			{
				long long i;
				for(i=1;i<=n;i++) a[i][5]=a[i][1]-a[i][2],b[1][i]=i;
				sort(b[1]+1,b[1]+n+1,cmp);
				for(i=1;i<=n/2;i++) ans+=a[b[1][i]][1];
				for(i=n/2+1;i<=n;i++) ans+=a[b[1][i]][2];
			}
			cout<<ans<<endl;continue;
		}
		for(long long i=1;i<=n;i++)
		{
			s=a[i][0];
			if(!(b[s][0]+1>n/2))
			{
				b[s][0]++;ans+=a[i][s];
				b[s][b[s][0]]=i;
				sort(b[s]+1,b[s]+b[s][0]+1,cmp);
			}
			else 
			{
				long long minn=b[s][b[s][0]];
				if(a[i][a[i][0]] + a[minn][a[minn][4]]
				>
				a[minn][a[minn][0]] + a[i][a[i][4]] )
				{
					ans+=a[i][a[i][0]] - a[minn][a[minn][0]]
						+ a[minn][a[minn][4]] ;
					b[a[minn][4]][0]++;
					b[s][b[s][0]]=i;
					b[a[minn][4]][b[a[minn][4]][0]]=minn;
					sort(b[s]+1,b[s]+b[s][0]+1,cmp);
				}
				else
				{
					s=a[i][4];
					b[s][0]++;ans+=a[i][s];
					b[s][b[s][0]]=i;
					sort(b[s]+1,b[s]+b[s][0]+1,cmp);
				} 
			}
			/*for(long long i=1;i<=3;i++)
			{
				for(long long j=0;j<=n;j++) cout<<b[i][j]<<" ";
				cout<<endl;
			}*/	
		}
		cout<<ans<<endl;
	/*	for(long long i=1;i<=3;i++)
		{
			for(long long j=0;j<=n;j++) cout<<b[i][j]<<" ";
			cout<<endl;
		}*/
	}
	return 0;
}
