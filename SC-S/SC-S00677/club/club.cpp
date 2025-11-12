#include<bits/stdc++.h>
using namespace std;

const int N=10e5;
int a[N][5];

int cnt[5];

int dfs(int k,int n){
	if(k==n)return 0;
	int ans=0xcfcfcfcf;
	for(int i=0;i<3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			ans=max(ans,dfs(k+1,n)+a[k][i]);
			cnt[i]--;
		}
	}
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(;t;t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		cout<<dfs(0,n)<<endl;
	}
	return 0;
}
