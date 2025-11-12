#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(n*m==1){
		cout<<n<<" "<<m;
	}else{
		sort(a,a+n);
	}
	return 0;
}
