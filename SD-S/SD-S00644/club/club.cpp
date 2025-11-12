#include<bits/stdc++.h>
#define ll long long 
using namespace std;
/*====================*/
const int N = 1e5+10;
/*====================*/
const int INF = 0x3F3F3F3F;
/*====================*/
const int MOD=998244353;
/*====================*/
int n,ans;
struct A{
	int a,b,c;
	friend bool operator<(const A&x,const A&y){
		return x.a>y.a;
	}
}s[N];
int DFS(vector<int>cnt,int ans,int k){
	if(k==n+1)return ans;
	int an=ans;
	for(int i=1;i<=3;i++){
		if(cnt[i]==n/2)continue;
		//cout<<"UDD "<<k<<' '<<i<<' '<<ans<<'\n';
		vector<int>q;q=cnt;q[i]++;
		an=max(DFS(q,ans+(i==1?s[k].a:(i==2?s[k].b:s[k].c)),k+1),an);
		//cout<<"UGFG "<<k<<' '<<i<<' '<<an<<'\n';
	}return an;
}
/*====================*/
void Solve(){
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[i].b!=0||s[i].c!=0)flag=1;
	}
	if(!flag){
		sort(s+1,s+1+n);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=s[i].a;
		}cout<<ans<<'\n';
		return;
	}
	vector<int>cnt(5,0);
	cout<<DFS(cnt,0,1)<<'\n';
}
/*====================*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T=1;cin>>T;
	while(T--)Solve();
	return 0;
}
/*Ren5Jie4Di4Ling5%*/
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
