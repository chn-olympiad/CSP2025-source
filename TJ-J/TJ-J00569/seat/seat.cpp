#include<bits/stdc++.h>
using namespace std;
int b[13][13],a[108];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s;
	cin>>s;
	a[1]=s;
	for(int i=2; i<=(n*m); i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+(n*m),cmp);
	int l=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			b[i][j]=a[l++];
			}
		if(i%2==0)
			sort(b[i]+1,b[i]+1+m);
		else
			sort(b[i]+1,b[i]+1+m,cmp);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(b[i][j]==s) {
				cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
}
