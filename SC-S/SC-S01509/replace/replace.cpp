#include <bits/stdc++.h>
using namespace std;

int n,q,ans;
string a[200005][3],b[200005][3];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=2;j++) {
			cin>>a[i][j];
		}
	}
	while(q) {
		ans=0;
		for(int j=1;j<=2;j++) {
			cin>>b[q][j];
		}
		for(int j=1;j<=n;j++) {
			if(b[q][1]==a[j][1] &&b[q][2]==a[j][2]) {
				ans++;break;
			}
		}
		cout<<ans<<'\n';
		q--;
	}
	
	return 0;
}
