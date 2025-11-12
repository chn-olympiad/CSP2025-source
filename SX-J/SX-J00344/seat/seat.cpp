#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r".stdin);
	freopen("seat.out","w".stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=n*m;
		cin>>a[i];
	}
		
	
	cout<<n<<m;
	return 0;
}
