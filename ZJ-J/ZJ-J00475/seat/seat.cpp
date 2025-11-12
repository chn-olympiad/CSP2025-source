#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m,b,num=1;
int a[105];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+2+n*m,cmp);
	for(int i=1; i<=m; i++) {
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				if(a[num]==b) {
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		} else {
			for(int j=n; j>=1; j--) {
				if(a[num]==b) {
					cout<<i<<" "<<j;
					return 0;
				}
				num++;
			}
		}
	}
	return 0;
}
