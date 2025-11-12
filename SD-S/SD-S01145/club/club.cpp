#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100010][5];
int cnt[5];
int ans=0;
void dfs(int x,int s){
	if(x==n){
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]!=n/2){
			cnt[i]++;
			dfs(x+1,s+a[x+1][i]);
			cnt[i]--;
		}
	}
}
bool vis[100010];
struct A{
	int f,id,idx;
	bool operator <(const A x)const{
		return f<x.f;
	}
};
struct B{
	int f1,f2,f3,v=0;
};
B b[100010];
bool cmp1(B x,B y){
	if(x.f1==y.f1) return x.f2>y.f2;
	return x.f1>y.f1;
}
bool cmp2(B x,B y){
	return x.f2>y.f2;
}
A c[100010][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		if(n<=30){
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			dfs(0,0);
			cout<<ans<<endl;
		}else{
			memset(vis,0,sizeof(vis));
			priority_queue<A> q;
			bool k3=0;
			for(int i=1;i<=n;i++){
				cin>>c[i][1].f>>c[i][2].f>>c[i][3].f;
				if(c[i][3].f!=0) k3=1;
				c[i][1].id=1,c[i][2].id=2,c[i][3].id=3;
				c[i][1].idx=c[i][2].idx=c[i][3].idx=i;
				q.push(c[i][1]);q.push(c[i][2]);q.push(c[i][3]);
			}
			if(k3==0){
				for(int i=1;i<=n;i++){
					b[i].f1=c[i][1].f;
					b[i].f2=c[i][2].f;
					b[i].f3=c[i][3].f;
				}
				sort(b+1,b+n+1,cmp1);
				ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=b[i].f1;
					b[i].v=1;
				}
				sort(b+1,b+n+1,cmp2);
				int cnt2=0;
				for(int i=1;i<=n&&cnt2<=n/2;i++){
					if(b[i].v==1&&b[i].f1<b[i].f2){
						cnt2++;
						ans-=b[i].f1;
						ans+=b[i].f2;
					}
				}
				if(cnt2==n/2){
					for(int i=1;i<=n;i++){
						if(b[i].v==0){
							ans+=b[i].f1;
						}
					}
				}else{
					for(int i=1;i<=n;i++){
						if(b[i].v==0){
							ans+=b[i].f2;
						}
					}
				}
				cout<<ans<<endl;
			}else{
				int cnt[5]={0,0,0,0};
				while(!q.empty()){
					A t=q.top();
					q.pop();
					if(vis[t.idx]==1) continue;
					if(cnt[t.id]==n/2) continue;
					cnt[t.id]++;
					vis[t.idx]=1;
					ans+=t.f;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
