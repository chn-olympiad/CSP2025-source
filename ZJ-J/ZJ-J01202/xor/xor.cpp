#include<bits/stdc++.h>
using namespace std;
long long k,a[100001],dp[100001][100001];
int n,ans,tot;
bool f[100001],flag;
struct no{
	int l,r,w;
}b[500001];
bool cmp(no q,no h){
	return q.w<h.w;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		dp[i][i]=a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			dp[i][j]=dp[i][j-1] xor a[j];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(dp[i][j]==k){
				tot++;
				b[tot].l=i;
				b[tot].r=j;
				b[tot].w=j-i+1;
				break;
			}
	sort(b+1,b+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		flag=0;
		for(int j=b[i].l;j<=b[i].r;j++)
			if(f[j]){
				flag=1;
				break;
			}
		if(!flag){
			ans++;
			for(int j=b[i].l;j<=b[i].r;j++)
				f[j]=1;
		}
	}
	cout<<ans;
}
