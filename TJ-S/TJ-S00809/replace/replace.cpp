#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node {
	string a,b;
};
node ans[maxn];
int main(){
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for (int i=1;i<=n;i++){
		cin >> ans[i].a >> ans[i].b;
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
