#include <bits/stdc++.h>
using namespace std;
struct st1{
	int a,b,c;
}s[1000010];
struct st2{
	int f;
	int l[1000010];
}x[30];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>s[i].a>>s[i].b>>s[i].c;
	for(int i=1;i<=k;i++){
		cin>>x[i].f;
		for(int j=1;j<=n;j++) cin>>x[i].l[j];
	}
	long long sum=0;
	for(int i=1;i<=m;i++) sum+=s[i].c;
	cout<<sum;
	return 0;
}