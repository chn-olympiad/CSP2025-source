#include<bits/stdc++.h>
using namespace std;
int l[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>l[i]; 
	}
	sort(l+1,l+m+1);
	int ans=0;
	for(int i=1;i<n;i++){
		ans+=l[i];
	}
	cout<<ans;
	return 0;
}

