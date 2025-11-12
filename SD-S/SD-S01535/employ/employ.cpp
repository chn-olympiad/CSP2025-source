//20pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define ls rt*2;
#define rs rt*2+1;
const int Mod=998244353;
const int N=1e3;
int n,m;
string s;
int c[N];
int a[N],vis[N];
int ans;
int check(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]){
			cnt++;
			continue;
		}
		if(s[i]=='1'){
			sum++;
		}
		else{
			cnt++;
		}
	}
	if(sum>=m){
		return 1;
	}
	return 0;
}
void dfs(int x){
	if(x>n){
		(ans+=check())%=Mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			a[x]=0;
			vis[i]=0; 
		}
	}
}
int A;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;
	}
	return 0;
} 
/*
3 2
101
1 1 2
*/
