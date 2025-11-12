//SN-J00338 张巍骞 曲江第一中学
#include<bits/stdc++.h>
using namespace std;
const int N =5e5+10;
int n,k;
int a[N];
int p[N];
int cnt;
struct node {
	int x;
	int y;
} u[N];
int asd;
void qwe(int v,int p,int h) {
	for(int j =v+1; j<=cnt; j++) {
		if(u[j].x>p) {
			h++;
			p = u[j].y;
			qwe(j,p,h);
		}
	}
	asd = h+1;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i = 1; i<= n; i++) {
		cin>>a[i];
		p[i] = p[i-1]^a[i];
	}
	int maxx = 0;
	for(int i = 1; i<=n; i++) {
		for(int j = i; j<= n; j++) {
			if(p[j]-p[i-1]==k||p[j]-p[i-1]==-k) {
				u[++cnt].x =i;
				u[cnt].y = j;
			}
		}
	}
	for(int i = 1; i<= cnt; i++) {
		asd = 0;
		int p=u[i].y;
		qwe(i,p,0);
		maxx = max(maxx,asd);
	}
	cout<<maxx;
	return 0;
}
