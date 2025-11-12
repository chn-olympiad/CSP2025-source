#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int>a;
int ans=0;
void dfs(int s,int e,int m,int t,int m2){
	if(s==e){
		if(m>t and m2>=2){
			ans++;
		}
		return;
	}
	dfs(s+1,e,m,t,m2);
	dfs(s+1,e,m+a[s],t,m2+1);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	a=vector<int>(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int an=0;
	for(int i=2;i<n;i++){
		ans=0;
		dfs(0,i,0,a[i],0);
		an=(an+ans)%998244353;
	}
	cout<<an;
	return 0;
}
