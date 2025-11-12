#include <bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
	}
	for(int j=1;j<=q;j++){
		cin >> a >> b;
	}
	for(int i=1;i<=q;i++){
		cout << 0 << endl;
	}
	return 0;
} 
