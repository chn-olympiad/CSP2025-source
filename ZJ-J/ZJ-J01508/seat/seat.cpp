#include<bits/stdc++.h>
using namespace std;
int n,m,fenshu[1000],r,weizhi,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
			cin>>fenshu[i];
	}
	r=fenshu[0];
	sort(fenshu,fenshu+n*m);
	for(int i=0;i<n*m;i++){
		if(fenshu[i]==r){
			weizhi=n*m-i;
			break;
		}
	}
	x=weizhi/n;
	if(x*n!=weizhi){
		x++;
	}
	if(x%2==1){
		if(weizhi%n==0){
			y=n;
		}else{
			y=weizhi%n;
		}
	}else{
		if(weizhi%n==0){
			y=1;
		}else{
			y=n-weizhi%n+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}