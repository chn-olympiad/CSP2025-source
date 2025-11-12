#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	pair<int,int> x[4];
};
struct nn{
	int a,b,c;
};
int maxx=0;
void dfs(int pos,int ans,int tong[],int n,nn awa[]){
	if(pos==n+1){
		maxx=max(maxx,ans);
		return; 
	}
	if(tong[1]<n/2){
		tong[1]++;
		dfs(pos+1,ans+awa[pos].a,tong,n,awa);
		tong[1]--;
	}
	if(tong[2]<n/2){
		tong[2]++;
		dfs(pos+1,ans+awa[pos].b,tong,n,awa);
		tong[2]--;
	}
	if(tong[3]<n/2){
		tong[3]++;
		dfs(pos+1,ans+awa[pos].c,tong,n,awa);
		tong[3]--;
	}
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		node p[n+5];
		nn awa[n+5];
		for(int i=1; i<=n; i++){
			int a,b,c;
			cin>>a>>b>>c;
			awa[i].a=a;
			awa[i].b=b;
			awa[i].c=c;
			int maxx=max(a,max(b,c));
			if(a==maxx){
				if(b>c){
					p[i].x[1]={a,1};
					p[i].x[2]={b,2};
					p[i].x[3]={c,3};
				}
				else{
					p[i].x[1]={a,1};
					p[i].x[2]={c,3};
					p[i].x[3]={b,2};
				}
			}
			else if(b==maxx){
				if(a>c){
					p[i].x[1]={b,2};
					p[i].x[2]={a,1};
					p[i].x[3]={c,3};
				}
				else{
					p[i].x[1]={b,2};
					p[i].x[2]={c,3};
					p[i].x[3]={a,1};
				}
			}
			else{
				if(a>b){
					p[i].x[1]={c,3};
					p[i].x[2]={a,1};
					p[i].x[3]={b,2};
				}
				else{
					p[i].x[1]={c,3};
					p[i].x[2]={b,2};
					p[i].x[3]={a,1};
				}
			}
		}
		int tong[4]={0},ans=0;
		if(n<=10){
			maxx=0;
			dfs(1,0,tong,n,awa);
			cout<<maxx<<"\n";
			continue;
		}
		sort(p+1,p+n+1,[](node a,node b){
			if(a.x[1].first==b.x[1].first){
				if(a.x[2].first==b.x[2].first) return a.x[3].first>b.x[3].first;
				return a.x[2].first>b.x[2].first;
			}
			return a.x[1].first>b.x[1].first;
		});
		for(int i=1; i<=n; i++){
			pair<int,int> mb;
			if(tong[p[i].x[1].second]<n/2) mb=p[i].x[1];
			else if(tong[p[i].x[2].second]<n/2) mb=p[i].x[2];
			else mb=p[i].x[3];
			tong[mb.second]++;
			ans+=mb.first;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
*/
