#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int f[N][N],n,m;
int a[N];
int cnt;
int x,y;
int sol;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	sol=a[1];
//	cout<<n<<' '<<m<<'\n';
//	for(int i=1;i<=n*m;i++)cout<<a[i]<<' ';
	sort(a+1,a+n*m+1,cmp);
	x=1,y=1;
	f[1][1]=a[1];cnt++;
	while(cnt<n*m){
		if(y%2==1&&x==n){
			y++;
		}else if(y%2==0&&x==1){
			y++;
		}
		else if(y%2==0){
			x--;
		}else if(y%2==1){
			x++;
		}f[x][y]=a[++cnt];
//		cout<<x<<' '<<y<<' '<<f[x][y]<<'\n';
//		cout<<x<<' '<<y<<' '<<a[cnt]<<"\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
//			cout<<f[i][j]<<' ';
			if(sol==f[i][j]){
				cout<<j<<' '<<i<<"\n";
				return 0;
			}
		}
//		cout<<"\n";
	}
//	cout<<sol<<'\n';
	return 0;
}
