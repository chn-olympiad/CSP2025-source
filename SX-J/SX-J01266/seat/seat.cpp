#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],z;
long long cmp(long long xx,long long yy){
	return xx>yy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	z=a[1];
	sort(a+1,a+1+(n*m),cmp);
	long long i=0,x=1,y=0,f=0;
	while(1){
		i++;
		if(f==1){	
			y--;
			if(y<1){
				y++;
				x++;
				f=0;
			}
		}else{
			y++;
			if(y>m){
				y--;
				x++;
				f=1;
			}
		}
		if(a[i]==z){
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
}
