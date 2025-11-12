#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int a[N][4];
int f[205][205][205];

void SolveAA(int n){
	int ans=0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.emplace_back(a[i][1]);
	}sort(v.begin(),v.end(),greater<int>());
	for(int i=1;i<=n/2;i++){
		ans+=v[i-1];
	}cout<<ans<<endl;
	return;
}

void Solve(){
	memset(a,0,sizeof a);
	memset(f,0,sizeof f);
	int n,ans=0;
	bool aa=1,bb=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0||a[i][3]!=0) aa=0;
	}if(aa){
		SolveAA(n);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i-j;k++){
				int l=i-j-k;
				if(l<0||j>n/2||k>n/2||l>n/2) continue;
				if(j>0) f[j][k][l]=max(f[j][k][l],f[j-1][k][l]+a[i][1]);
				if(k>0) f[j][k][l]=max(f[j][k][l],f[j][k-1][l]+a[i][2]);
				if(l>0) f[j][k][l]=max(f[j][k][l],f[j][k][l-1]+a[i][3]);
				if(i==n) ans=max(ans,f[j][k][l]);
			}
		}
	}cout<<ans<<endl;
	
}


int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){	
		Solve();
	}
	
	return 0;
}

// TRAGEDY