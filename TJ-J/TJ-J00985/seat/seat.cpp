#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[9999999];
	cin>>n>>m;
	long long len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	long long s=a[1],x=1,y=0,z=1;
	sort(a+1,a+len+1);
	while(true){
		if(x%2==0){
			y--;
		}else{
			y++;
		}
		if(a[z]==s){
			cout<<x<<" "<<y;
			return 0;
		}
		if(z!=1){
			if(y==1 || y==n){
				x++;
			}
		}else{
			if(y==n){
				x++;
			}
		}
		z++;
	}
	return 0;
}
