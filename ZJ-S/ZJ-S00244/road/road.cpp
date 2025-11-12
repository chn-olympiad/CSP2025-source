#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long i,n,j,m,k,a[100000],c[100000],b[100000];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1; i<=m; i++) {
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]<a[i]) swap(a[i],b[i]);
	}
	for(i=1; i<=m; i++)
		for(j=1; j<=m; j++) {
			if(a[i]==a[j]&&b[i]==b[j]&&i!=j) {
				c[i]=min(c[i],c[j]);
				c[j]=11451400;
			}
		}
	long long ans=0;
	for(i=1; i<=m; i++) {if(c[i]!=11451400)ans+=c[i];}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}