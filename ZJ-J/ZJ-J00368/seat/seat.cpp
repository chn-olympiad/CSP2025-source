#include<bits/stdc++.h>
using namespace std;
int a[100001],n,m,x=0,t=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int b;
		cin>>b;
		if(i==1){
			x=b;
		}
		if(b>x) t++;
	}
	int ans=1,sum=1,ok=0;
	for(int i=1;i<=t;i++){
		if(ok==0){
			if(ans==n){
				ok=1;
				sum++;
			}
			else{
				ans++;
			}
		}
		else{
			if(ans==1){
				ok=0;
				sum++;
			}
			else{
				ans--;
			}
		}
	}
	cout<<sum<<" "<<ans;
	return 0;
}


