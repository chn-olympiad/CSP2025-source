#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	sort(c+1,c+m+1);
	for(int i=1;i<=n-1;i++){
		sum+=c[i];
	}
	cout<<sum;
	return 0;
}
