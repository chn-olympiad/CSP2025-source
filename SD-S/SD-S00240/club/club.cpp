#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int it,v;
};
vector<node> a[N];
bool cmp(node a,node b){
	return a.v>b.v;
}
bool cmp2(vector<node> a,vector<node> b){
	if(a[0].it!=b[0].it) return a[0].it<b[0].it;
	if(a[1].it!=b[1].it) return a[1].it<b[1].it;
	if(a[2].it!=b[2].it) return a[2].it<b[2].it;
	
	if(a[0].v!=b[0].v) return a[0].v>b[0].v;
	if(a[1].v!=b[1].v) return a[1].v>b[1].v;
	return a[2].v>b[2].v;
}
int ans;
void dfs(int fi,int se,int th,int val,int now){
	ans=max(ans,val);
	if(now==n+1) return;
	if(fi<n/2) dfs(fi+1,se,th,val+a[now][0].v,now+1);
	if(se<n/2) dfs(fi,se+1,th,val+a[now][1].v,now+1);
	if(th<n/2) dfs(fi,se,th+1,val+a[now][2].v,now+1);
}
void solve(){
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			int t;
			cin>>t;
			node x;
			x.it=j;
			x.v=t;
			a[i].push_back(x);
		}
		//sort(a[i].begin(),a[i].end(),cmp);
	}
	//sort(a+1,a+n+1,cmp2);
//	for(int i=1;i<=n;i++,cout<<endl) for(int j=0;j<=2;j++) cout<<a[i][j].v<<' '; 
	dfs(0,0,0,0,1);
	cout<<ans<<endl;
	ans=0;
}
int main (){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
    fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
