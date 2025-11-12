#include<bits/stdc++.h>
using namespace std;
const int mcx=5e5+5;
int n,k,a[mcx],sum[mcx],dp[mcx],hed,stlen[mcx],sted[mcx];
int len;
struct xu{
	int x,y;
}qp[mcx];
bool cmp(xu a,xu b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	int ma=INT_MIN;
	for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]^a[i],ma=max(ma,a[i]);
	
	if(k<=1&&ma<=1){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;){
				if(a[i]==0)ans++,i++;
				else if(a[i]==1&&a[i+1]==1)i+=2,ans++;
				else i++;
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++)
	if((sum[j]^sum[i-1])==k)qp[++len]={i,j};
	
	sort(qp+1,qp+len+1,cmp);
	for(int i=1;i<=len;i++){
		int weizhi=lower_bound(sted+1,sted+hed+1,qp[i].x)-sted-1;
		if(stlen[weizhi]+1>stlen[hed])stlen[++hed]=stlen[weizhi]+1,sted[hed]=qp[i].y;
		ans=max(ans,stlen[weizhi]+1);
	}
	cout<<ans;
	return 0;
}