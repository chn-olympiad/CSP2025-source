#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200;
int a[N];

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	// fhr can help me AK the contest!
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tot=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*m+j]==tot){
				cout<<i<<' '<<(n-j+1)<<endl;
				return 0;
			}
		}
	}
	return 0;
}
/*
3 2
3 1 2 4 5 6
*/