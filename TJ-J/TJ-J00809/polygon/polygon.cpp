#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod= 998244353; 
int n;
vector<int>a;
ll ans=0;
void dfs(int pos,ll sum,int mx,int ct){
	if(pos>=n){
		if(sum>2*mx&&ct>=3){
			ans++;
		}
		return;
	}
	int new_mx=max(mx,a[pos]);
	dfs(pos+1,sum+a[pos],new_mx,ct+1);
	dfs(pos+1,sum,mx,ct);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans%mod<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
