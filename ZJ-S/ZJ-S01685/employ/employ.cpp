#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=1000;
int n,m,val;
long long a[N];
long long ans,x;
bool vis[N];
string str;
void dfs(int pos,int srt){
	if(pos>n){
		if((n-srt)>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]>srt&&str[pos-1]=='1')
				dfs(pos+1,srt);
			else dfs(pos+1,srt+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	int len=str.length();
	bool flag=1;
	for(int i=0;i<len;i++){
		if(str[i]=='0') flag=0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0) val++;
	}
	x=0;
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
//chzx_lfw AK IOI!!!!!
/*
3 2
101
1 1 2

2
*/
