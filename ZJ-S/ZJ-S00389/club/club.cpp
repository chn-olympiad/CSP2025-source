#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll t,dp[maxn],num[maxn][4],lst[4];
struct node{
	ll cha,fi,se,ind;
}a[maxn];
bool cmp(node x,node y){
	return x.cha>y.cha;
}
int main(){
	freopen("size.in","r",stdin);
	freopen("size.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		ll n;
		cin>>n;
		for(int j=0;j<maxn;j++){
			dp[j]=0;
		}
		for(int j=0;j<maxn;j++){
			lst[j]=0;
		}
		for(int j=1;j<=n;j++){
			a[j].ind=j;
			cin>>num[j][1]>>num[j][2]>>num[j][3];
			if(num[j][1]>=num[j][2] and num[j][1]>=num[j][3]){
				a[j].fi=1;
				if(num[j][2]>=num[j][3]){
					a[j].se=2;
					a[j].cha=num[j][1]-num[j][2];
				}
				else{
					a[j].se=3;
					a[j].cha=num[j][1]-num[j][3];
				}
			}
			else if(num[j][2]>=num[j][1] and num[j][2]>=num[j][3]){
				a[j].fi=2;
				if(num[j][1]>=num[j][3]){
					a[j].se=1;
					a[j].cha=num[j][2]-num[j][1];
				}
				else{
					a[j].se=3;
					a[j].cha=num[j][2]-num[j][3];
				}
			}
			else{
				a[j].fi=3;
				if(num[j][1]>=num[j][2]){
					a[j].cha=num[j][3]-num[j][1];
					a[j].se=1;
				}
				else{
					a[j].se=2;
					a[j].cha=num[j][3]-num[j][2];
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(lst[a[j].fi]<n/2){
				dp[j]=dp[j-1]+num[a[j].ind][a[j].fi];
				lst[a[j].fi]++;
			}
			else{
				dp[j]=dp[j-1]+num[a[j].ind][a[j].se];
				lst[a[j].se]++;
			}
		}
		cout<<dp[n]<<endl;
	}
		
	return 0;
}
