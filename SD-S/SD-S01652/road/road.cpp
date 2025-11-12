#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=10010,M=1100010,INF=0x3f3f3f3f3f3f3f3f;
int n,m,k,ans=INF;
int c[20];
int dsu[N];
struct R{
	int x,y,w;
}road[M],nroad[M];
struct V{
	int x,y,w;
}vl[20][N];
bool cmp(R a,R b){
	return a.w<b.w;
}
bool cmp2(V a,V b){
	return a.w<b.w;
}
int find(int x){
	if(x==dsu[x]){
		return x;
	}
	return dsu[x]=find(dsu[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		dsu[fx]=fy;
	}
}
bool flag_0=1;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i].x>>road[i].y>>road[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			flag_0=0;
		}
		for(int j=1;j<=n;j++){
			cin>>vl[i][j].w;
			vl[i][j].x=i+n;
			vl[i][j].y=j;
		}
		sort(vl[i]+1,vl[i]+n+1,cmp2);
		if(vl[i][1].w!=0){
			flag_0=0;
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			dsu[i]=i;
		}
		int sum=0;
		sort(road+1,road+m+1,cmp);
		int cnt_tmp=0;
		for(int i=1;i<=m;i++){
			int x=road[i].x,y=road[i].y,w=road[i].w;
			if(find(x)!=find(y)){
				sum+=w;
				merge(x,y);
				cnt_tmp++;
				if(cnt_tmp==n-1){
					break;
				}
			}
		}
		cout<<sum;
		return 0;
	}
	else if(flag_0){
		int tot_road=m;
		for(int i=1;i<=n+k;i++){
			dsu[i]=i;
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				road[++tot_road].x=vl[i][j].x;
				road[tot_road].y=vl[i][j].y;
				road[tot_road].w=vl[i][j].w;
			}
		}
		int sum=0;
		sort(road+1,road+tot_road+1,cmp);
		int cnt_tmp=0;
		for(int i=1;i<=m;i++){
			int x=road[i].x,y=road[i].y,w=road[i].w;
			if(find(x)!=find(y)){
				sum+=w;
				merge(x,y);
				cnt_tmp++;
				if(cnt_tmp==n+k-1){
					break;
				}
			}
		}
		cout<<sum;
		return 0;
	}
	else if(k<=5){
		for(int opt=0;opt<=(1<<k)-1;opt++){
			int sum=0;
			for(int i=1;i<=n+k;i++){
				dsu[i]=i;
			}
			int tot_road=m,ava=0;
			for(int i=1;i<=m;i++){
				nroad[i]=road[i];
			}
			for(int i=1;i<=k;i++){
				if((opt>>(i-1))&1){
					ava++;
					sum+=c[i];
					for(int j=1;j<=n;j++){
						nroad[++tot_road].x=vl[i][j].x;
						nroad[tot_road].y=vl[i][j].y;
						nroad[tot_road].w=vl[i][j].w;
					}
					
				}
			}
			sort(nroad+1,nroad+tot_road+1,cmp);
			int cnt_tmp=0;
			for(int i=1;i<=tot_road;i++){
				int x=nroad[i].x,y=nroad[i].y,w=nroad[i].w;
				if(find(x)!=find(y)){
					sum+=w;
					merge(x,y);
					cnt_tmp++;
					if(cnt_tmp==n+ava-1){
						break;
					}
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
