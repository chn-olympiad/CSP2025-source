#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int arr[6005],vis[6005],maxx,tmplen,n,tot;
int dp[5005][5005];
bool check(int cnt,int maxlen){
	return cnt>(maxlen*2);
}
void dfs(int p,int cnt,int maxlen,int maxid,int al){
	if(p==al && check(cnt,maxlen)){
		tot++;
		tot%=998244353;
		return;
	}
	for(int i=maxid;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(p+1,cnt+arr[i],max(maxlen,arr[i]),max(maxid,i),al);
		vis[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		maxx=max(arr[i],maxx);
	}
	if(n<=3){
		int cnt=arr[1]+arr[2]+arr[3];
		if(check(cnt,maxx)){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(maxx==1){
		for(int i=2;i<n;i++){
			tot+=(n-i);
		}
		cout<<tot;
		return 0;
	}
	sort(arr+1,arr+n+1);
	if(n<=20){
		for(int i=3;i<=n;i++){
			dfs(0,0,1,1,i);
		}
	}
	cout<<tot;
	return 0;
}
