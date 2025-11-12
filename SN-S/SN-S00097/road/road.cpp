#include<bits/stdc++.h>
using namespace std;
int c[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,e,d,f;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>a>>b>>f>>d>>e;
	}
	sort(c+1,c+m+1);
	int s=0;
	for(int i=1;i<=n-1;i++){
		s+=c[i];
	}
	cout<<s;
	return 0;
}
