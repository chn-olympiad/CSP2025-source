#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];
int maxx=0;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx = max(maxx,a[i]);
		ans+=a[i];
	}
	if(n<3){
		cout<<0;
	}else if(ans > 2*maxx){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	
	return 0;
}
