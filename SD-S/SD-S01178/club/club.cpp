#include<bits/stdc++.h>
using namespace std;
struct cll
{
	int w;
	int r;
};
int nn,k,a[4][100005],f[4]={0,0,0,0},s[100005];
cll t[100005];
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>nn;
	while(nn--)
	{
		memset(t,0,sizeof(t));
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(f,0,sizeof(f));
		ans=0;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int mmax=-1,mmin=0x3f3f3f3f,m1=0,m2=0;
			for(int j=1;j<=3;j++)
			{
				cin>>a[j][i];
				if(a[j][i]>mmax)
				{
					mmax=a[j][i];
					m1=j;
				}
				if(a[j][i]<=mmin)
				{
					mmin=a[j][i];
					m2=j;
				}
			}
			for(int j=1;j<=3;j++)
			{
				if(j==m1||j==m2) continue;
				else 
				{
					t[i].w=mmax-a[j][i];
					t[i].r=j;
				}
			}
			ans+=mmax;
			f[m1]++;
		}
		for(int i=1;i<=3;i++)
		{
			if(f[i]>k/2)
			{
				for(int j=1;j<=k;j++)
				{
					if(t[j].r!=i) s[t[j].w]++;
				}
				int ff=f[i]-k/2;
				for(int j=1;j<=20005;j++)
				{
					while(s[j]>0&&ff>0) 
					{
						ans-=j;
						s[j]--;
						ff--;
					}
					if(ff<=0) break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

