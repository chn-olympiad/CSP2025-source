#include <bits/stdc++.h>
using namespace std;
string a[200010],b[200010],c[200010],d[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >>a[i] >> b[i];
	}
	for(int i=1;i<=q;i++){
		cin >> c[i] >> d[i];
	}
	return 0;
}
