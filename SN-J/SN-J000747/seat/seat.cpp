#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]>a[1])
			    cnt++;
		}
	}
	cnt=cnt+1;
	int mod=cnt%n,seat=cnt/n;
	if(mod==0){
		if(seat%2==0){
			cout<<seat<<" "<<1;
			return 0;
		}else if(seat%2==1){
			cout<<seat<<" "<<n;
			return 0;
		}
	}else if(mod!=0){
		seat++;
		if(seat%2==0){
			cout<<seat<<" "<<n-mod+1;
			return 0;
		}else if(seat%2==1){
			cout<<seat<<" "<<mod;
			return 0;
		}
	}
	return 0;
}

