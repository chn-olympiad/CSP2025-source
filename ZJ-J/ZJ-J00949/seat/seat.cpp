#include<bits/stdc++.h>
using namespace std;
const int N=10e5+5;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q,All=m*n,i=0,fir=0,sum=1;
	while(All--){
		i++;
		cin>>q;
		if(i==1){
			fir=q;
			continue;
		}else if(fir<q) sum++; 
	}
	if(sum%n==0) {
		cout<<sum/n<<" ";
		if((sum/n)%2==1) cout<<m;
		else cout<<1;
	}else {
		cout<<sum/n+1<<" ";
		if((sum/n+1)%2==1){
			cout<<sum%n;
		}else cout<<m-(sum%n)+1;
	}
	return 0;
}