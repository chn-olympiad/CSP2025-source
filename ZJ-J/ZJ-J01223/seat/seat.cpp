#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20;
int a[N][N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(i==1&&j==1) f=a[i][j];
			else{
				if(a[i][j]>f) cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				cnt--;
				if(cnt==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cnt--;
				if(cnt==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
