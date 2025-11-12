#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int t;
int n;
struct Node{
	int a,b,c,id;
}x[N];
struct Node2{
	int a,b,c,id;
}y[N];
struct Node3{
	int a,b,c,id;
}z[N];
bool cmp(Node i,Node j){
	if(i.a==j.a){
		if(i.b==j.b) return i.c<j.c;
		return i.b<j.b;
	}
	return i.a>j.a;
}
bool cmp2(Node2 i,Node2 j){
	if(i.b==j.b){
		if(i.a==j.a) return i.c<j.c;
		return i.a<j.a;
	}
	return i.b>j.b;
}
bool cmp3(Node3 i,Node3 j){
	if(i.c==j.c){
		if(i.a==j.a) return i.b<j.b;
		return i.a<j.a;
	}
	return i.c>j.c;
}
bool vis[N];
int num[3];
int up;
int ans;
void dfs(int t,int sum){
	if(num[0]>up||num[1]>up||num[2]>up) return;
	if(t==n+1){
		ans=max(ans,sum);
		return;
	}
	num[0]++;
	dfs(t+1,sum+x[t].a);
	num[0]--;
	num[1]++;
	dfs(t+1,sum+x[t].b);
	num[1]--;
	num[2]++;
	dfs(t+1,sum+x[t].c);
	num[2]--;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(vis,0,sizeof vis);
		cin>>n;ans=0;
		up=n/2;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			y[i].a=x[i].a,y[i].b=x[i].b,y[i].c=x[i].c;
			z[i].a=x[i].a,z[i].b=x[i].b,z[i].c=x[i].c;
			x[i].id=y[i].id=z[i].id=i;
		}
		if(n<=10){
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
		sort(x+1,x+n+1,cmp);
		sort(y+1,y+n+1,cmp2);
		sort(z+1,z+n+1,cmp3);
		//for(int i=1;i<=n;i++) cout<<y[i].id<<'\n';
		int i=1,j=1,k=1;
		int ans=0;
		for(int p=1;p<=n;p++){
			while(i<=up&&vis[x[i].id]) i++;
			while(j<=up&&vis[y[j].id]) j++;
			while(k<=up&&vis[z[k].id]) k++;
			int ma=0;
			if(i<=up) ma=max(ma,x[i].a);
			if(j<=up) ma=max(ma,y[j].b);
			if(k<=up) ma=max(ma,z[k].c);
			//int ma=max({x[i].a,y[j].b,z[k].c});
			if(i<=up&&ma==x[i].a){
				ans+=x[i].a;
				vis[x[i].id]=1;
				i++;
			}
			if(j<=up&&ma==y[j].b){
				ans+=y[j].b;
				vis[y[j].id]=1;
				j++;
			}
			if(k<=up&&ma==z[k].c){
				ans+=z[k].c;
				vis[z[k].id]=1;
				k++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
