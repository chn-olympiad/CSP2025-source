#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt;
int R=1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int t;
		cin>>t;
		if(i==1){
			r=t;
		}
		else{
			if(t>r)	R++;
		}	
	}
	int a=R/m;
	int b=R-n*a;
	if(a%2==0){
		cout<<a+1<<" "<<b;
	}
	else{
		cout<<a+1<<" "<<n-b+1;
	}
	return 0;
}
