#include<bits/stdc++.h> 
using namespace std;
int a[110000][4];
int maxn[110000][6];
int midd[110000][6];
int c1[110000][6];
int cz[50000][6];
int num[50000][4];
int _max[4];
int _mid[4];
bool pd[4][50000];
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		memset(_max,0,sizeof(_max));
		memset(_mid,0,sizeof(_mid));
		memset(cz,0,sizeof(cz));
		memset(c1,0,sizeof(c1));
		memset(num,0,sizeof(num));
		int n,_c1=100000,_c2=100000;
		ans=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&a[j][1],&a[j][2],&a[j][3]);
			if(a[j][1]>=a[j][2])
			{
				if(a[j][2]>=a[j][3])
				{
					maxn[j][k]=1;
					midd[j][k]=2;
//					minn[j][k]=3;
					_max[maxn[j][k]]++;
					_mid[midd[j][k]]++;
//					_min[minn[j][k]]++;
				}
				else
				{
					if(a[j][1]>=a[j][3])
					{
						maxn[j][k]=1;
						midd[j][k]=3;
//						minn[j][k]=2;
						_max[maxn[j][k]]++;
						_mid[midd[j][k]]++;
//						_min[minn[j][k]]++;
					}
					else
					{
						maxn[j][k]=3;
						midd[j][k]=1;
//						minn[j][k]=2;
						_max[maxn[j][k]]++;
						_mid[midd[j][k]]++;
//						_min[minn[j][k]]++;
					}
				}
			}
			else
			{
				if(a[j][1]>=a[j][3])
				{
					maxn[j][k]=2;
					midd[j][k]=1;
//					minn[j][k]=3;
					_max[maxn[j][k]]++;
					_mid[midd[j][k]]++;
//					_min[minn[j][k]]++;			
				}
				else
				{
					if(a[j][2]>=a[j][3])
					{
						maxn[j][k]=2;
						midd[j][k]=3;
//						minn[j][k]=1;
						_max[maxn[j][k]]++;
						_mid[midd[j][k]]++;
//						_min[minn[j][k]]++;
					}
					else
					{
						maxn[j][k]=3;
						midd[j][k]=2;
//						minn[j][k]=1;
						_max[maxn[j][k]]++;
						_mid[midd[j][k]]++;
//						_min[minn[j][k]]++;
					}
				}
			}
			pd[maxn[j][k]][a[j][maxn[j][k]]-a[j][midd[j][k]]]=1;
//			cout<<maxn[j][k]<<" "<<j<<" ";
			c1[j][k]=a[j][maxn[j][k]]-a[j][midd[j][k]];
			num[a[j][maxn[j][k]]-a[j][midd[j][k]]][maxn[j][k]]++;
			cz[a[j][maxn[j][k]]-a[j][midd[j][k]]][k]=j;
			_c1=min(_c1,c1[j][k]);
//			c2[j][k]=a[j][midd[j][k]]-a[j][minn[j][k]];
//			cz[a[j][midd[j][k]]-a[j][minn[j][k]]][2][k]=j;
//			_c2=min(_c2,c2[j][k]);
			ans+=a[j][maxn[j][k]];	
		}
		int d=0;
		for(int i=1;i<=3;i++)
		{
			if(_max[i]>n/2)
			{
				d=i;
			}
		}
//		cout<<d<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			cout<<maxn[i][k]<<" "<<midd[i][k]<<" "<<c1[i][k]<<" "<<num[i]<<endl;		
//		}
//		cout<<_max[1]<<" "<<_max[2]<<" "<<_max[3]<<endl;
//		cout<<_mid[1]<<" "<<_mid[2]<<" "<<_mid[3]<<endl;
		if(d!=0)
		{
			for(int i=_c1;_max[d]>n/2;i++)
			{					
//			cout<<cz[i][k]<<" "<<pd[d][cz[i][k]]<<" "<<num[i][d];
				if(cz[i][k]!=0&&pd[d][i]==1&&num[i][d]>0)
				{
//					cout<<" max"<<_max[d]<<"ans"<<ans<<endl;
					ans-=c1[cz[i][k]][k];
					_max[d]--;
					num[i][d]--;
					i--;

				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
