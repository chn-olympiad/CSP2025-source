#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000100],v[1000100],w[1000100],c[11],a[11][10010],c2[10010],minn=99999999999999999,minnc2[10010],nownum=1,mi;
long long xiang[11];
bool ch[1001];
struct way{
	long long ww[1000010],wv[1000010],num,wnum[1000010];
}way[10010];
int bian(long long now){
	if(nownum==n){
		if(mi<minn){
			minn=mi;
			for(long long i=1;i<=n;i++){
				minnc2[i]=c2[i];
			}
		}
		return 0;
	}
	for(long long i=1;i<=way[now].num;i++){
		if(ch[way[now].wv[i]]==0){
			long long q=way[now].wv[i];
			nownum++;
			c2[q]=way[now].ww[i];
			ch[q]=1;
			mi+=way[now].ww[i];
			bian(q);
			nownum--;
			ch[q]=0;
			mi-=way[now].ww[i];
		}
	}
	for(){
		
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		way[u[i]].num++;
		way[v[i]].num++;
		way[u[i]].wv[way[u[i]].num]=v[i];
		way[u[i]].ww[way[u[i]].num]=w[i];
		way[v[i]].wv[way[v[i]].num]=u[i];
		way[v[i]].ww[way[v[i]].num]=w[i];
		way[v[i]].wnum[way[v[i]].num]=i;
		way[u[i]].wnum[way[u[i]].num]=i;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ch[1]=1;
	bian(1);
	cout<<minn;
	return 0;
}

