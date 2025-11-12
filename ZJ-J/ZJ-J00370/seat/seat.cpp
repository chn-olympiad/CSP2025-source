#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=200,M=1e5+7,MOD=1e9+7;
int a[N],x,n,m,flag;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		flag++;
		if(x==a[i]) break;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				sum++;
				if(sum==flag){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				sum++;
				if(sum==flag){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
