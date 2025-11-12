#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=1e2+10;
int a[N];
int a1;
bool cmp(int &x,int &y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x,y;
	x=y=1;
	int cnt=1;
	while (a[cnt]!=a1){
		if (a[cnt]==a1){
			break;
		}
		if (x%2==1){
			y++;
			if (y==n+1){
				x++;
				y=n;
			}
		}else{
			y--;
			if (y==0){
				x++;
				y=1;
			}
		}
		cnt++;
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}
