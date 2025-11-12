#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define L(i,j,k) for(int i=(j);i<=(k);i++)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
int kkk;
int n,maxx,minn,ans;
const int Mxn=100100;
int cnt[5],cntt[5];
int anc=0,t,k;
bool vis[Mxn],ka,kb;
priority_queue <int> pq;
int ca[Mxn],cb[Mxn],cc[Mxn];
int cca[Mxn],ccb[Mxn],ccc[Mxn];
int a[Mxn][5];//第i个人对于j的满意度
void dfs(int d) {
	//cout<<d;
	if(d>n) {
		ans=Max(ans,anc);
//		cout<<cnt[1]<<cnt[2]<<cnt[3]<<endl;
		return;
	}
	if(vis[d])return;
	L(i,1,3) {
		if(cnt[i]>=maxx)continue;
		cnt[i]++;
		vis[d]=true;
		anc+=a[d][i];
		dfs(d+1);
		anc-=a[d][i];
		cnt[i]--;
		vis[d]=false;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&kkk);
	while(kkk--) {
//		cout<<kkk<<":";
		ka=true;
		kb=true;
		ans=0;
		scanf("%d",&n);
		maxx=n/2;
		cnt[1]=cnt[2]=cnt[3]=0;
		L(i,1,n) {
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0)ka=false;
			if(a[i][3]!=0)kb=false;
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])cnt[1]++,ans+=a[i][1];
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])cnt[2]++,ans+=a[i][2];
			if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])cnt[3]++,ans+=a[i][3];
			ca[i]=a[i][1]-a[i][2];
			cb[i]=a[i][2]-a[i][3];
			cc[i]=a[i][1]-a[i][3];
			cca[i]=a[i][2]-a[i][1];
			ccb[i]=a[i][3]-a[i][2];
			ccc[i]=a[i][3]-a[i][1];
		}
//		cout<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
		t=ans;
		if(cntt[1]<=maxx&&cntt[2]<=maxx&&cntt[3]<=maxx) {
			printf("%d\n",ans);
			continue;
		}
		if(ka) {
			ans=0;
			while(pq.size()>0)pq.pop();
			L(i,1,n)pq.push(a[i][1]);
			L(i,1,maxx) {
				ans+=pq.top();
				pq.pop();
			}
			printf("%d\n",ans);
			continue;
		}
		if(n<=10) {
			memset(vis,false,sizeof(vis));
			memset(cntt,0,sizeof(cnt));
			anc=0;
			dfs(1);
			printf("%d\n",ans);
			continue;
		}
		ans=t;
		memset(vis,false,sizeof(vis));
		
		
		
		
		if(cnt[1]>maxx){
			t=cnt[1]-maxx;
			while(t--){
				minn=1e9;
				k=0;
				L(i,1,n){
					if(vis[i])continue;
					if(Max(ca[i],cca[i])<minn||Max(cc[i],ccc[i])<minn){
						if(cnt[2]<maxx&&cnt[3]<maxx){
							if(Max(ca[i],cca[i])<Max(cc[i],ccc[i])){
								cnt[2]++;
								minn=Max(ca[i],cca[i]);
								k=i;
							}
							else{
								cnt[3]++;
								minn=Max(cc[i],ccc[i]);
								k=i;
							} 
							
							continue;
						}
						if(cnt[2]<maxx){
							cnt[2]++;
							minn=Max(ca[i],cca[i]);
							k=i;
							continue;
						}
						if(cnt[3]<maxx){
							cnt[3]++;
							minn=Max(cc[i],ccc[i]);
							k=i;
							continue;
						}
					}
				}
				ans-=minn;
				vis[k]=true;
			}
		}
		if(cnt[2]>maxx){
			t=cnt[2]-maxx;
			while(t--){
				minn=1e9;
				k=0;
				L(i,1,n){
					if(vis[i])continue;
					if(Max(ca[i],cca[i])<minn||Max(cb[i],ccb[i])<minn){
						if(cnt[1]<maxx&&cnt[3]<maxx){
							if(Max(ca[i],cca[i])<Max(cb[i],ccb[i])){
								cnt[1]++;
								minn=Max(ca[i],cca[i]);
								k=i;
							}
							else{
								cnt[3]++;
								minn=Max(cb[i],ccb[i]);
								k=i;
							} 
							
							continue;
						}
						if(cnt[1]<maxx){
							cnt[1]++;
							minn=Max(ca[i],cca[i]);
							k=i;
							continue;
						}
						if(cnt[3]<maxx){
							cnt[3]++;
							minn=Max(cb[i],ccb[i]);
							k=i;
							continue;
						}
					}
				}
				ans-=minn;
				vis[k]=true;
			}
		}
		if(cnt[3]>maxx){
			t=cnt[3]-maxx;
			while(t--){
				minn=1e9;
				k=0;
				L(i,1,n){
					if(vis[i])continue;
					if(Max(cc[i],ccc[i])<minn||Max(cb[i],ccb[i])<minn){
						if(cnt[1]<maxx&&cnt[2]<maxx){
							if(Max(cc[i],ccc[i])<Max(cb[i],ccb[i])){
								cnt[1]++;
								minn=Max(cc[i],ccc[i]);
								k=i;
							}
							else{
								cnt[2]++;
								minn=Max(cb[i],ccb[i]);
								k=i;
							} 
							
							continue;
						}
						if(cnt[1]<maxx){
							cnt[1]++;
							minn=Max(cc[i],ccc[i]);
							k=i;
							continue;
						}
						if(cnt[2]<maxx){
							cnt[2]++;
							minn=Max(cb[i],ccb[i]);
							k=i;
							continue;
						}
					}
				}
				ans-=minn;
				vis[k]=true;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}