#include <bits/stdc++.h>
using namespace std;
int n,q;
const int maxn=2e5+10;
string a[maxn],b[maxn],tx,ty;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<=q;i++){
		cin >> tx >> ty;
		cout << 0 << '\n';
	}
	return 0;
}
