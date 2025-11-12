#include<bits/stdc++.h>
using namespace std;
int n,m,t,t2,myg,k=1,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	cin>>myg;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>=myg)k++;
	}
	ans1=k/n;
	if(k%n!=0)ans1++;
	
	t2=k%(2*n);
	if(t2==0)t2=2*n;
	if(1<=t2&&t2<=n)ans2=t2;
	else ans2=2*n+1-t2;
	
	cout<<ans1<<' '<<ans2;
}