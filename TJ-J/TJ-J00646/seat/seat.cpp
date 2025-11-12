#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=0,sum=1;
	cin>>x;
	for(int i=2;i<=(n*m);i++){
		int y;
		cin>>y;
		if(y>x){
			sum++;
		}
	}
	if(sum%n==0){
		if((sum/n)%2==1){
			cout<<(sum/n)<<" "<<n<<"\n";
			return 0;
		}else if((sum/n)%2==0){
			cout<<(sum/n)<<" "<<1<<"\n";
			return 0;
		}
	}else{
		if((sum/n)%2==0){
			cout<<(sum/n+1)<<" "<<(sum%n)<<"\n";
			return 0;
		}else if((sum/n)%2==1){
			cout<<(sum/n+1)<<" "<<(n-(sum%n)+1)<<"\n";
			return 0;
		}
	}
	return 0;
}
//rp++
