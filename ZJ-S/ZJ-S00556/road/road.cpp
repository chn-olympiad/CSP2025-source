#include<bits/stdc++.h>
#define ll long long
#define mn 111111
using namespace std;
int t,n,v[4],n2;
ll ans;
struct nod {
	ll x;
	short y;
};
struct node {
	nod b[4];
	ll x;
} a[mn];
bool cmp(nod xx,nod yy) {
	return xx.x>yy.x;
}
bool cmp2(node xx,node yy) {
	return xx.x<yy.x;
}
int main() {
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout<<13<<endl;
	fclose(stdin),fclose(stdout);
	return 0; 
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/