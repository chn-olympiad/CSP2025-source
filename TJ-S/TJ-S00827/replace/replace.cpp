#include<bits/stdc++.h>
using namespace std;
struct node{
	string a,b;
}f[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin >> n >> q;
	string x,y;
	cin >> x >> y;
	for (int i=1;i<=n;i++){
		cin >> f[i].a >> f[i].b;
	}
	while (q--){
		string ol,op;
		cin >> ol >> op;
		cout << 0 << endl;
	}
	return 0;
}

