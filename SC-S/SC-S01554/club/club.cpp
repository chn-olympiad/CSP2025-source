#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt[4],dp[N][4],maxn,x=1;
int a1[N],a2[N],a3[N];

void solve(){
	maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
	}
	sort(a1+1,a1+n+1);
	sort(a2+1,a2+n+1);
	int m=n;
	if(a2[1]!=0&&a3[1]==0){
		for(int i=n/2;i>=1;i--){
			int plas=max(a2[m],a1[m]);
			if(plas==a1[m]) cnt[1]++;
			else if(plas==a2[m]) cnt[2]++;
			if(cnt[1]>n/2&&cnt[2]<n/2) plas=a2[m];
			if(cnt[1]<n/2&&cnt[2]>n/2) plas=a1[m];
			if(cnt[1]>n/2&&cnt[2]>n/2) plas=a3[m];
			maxn+=plas;
			m--;
		}
	}
	if(a2[1]==0&&a3[1]==0){
		for(int i=n/2;i>=1;i--){
			maxn+=a1[m];
			m--; 
		}
	}
	cout<<maxn<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}