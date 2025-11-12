//by snakeMC
//now:PAC  ~10pts
#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500010];
bool can(int l,int r,int ans){
	return (ans==k);
}
int maxcnt=0;
void dfs(int cnt,int k,int ans){
	if(k>=n){
		maxcnt=max(maxcnt,cnt);
		return;
	}
	for(int i=k;i<n;i++){
		if(can(k,i,ans)){
			dfs(cnt+1,i+1,a[i+1]);
			break;
		}else if(i+1<n){
			ans^=a[i+1];
		}
	}
	dfs(cnt,k+1,a[k+1]);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs(0,0,a[0]);
	cout<<maxcnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
