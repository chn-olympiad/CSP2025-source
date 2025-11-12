//T2 PASS 9:20 ALL 样例
//为啥先列再行呀，条了20分钟 
#include<bits/stdc++.h>
#define int long long
const int N = 1E3+10;
using namespace std;
int c,r,n,m,fs,pos;
int a[N];
int mp[N][N];
int cmp(int x,int y) {
	return x>y;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1; i<=s; i++) {
		cin>>a[i];
	}
	fs=a[1];
	sort(a+1,a+s+1,cmp);
	int now=1;
	for(int i=1; i<=m; i++) { //模拟填充矩阵
		if(i%2==1) {
			for(int j=1; j<=n; j++) {
				mp[j][i]=a[now];
				now++;
			}
		} else {
			for(int j=n; j>=1; j--) {
				mp[j][i]=a[now];
				now++;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(mp[i][j]==fs) {
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
