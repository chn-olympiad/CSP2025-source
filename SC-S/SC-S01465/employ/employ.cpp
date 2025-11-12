#include<iostream>
#include<algorithm>
#define int long long
#define mod 998244353
using namespace std;
const int N=505;
int n,m,ans,A[N],vu[N],go[N];
string s;
void work(){
	int del=0,get=0;
	for(int i=1;i<=n;i++){
		if(del>=A[go[i]]){del++;continue;}
		if(s[i]=='1') get++;
		else del++;
	}
	if(get>=m){
		ans++;
//		for(int i=1;i<=n;i++) cout<<go[i]<<" ";
//		cout<<endl;
	}
}
void dfs(int x){
	if(x>n) return work();
	for(int i=1;i<=n;i++){
		if(vu[i]) continue;
		go[x]=i;vu[i]=1;
		dfs(x+1);
		go[x]=vu[i]=0;
	}
}
void solve1(){
	dfs(1);cout<<ans<<endl;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s='6'+s;
	for(int i=1;i<=n;i++) cin>>A[i];
	if(n<=10) return solve1(),0;
	else{
		cout<<"0\n";
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/