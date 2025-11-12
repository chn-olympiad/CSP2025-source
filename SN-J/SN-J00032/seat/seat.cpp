#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[230];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int l=a[1];
	sort(a,n*m+2+a);
	for(int i=n*m;i>=1;i--){
		if(a[i]==l){
			cout<<i%n<<" "<<i/m;
			break;
		}else{
			a[i]+=0;
		}
	}
	return 0;
} 
