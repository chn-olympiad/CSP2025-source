#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[105],c[105];
string s;
long long cnt=0;
bool b[105];
void dfs(int w,int jj,int jn){
	if(w==n){
		if(jn>=m){
			cnt=(cnt+1)%mod;
		}
		return ;
	}
	for(int i=0;i<n;i++){
		if(!b[i]){
			b[i]=1;
			if((a[i]>jj)&&c[w]){
				dfs(w+1,jj,jn+1);
			}else{
				dfs(w+1,jj+1,jn);
			}
			b[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=s[i]-'0';
	}
	dfs(0,0,0);
	cout<<cnt;
	return 0;
}

