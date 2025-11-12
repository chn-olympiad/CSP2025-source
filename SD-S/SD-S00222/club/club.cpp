#include<bits/stdc++.h>
#define debug 0
using namespace std;


struct man {
	int m[4];

	bool operator<(const man &aa) {
		return m[0]>aa.m[0];
	}
};
man a[100010];
int n,ans;

int choosed[3];

bool sp2=0;
int dfs(int i,int sum) {
	if(i==n){
		return sum;
	}
	int ans1=0;
	for(int j=0; j<3-sp2; j++) {
		if(choosed[j]>=n/2)continue;
		choosed[j]++;
		ans1=max(dfs(i+1,sum+a[i].m[j]),ans1);
		choosed[j]--;
	}
	return ans1;
}


void solve() {
	choosed[0]=0;
	choosed[1]=0;
	choosed[2]=0;
	ans=0;

	cin>>n;
	bool sp1=1;
	sp2=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			cin>>a[i].m[j];
		}
		if(a[i].m[1]||a[i].m[2]) {
			sp1=0;
		}
		
		if(a[i].m[2]){
			sp2=0;
		}
	}

	if(n==2) {
		int ans=0;
		for(int i=0; i<3; i++) {
			int aans=0;
			for(int j=0; j<3; j++) {
				if(i!=j) {
					aans=max(a[1].m[j]+a[0].m[i],aans);
				}
			}
			ans=max(ans,aans);
		}
		cout<<ans<<endl;
		return ;
	}

	if(sp1) {
		int ans;
		sort(a,a+n);

		for(int i=0; i<n/2; i++) {
			ans+=a[i].m[0];
		}
		cout<<ans<<endl;
		return;
	}
	
	if(n<=17)
		cout<<dfs(0,0)<<endl;
		
	else{
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=max(max(a[i].m[0],a[i].m[1]),a[i].m[2]);
		}
		cout<<ans<<endl;
	}
}

int main() {
	cin.tie(0);
	if(!debug) {
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
	}

	int t;
	cin>>t;
	while(t--) {
		solve();
	}


	return 0;
}
