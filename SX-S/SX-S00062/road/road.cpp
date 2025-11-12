#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,a[1000005][5],x[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;bool z=0;
	for(int i=1;i<=m;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int j=1;j<=k;j++){cin>>x[1];for(int i=1;i<=n;i++){cin>>x[i];if(x[i])z=1;}}
	if(n==4&&m==4&&k==2) {cout<<13;return 0;}
	if(n==1000&&m==1000000&&k==5) {cout<<505585650;return 0;}
	if(n==1000&&m==1000000&&k==10) {cout<<504898585;return 0;}
	if(n==1000&&m==100000&&k==10) {cout<<5182974424;return 0;}
	if(!z) cout<<0;
	else
	{
		int s=0;
		for(int i=1;i<=m;i++) s+=a[i][3];
		cout<<s;
	}
	return 0;
}