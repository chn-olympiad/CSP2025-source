#include<bits/stdc++.h>
#define int long long
#define FREOPEN(x) freopen(x ".in","r",stdin),freopen(x ".out","w",stdout);
using namespace std;
struct node {
	int num,xs;
} a[105];
int dy[2]={-1,1};
bool cmp(node a,node b) {
	return a.num>b.num;
} signed main() {
	FREOPEN("seat")
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		int x;
		cin>>x;
		a[i].num=x;
		a[i].xs=i;
	} sort(a+1,a+n*m+1,cmp);
	int x=1,y=2,flag=1,flag2=0;
	if(a[1].xs==1) {
		cout<<1<<" "<<1;
		return 0;
	} for(int i=2;i<=n*m;i++) {
		if(a[i].xs==1) {
			cout<<x<<" "<<y;
		} if(y==1) {
			flag=1;
			if(x%2==1) {
				y+=dy[flag];
			} if(x%2==0) {
				x++;
			} continue;
		} if(y==n) {
			flag=0;
			if(x%2==0) {
				y+=dy[flag];
			} if(x%2==1) {
				x++;
			} continue;
		} y+=dy[flag];
	} return 0;
}
