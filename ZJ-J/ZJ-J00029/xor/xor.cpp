#include<bits/stdc++.h>
using namespace std;
long long n,k,t,l,r,s,x,a[500005],b[1005][1005],dp[500005][2];bool p;
struct node{
	long long x,y;
}f[1000005];
bool cmp(node a,node b){
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n<=1000){
		for (int i=1;i<=n;i++) b[i][i]=a[i];
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++){
			b[i][j]=(b[i][j-1] xor a[j]);
			if (b[i][j]==k) f[++t].x=i,f[t].y=j;
		}sort(f+1,f+t+1,cmp);l=1;s=t;
		while (l<=t){
			if (l+2<=t&&f[l].y>f[l+1].x&&f[l].y<f[l+2].x) s--,l=l+2;
			else if (l+2<=t&&f[l].y>f[l+2].x) s--,l++;
			else l++;
		}cout<<s;
	}else{
		for (int i=1;i<=n;i++){
			if (!p) x=(x xor a[i]);
			else x=a[i];
			if (x==k){
				dp[i][1]=max(dp[i-1][1],dp[i-1][0])+1;
				dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				p=1;
			}else{
				dp[i][1]=max(dp[i-1][1],dp[i-1][0]);
				dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
				p=0;
			}
		}cout<<max(dp[n][1],dp[n][0]);
	}
}