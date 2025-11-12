#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int dp(int i,int cnt,int ans,int maxn,bool f){
	if(i > n)	return ans;
	if(f && i >= 3){
		if(a[i] <= maxn && cnt + a[i] > 2 * maxn)    ans++;
		else if(a[i] > maxn){
			maxn = a[i];
			if(cnt + a[i] > 2 * maxn)    ans++;
		}
		return dp(i+1,cnt + a[i],ans,maxn,true) + dp(i+1,cnt + a[i],ans,maxn,false);
	}
	else if(i < 3){
		if(f)	dp(i+1,cnt + a[i],ans,max(a[i],maxn),true) + dp(i+1,cnt + a[i],ans,max(a[i],maxn),false);
		return dp(i+1,cnt,ans,max(a[i],maxn),true) + dp(i+1,cnt,ans,max(a[i],maxn),false);
	}
	return dp(i+1,cnt,ans,max(a[i],maxn),true) + dp(i+1,cnt,ans,max(a[i],maxn),false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a + n + 1);
	cout << dp(1,0,0,0,true) + dp(1,0,0,0,false);
	return 0;
}
