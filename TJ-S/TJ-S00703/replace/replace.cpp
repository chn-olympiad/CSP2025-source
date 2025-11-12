#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin >> n >> q;
	string a[n+1][3],t[q+1][3];
	for(int i=1;i<=n;i++) cin >> a[i][1] >> a[i][2];
	for(int i=1;i<=q;i++) cin >> t[i][1] >> t[i][2];
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			if(t[i][1]==a[j][1]&&t[i][2]==a[j][2]) ans++;
		}
    }
	cout << ans;
	return 0; 
}
