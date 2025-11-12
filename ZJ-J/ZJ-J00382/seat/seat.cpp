#include<bits/stdc++.h>
//#define int long long

using namespace std;

int n,m,a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	int sum=a[1];
	int step=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(a[(i-1)*m+j]>sum)step++;
	int lie=(step%m?step/m+1:step/m);
	int hang=(step%(2*m)>m?(2*m-step%(2*m))+1:step%(2*m));
	cout<<lie<<" "<<hang;
	return 0;
}
