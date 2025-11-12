//CSP-J
//SN-J00313
//张之奇
//西安市铁一中学 

#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
const int maxl=1e6+5;
int n,k;
int a[maxn];
int sum[maxn];
int dp[maxl][2];
vector<pair<int,int> > V;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)	cin>>a[i],sum[i]=(sum[i-1]^a[i]);
	if (n<=1000){
		for (int l=1;l<=n;l++){
			for (int r=l;r<=n;r++){
				if ((sum[r]^sum[l-1])==k)	V.push_back({r,l});
			} 
		}
		sort(V.begin(),V.end());
		dp[0][0]=0;dp[0][1]=1;
		for (int i=1;i<(int)V.size();i++){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			int l=0,r=i-1,t=-1;
			while (l<=r){
				int mid=((l+r)>>1);
				if (V[mid].first<V[i].second){
					t=mid;
					l=mid+1;
				}
				else	r=mid-1;
			}
			if (t!=-1)	dp[i][1]=max(dp[t][0],dp[t][1])+1;
		}
		cout<<max(dp[(int)V.size()-1][0],dp[(int)V.size()-1][1]);
	}
	else {
		int ans=0;
		if (k==0){
			for (int i=1;i<=n;i++){
				if (a[i]==0)	ans++;
			}
		}
		else if (k==1){
			for (int i=1;i<=n;i++){
				if (a[i]==1)	ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
