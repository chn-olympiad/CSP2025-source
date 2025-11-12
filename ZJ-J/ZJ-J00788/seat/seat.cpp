#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j];
		}
	a[0]=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==a[0]){
			int c=(i-1)/m+1;
			i=(i-1)%m+1;
			if(c%2==0) i=m-i+1;
			cout<<c<<" "<<i;
			break;
		}
	}
	return 0;
}
