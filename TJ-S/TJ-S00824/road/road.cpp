#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cin in
#define cout out
int main(){
	fstream in,out;
	in.open("a.in",ios::in);
	out.open("b.out",ios::out);
	int n,m,k;
	cin >> n >> m >> k;
	ll sum=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		sum+=w;
	}
	cout << sum << endl;
	return 0;
}