#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int c[N],s[N],n,m,vis[N],ch[N],ans;
char t[N];
bool check(){
	int lst=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(c[ch[i]]<=lst) lst++;
		else if(s[i]) cnt++,lst=0;
		else lst++;
	}
	if(cnt<m) return 0; 
	for(int i=1;i<=n;i++) cout<<ch[i]<<" ";
	cout<<cnt<<"\n";
	return cnt>=m;
}
void dfs(int p){
	if(p>n){
		if(check()) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ch[p]=i,vis[i]=1;
			dfs(p+1);
			ch[p]=vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	cin>>n>>m>>(t+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) s[i]=t[i]-'0';
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	cout<<0;
	return 0;
} 