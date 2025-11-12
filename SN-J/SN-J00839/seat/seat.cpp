#include<bits/stdc++.h>
using namespace std;
int n,m,a[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;i<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<n<<m;
	return 0;
}
