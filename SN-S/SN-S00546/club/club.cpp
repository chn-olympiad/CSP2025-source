#include<bits/stdc++.h>
#define int long long
using namespace std;
bool v,u;
int T,n,t,ans;
struct node{
	int a,b,c,s,id;
};
node vis[100005];
void dfs(int m,int k,int x,int y,int z){
	if(m>n){
		ans=max(ans,k);
		return ;
	}
	if(x<t) dfs(m+1,k+vis[m].a,x+1,y,z);
	if(y<t) dfs(m+1,k+vis[m].b,x,y+1,z);
	if(z<t) dfs(m+1,k+vis[m].c,x,y,z+1);
}
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp1(node x,node y){
	return x.s>y.s;
}
//无正确性的贪心 :(((((((((((((((((((((
void f(){
	sort(vis+1,vis+1+n,cmp1);
	int cy[5]={0,0,0,0};
	for(int i=1;i<=n;i++){
		if(cy[vis[i].id]<t){
			cy[vis[i].id]++;
			ans+=vis[i].s;
		}
		else{
			if(vis[i].id==1){
				if(vis[i].b>vis[i].c&&cy[2]<t){
					cy[2]++;
					ans+=vis[i].b;
				}
				else{
					cy[3]++;
					ans+=vis[i].c;
				}
			}
			if(vis[i].id==2){
				if(vis[i].a>vis[i].c&&cy[1]<t){
					cy[1]++;
					ans+=vis[i].a;
				}
				else{
					cy[3]++;
					ans+=vis[i].c;
				}
			}
			if(vis[i].id==3){
				if(vis[i].a>vis[i].b&&cy[1]<t){
					cy[1]++;
					ans+=vis[i].a;
				}
				else{
					cy[2]++;
					ans+=vis[i].b;
				}
			}
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		v=1,u=1;
		t=n/2;
		for(int i=1;i<=n;i++){
			cin>>vis[i].a>>vis[i].b>>vis[i].c;
			//调最大 
			if(vis[i].a>vis[i].b&&vis[i].a>vis[i].c){
				vis[i].s=vis[i].a;
				vis[i].id=1;
			}
			if(vis[i].b>vis[i].a&&vis[i].b>vis[i].c){
				vis[i].s=vis[i].b;
				vis[i].id=2;
			}
			if(vis[i].c>vis[i].b&&vis[i].c>vis[i].a){
				vis[i].s=vis[i].c;
				vis[i].id=3;
			}
			//特判 
			if(vis[i].b!=0||vis[i].c!=0) v=0;
			if(vis[i].c!=0) u=0;
		}
		//特判 
		if(v){
			sort(vis+1,vis+1+n,cmp);
			for(int i=1;i<=t;i++) ans+=vis[i].a;
			cout<<ans<<endl;
			continue;
		}
		//范围小就暴力 
		if(n<=18) dfs(1,0,0,0,0);
		else f();
		cout<<ans<<endl;
	}
	return 0;
}
//
