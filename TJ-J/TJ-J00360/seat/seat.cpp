#include<bits/stdc++.h>
using namespace std;
int n,m,ai=1,b,x,chu;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    for(int i =2;i<=n*m;i++){
    	cin>>b;
    	if(b>=x) ai++;
	}
	if(ai%m==0){
		chu=ai/m;
		if(chu%2==1){
			cout<<chu<<" "<<n;
		}else{
			cout<<chu<<" "<<1;
		}
		return 0;
	}else{
		chu=ai/m+1;
	}
	if(chu%2==1){
		cout<<chu<<" "<<ai%m;
	}else{
		cout<<chu<<" "<<n-ai%m+1;
	}
	return 0;
}

