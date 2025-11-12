#include <bits/stdc++.h>
using namespace std;

//#define ll long long
//const int maxn=1e5+5;

/*
long long quickpower(long long a, long long b) {
	long long ans = 1, base = a;
	while (b > 0) {
		if (b & 1)
			ans = ans * base;
		base = base * base;
		b >>= 1;
	}
	return ans;
}
*/

/*
int find(int a){
	if(fa[a]==a) return a;
	else return fa[a]=find(fa[a]);
}
void merge(int a,int b){
	int fx=find(a);int fy=find(b);
	if(fx!=fy){
		fa[fx]=fy;
	}
}
*/
int n,m,k;
int main() {

	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long num;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		num+=w;
	}
	for(int i=1;i<=k;i++){
		int r;
		for(int j=1;j<=n+1;j++){
			cin>>r;
		}
	}
	cout<<num<<endl;

	/*
	//quickpower
	long long a, b;
	cin >> a >> b;
	cout << quickpower(a, b) << endl;
	*/


	return 0;
}
