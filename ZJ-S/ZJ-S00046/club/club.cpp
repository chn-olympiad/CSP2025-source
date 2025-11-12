#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c;
}pt[100010];
struct nn{
	int a,idx;
}ad[100010],bd[100010];
int n,ans,vis[100010],act,bct;
//map<node,int> mps;
void dfs(int nw,int na,int nb,int nc,int sum){
	if (na>n/2 || nb>n/2 || nc>n/2)return ;
	if (nw==n+1){
		ans=max(ans,sum);
		return ;
	}
	dfs(nw+1,na+1,nb,nc,sum+pt[nw].a);
	dfs(nw+1,na,nb+1,nc,sum+pt[nw].b);
	dfs(nw+1,na,nb,nc+1,sum+pt[nw].c);
}
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp2(nn a,nn b){
	return a.a>b.a;
}
void SLOVE(){
	cin>>n;
	ans=act=0;
	bool f=0;
	for (int i=1;i<=n;++i){
		vis[i]=0;
		cin>>pt[i].a>>pt[i].b>>pt[i].c;
		if (pt[i].b!=0 || pt[i].c!=0){
			f=1;
		}
		ad[++act].a=pt[i].a;
		ad[act].idx=i;
		ad[++act].a=pt[i].b;
		ad[act].idx=i;
	}
	sort(ad+1,ad+1+act,cmp2);
	if (!f){
		ans=0;
		sort(pt+1,pt+1+n,cmp);
		for (int i=1;i<=n/2;++i){
			ans+=pt[i].a;
		}
		cout<<ans<<endl;
		return ;
	}
	f=0;
	for (int i=1;i<=n;++i){
		if (pt[i].c!=0){
			f=1;
		}
	}
	if (!f){
		for (int i=1;i<=act;++i){
			if (!vis[ad[i].idx]){
				vis[ad[i].idx]=1;
				ans+=ad[i].a;
			}
		}
		cout<<ans<<endl;
		return ;
	}
	dfs(1,0,0,0,0);
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while (_--){
		SLOVE();
	}
	return 0;
}
