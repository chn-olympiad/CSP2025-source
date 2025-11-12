#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p=0,k,t;
	cin>>n>>m;
	for(int i=1; i<=m*n; i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1; i<=m*n; i++){
		if(k==a[i]){
			t=i;
		}
	}
	t=m*n-t+1;
	cout<<t<<endl;
	cout<<t/n<<" "<<t-(t/n-1)*n;
	return 0;
}