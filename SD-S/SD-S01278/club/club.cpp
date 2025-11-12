#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][4];
int c[4],px[4];
int b[3000005];
priority_queue<pair<int,int>,vector<pair<int,int> > >to[4][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long ans=0;
		int cnt=1;
		int ca=n/2;
		for(int i=1;i<3000003;i++)	b[i]=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				while(to[i][j].size())	to[i][j].pop();
		c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++)	scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++){
			int minn=0x7fffffff,maxx=-1;
			int umax,umin,umid;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxx){
					maxx=a[i][j];
					umax=j;
				}
				if(a[i][j]<=minn){
					minn=a[i][j];
					umin=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=umax&&j!=umin){
					umid=j;
					break;
				}
			}
			if(c[umax]==ca){
				int maxs,us,wer;
				while(b[to[umax][umid].top().second])	to[umax][umid].pop();
				while(b[to[umax][umin].top().second])	to[umax][umin].pop();
				if(to[umax][umid].top().first>to[umax][umin].top().first){
					maxs=to[umax][umid].top().first;
					us=to[umax][umid].top().second;
					wer=umid;
				}
				else{
					maxs=to[umax][umin].top().first;
					us=to[umax][umin].top().second;
					wer=umin;
				}
				if(maxs+a[i][umax]>a[i][umid]){
					b[us]=1;
					ans+=maxs+a[i][umax];
					c[wer]++;
					to[umax][umid].push(make_pair(a[i][umid]-a[i][umax],cnt++));
					to[umax][umin].push(make_pair(-0x3f3f3f3f,cnt));
				}
				else{
					ans+=a[i][umid];
					c[umid]++;
					to[umid][umin].push(make_pair(-0x3f3f3f3f,cnt++));
				}
			}
			else{
				c[umax]++;
				ans+=a[i][umax];
				to[umax][umid].push(make_pair(a[i][umid]-a[i][umax],cnt++));
				to[umax][umin].push(make_pair(-0x3f3f3f3f,cnt));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
