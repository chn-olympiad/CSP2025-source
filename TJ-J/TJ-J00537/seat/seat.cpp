#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;	//n为行数，m为列数 
	int r;
	cin>>r;
	int wz=1;
	for(int i=1;i<n*m;i++){
		int fs;
		cin>>fs;
		if(fs>r){
			wz+=1;	
		}
	}
	int ans1=0,ans2=0;	//ans1为列，ans2为行 
	ans1=wz/(2*n)+1;
	ans1=ans1*2-1;
	ans2=wz%(2*n);
	if(ans2>n){
		ans1+=1;
		ans2-=n;
		ans2=n-ans2+1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
