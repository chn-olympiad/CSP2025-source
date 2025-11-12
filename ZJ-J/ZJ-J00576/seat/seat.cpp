#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[(i-1)*m+j];
		}
	}
	int x=a[1],y=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;++i){
		if(a[i]==x){
			y=i;
			break;
		}
	}
	int k=(y+n-1)/n,t=y-(k-1)*n;
	if((k&1)==0){
		t=m-t+1;
	}
	cout<<k<<' '<<t;
	return 0;
}

