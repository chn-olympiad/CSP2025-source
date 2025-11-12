#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define dbg puts("____________qwq________________")
const int N=5e2+5;
int n,m,ans;
string s;
int c[N];
int b[N];
bool vis[N];
int check(){
//	for(int i=1;i<=n;i++){
//		cout<<b[i];
//	}
//	dbg;
	int q=0,res=0;
	for(int i=1;i<=n;i++){
		if(q>=c[b[i]]||s[i]=='0'){
			q++;
		}else{
			res++;
		}
	}
	if(res>=m){
		return 1;
	}
	return 0;
}
void dfs(int step){
	if(step>n){
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			b[step]=i;
			vis[i]=1;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;	
	return 0;
}