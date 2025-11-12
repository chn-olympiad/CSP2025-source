#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=2e9+7;
int n,a[3][N],cnt[3],v[N];
priority_queue<pair<int,int> > q[3][3];
int cal(){
	int id=0;
	for(int j=0;j<3;j++) if(cnt[j]>cnt[id]) id=j;
	if(cnt[id]>n/2) return id;
	return -1;
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		ch=getchar();
		if(ch=='-') f*=-1;
	}
	while(ch>='0' && ch<='9'){
		x*=10,x+=ch-48;
		ch=getchar();
	}
	return x*f;
}
int main(){
//	system("fc club.out club5.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			a[0][i]=read(),a[1][i]=read(),a[2][i]=read();
			int id=0;
			for(int j=0;j<3;j++) if(a[j][i]>a[id][i]) id=j;
			cnt[id]++;
			v[i]=id;
			ans+=a[id][i];
			for(int j=0;j<3;j++){
				if(j==id) continue;
//				cout<<id<<' '<<j<<' '<<a[j][i]-a[id][i]<<'\n';
				q[id][j].push({a[j][i]-a[id][i],i});
			}
		}
//		int C=0;
		while(1){
			int x=cal();
			if(x==-1) break;
			int id=0,W=-INF;
			for(int i=0;i<3;i++){
				if(i==x) continue;
				while(q[x][i].size() && v[q[x][i].top().second]!=x) q[x][i].pop();
				if(q[x][i].size()){
					int w=q[x][i].top().first;
					if(w>W) W=w,id=i;
				}
			}
			if(W!=-INF){
				int y=q[x][id].top().second,w=q[x][id].top().first;
//				cout<<x<<' '<<id<<' '<<y<<' '<<w<<' '<<v[y]<<'\n';
				ans+=w;
				v[y]=id;
				for(int i=0;i<3;i++){
					if(i==id) continue;
					q[id][i].push({a[id][y]-a[i][y],y});
				}
				cnt[x]--,cnt[id]++;
			}
//			C++;
		}
//		printf("%lld ",C);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			v[i]=0;
		}
		for(int i=0;i<3;i++){
			cnt[i]=0;
			for(int j=0;j<3;j++){
				while(!q[i][j].empty()) q[i][j].pop();
			}
		}
	}
	return 0;
}
//15:00
