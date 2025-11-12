#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
template<typename T>inline void read(T &x)
{
	bool f=1;x=0;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=!f;ch=getchar();}
	while(ch>='0' && ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=(f?x:-x);return ;
}
int t,n;
int a[N][4];
int dp[N][4],sum[N][4][4];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q[4];
void init()
{
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=3;i++)
		while(!q[i].empty())	q[i].pop();
}
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)	read(a[i][1]),read(a[i][2]),read(a[i][3]);
		init();
		for(int i=1;i<=n;i++){
			int maxx=-1,mk;
			for(int j=1;j<=3;j++)			
				if(dp[i-1][j]>maxx)	maxx=dp[i-1][j],mk=j;
			if(i>1)	q[mk].push({a[i-1][mk],i});
			for(int j=1;j<=3;j++){
				if(sum[i-1][mk][j]<n/2){
					dp[i][j]=dp[i-1][mk]+a[i][j];
					for(int u=1;u<=3;u++){
						if(u==j)	sum[i][j][u]=sum[i-1][mk][u]+1;
						else	sum[i][j][u]=sum[i-1][mk][u];
					}
				}
				else{
					if(!q[j].empty()){
						int maxn=-1,mark;
						for(int u=1;u<=3;u++){
							if(u==mk)	continue;
							if(a[q[j].top().second][u]>maxn)	maxn=dp[q[j].top().second][u],mark=u;
						}
						if(a[i][j]+a[q[j].top().second][mark]>q[j].top().first){
							dp[i][j]=dp[i-1][mk]-q[j].top().first+a[i][j]+a[q[j].top().second][mark];
							q[mark].push({a[q[j].top().second][mark],q[j].top().second});
							for(int u=1;u<=3;u++){
								if(u==mark)	sum[i][j][u]=sum[i-1][mk][u]+1;
								else	sum[i][j][u]=sum[i-1][mk][u];
							}
							q[j].pop();
							q[j].push({a[i][j],i});
						}
						else{
							dp[i][j]=dp[i-1][mk];
							for(int u=1;u<=3;u++)	sum[i][j][u]=sum[i-1][mk][u];
						}
					}
					else{
						q[j].push({a[i][j],i});
						dp[i][j]=dp[i-1][mk]+a[i][j];
						for(int u=1;u<=3;u++){
							if(u==j)	sum[i][j][u]=sum[i-1][mk][u]+1;
							else	sum[i][j][u]=sum[i-1][mk][u];
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int u=1;u<=3;u++)
					cout<<sum[i][j][u]<<' ';
				cout<<"              ";
			}
			cout<<endl;
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	return 0;
}
/*
1
6
1 0 0
10 0 0
10 0 0
10 0 0
2 0 0
5 0 0
*/