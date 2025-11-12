#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c[110],b,id,pm,ans; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b;
		if(i==1) id=b;
		c[b]=1;
	}
	int tmp=1;
	for(int i=100;i>=1;i--){
		if(c[i]){
			a[tmp]=i;
			if(a[tmp]==id) pm=tmp;
			tmp++;
		}
	}
	ans=(pm-1)/n+1;
	if(ans%2){
		if(pm%n)
		cout<<ans<<" "<<pm%n;
		else cout<<ans<<" "<<m;
	}else{
		cout<<ans<<" "<<m-pm%n+1;
	}
	return 0;
} 
