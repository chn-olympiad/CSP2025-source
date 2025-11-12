#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200;
const ll MOD=998244353;
int n,m,a[N],c[N];
ll sum,p[N];
bool vis[N];
string s;
void check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]) cnt++;
		else if(s[i]=='0') cnt++;
	}
	if(n-cnt>=m) sum++;
}
void dfs(int x){
	if(x>n){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	bool flag=1;
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*i%MOD;
		if(s[i]!='1') flag=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=18){
		dfs(1);
		cout<<sum;
	}else if(m==n){
		if(!flag) cout<<0;
		else cout<<p[n];
	}else if(flag){
		cout<<p[n];
	}else if(m==1){
		cout<<p[n];
	}
	return 0;
}
/*
3 2
101
1 1 2


10 5
1101111011
6 0 4 2 1 2 5 4 3 3

5+3+1=9
3+2 -> m=1  dp? 20pts
*/
