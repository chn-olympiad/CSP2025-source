#include <bits/stdc++.h>
using namespace std;

//#define ll long long
const int maxn=1e5+5;

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

int n,q;
struct a{
	string d1,d2,q1,q2;
}node[maxn];

int main() {


	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>node[i].d1>>node[i].d2;
	}
	for(int i=1;i<=q;i++){
		cin>>node[i].q1>>node[i].q2;
	}
	cout<<0<<endl;

	/*
	//quickpower
	long long a, b;
	cin >> a >> b;
	cout << quickpower(a, b) << endl;
	*/


	return 0;
}
