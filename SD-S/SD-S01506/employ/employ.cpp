#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<stack>
#define N 200010
#define MOD 998244353
using namespace std;
long long n,m,c[N],ans=0,flag[N],pows[N];
char s[N];
void dfs(long long k,long long cnt){
	if(cnt>=m){
		ans+=pows[n-k];
		return;
	}
	if(k==n||cnt+n-k<m){
		return;
	}
	for(int i=1;i<=n;++i){
		if(flag[i]){
			continue;
		}
		flag[i]=1;
		dfs(k+1,cnt+(s[k+1]=='1'&&k-cnt<c[i]));
		flag[i]=0;
	}
}
long long special=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	pows[0]=1;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		pows[i]=pows[i-1]*i%MOD;
		special=(special&&s[i]=='1');
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
*/
