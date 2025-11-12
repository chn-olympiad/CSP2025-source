#include<bits/stdc++.h> 
using namespace std;
int a[100][100],aa[100000];
int c[110] = {0};
bool cmp (int  x,int y) {
	return x > y;
}
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ap = 0;
	for(int i = 1;i <= n*m;i++) {
		cin>>aa[i];
	}ap = aa[1];
	sort(aa+1,aa+n*m+1,cmp);
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) {
			a[j][i] = aa[(i-1)*n+j];
		}
	}
	for(int j = 1;j <= n/2;j++) {
		for(int i = 0;i <= m;i+=2) {
			swap(a[j][i],a[n-j+1][i]);
		} 
	}
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) {
			if(a[j][i] == ap) {
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
} 
