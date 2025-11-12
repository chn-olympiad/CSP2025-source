#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int t,n,k[10],ans;
vector<int> v[100005];

int dfs(int i){
	if(i==n) return 0;
	int sum=-1;
	for(int j=0;j<3;j++){
		if(k[j]+1<=n/2){
			k[j]++;
			sum=max(sum,dfs(i+1)+v[i][j]);
			k[j]--;
		}
	}
	return sum;
}

signed main(){
	FI("club");
	FO("club");
	cin>>t;
	while(t--){
		ans=0;
		for(int i=0;i<n;i++)v[i].clear();
		memset(k,0,sizeof k);
		cin>>n;
		for(int i=0,x,y,z;i<n;i++){
			cin>>x>>y>>z;
			v[i].push_back(x);
			v[i].push_back(y);
			v[i].push_back(z);
		}
//		sort(v.begin(),v.end(),cmp);
		cout<<dfs(0)<<endl;
	}
	return 0;
}
