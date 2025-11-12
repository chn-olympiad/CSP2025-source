#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500];
int R;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=m*n;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+x+1,greater<int>());
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==R){
				cout<<i<<' ';
				if(i%2==1){
					cout<<j;
				}else{
					cout<<n-j+1;
				}
			}
		}
	}
	return 0;
} 
