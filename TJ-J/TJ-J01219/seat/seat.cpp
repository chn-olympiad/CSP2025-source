#include<bits/stdc++.h>
int n,m,a[130],a1;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			a1=i;
			break;
		}
	}
	if(a1%n==0){
		cout<<a1/n<<" "<<n;
	}else{
		cout<<a1/n+1<<" "<<a1/n;
	}
	return 0;
}
