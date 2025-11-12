#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[15][15];
	int n,m;int x=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		for(int j=1;i<=m;j++){
			cin>>a[i][j];
		}
	}
	int s=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;i<=m;j++){
			if(s<a[i][j]){
				x++;
			}
		}
	}
	if(x>m){
		n=x/m;
		m=x%m;
	}
	cout<<n<<" "<<m;
	return 0;
}
