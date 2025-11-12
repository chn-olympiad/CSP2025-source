#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[10005];
int res;//记录要到找的数
int cnt;

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	res=a[1];

	sort(a+1,a+n*m+1,cmp);
//	for(int i=1; i<=n*m; i++) {
//		cout<<a[i]<<endl;
//	}
	for(int i=1; i<=n; i++) {
		if(i%2==0) { //偶数时=>倒
			for(int j=m; j>=1; j--) {
				cnt++;
				if(a[cnt]==res){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		} else { //奇数时=>正
			for(int j=1; j<=m; j++) {
				cnt++;
				if(a[cnt]==res){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
//神兽保佑，代码无 bug !!!
//#Shang4Shan3Ruo6Shui4

