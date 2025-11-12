#include <bits/stdc++.h>

using namespace std;
int n,m,a[105],tmp,id;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*m+j];
	tmp=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[i]==tmp){id=n*m-i;break;}
	int nnn=id/m;
	if(nnn%2) cout<<nnn+1<<' '<<m-id%m;
	else cout<<nnn+1<<' '<<id%m+1;
	return 0;
}
