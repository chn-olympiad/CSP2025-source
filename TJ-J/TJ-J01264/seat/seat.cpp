#include<bits/stdc++.h>
using namespace std;
int n,m,a,temp,t=0,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for (int i=0;i<n*m-1;i++){
		cin>>temp;
		if (temp>a){
			t++;
		}
	}
	ans1=t/n;
	if (ans1%2==0){
		ans2=t%n+1;
	}
	else{
		ans2=m-t%n;
	}
	cout<<ans1+1<<" "<<ans2;
	return 0;
}
