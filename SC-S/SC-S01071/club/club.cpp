#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
ll n,t,vis[N][5],f[5],ans,v[5][N],v1[N],ff[5];
struct node{
	ll num,bh;
}a[N][5];
bool operator >(node a,node b){
	return a.num>b.num;
}
bool operator <(node a,node b){
	return a.num>b.num;
}
priority_queue<node,vector<node>,greater<node>>q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(f,0,sizeof(f));
		for(ll i=1;i<=n;i++) 
			for(ll j=1;j<=3;j++){
				cin>>a[i][j].num;
				a[i][j].bh=j;
			}
				
		for(ll i=1;i<=n;i++){
			stable_sort(a[i]+1,a[i]+4);
			for(ll j=1;j<=3;j++){
				vis[i][a[i][j].bh]=j;
				if(j==1){
					f[a[i][j].bh]++;
					v[a[i][j].bh][f[a[i][j].bh]]=i;
					v1[i]=a[i][j].bh;
				}
			}
		}
		for(ll i=1;i<=3;i++) ff[i]=f[i];
		while(1){
			bool flag=0;
			for(ll i=1;i<=3;i++){
				if(ff[i]<=n/2) continue;
				else{
					flag=1;
					for(ll j=1;j<=f[i];j++){
						ll tmp=a[v[i][j]][vis[v[i][j]][i]].num-a[v[i][j]][vis[v[i][j]][i]+1].num;
						q.push({tmp,v[i][j]});
					}
					while(q.size()>n/2){
						node x=q.top();
						q.pop();
						ll zh=a[x.bh][vis[x.bh][i]+1].bh;
						f[zh]++;
						ff[zh]++;
						v[zh][f[zh]]=x.bh;
						v1[x.bh]=zh;
						ff[i]--;
					}
					while(q.size()){
						q.pop();
					}
				}
			}
			if(!flag) break;
		}
		for(ll i=1;i<=3;i++){
			for(ll j=1;j<=f[i];j++){
				if(v1[v[i][j]]!=i) continue;
				ans+=a[v[i][j]][vis[v[i][j]][i]].num;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}