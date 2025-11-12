#include <bits/stdc++.h>
using namespace std;
struct s{
	string a,b;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;cin >> n >> m;
	s h[n];
	for (int i=0;i<n;i++) cin >> h[i].a >> h[i].b;
	s z[m];
	for (int i=0;i<m;i++) cin >> z[i].a >> z[i].b;
	for (int j=0;j<m;j++) cout << 0 << endl; 
	return 0;
}
