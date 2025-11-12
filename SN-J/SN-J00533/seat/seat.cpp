//SN-J00533 lihaoze xianfulunzhongxue
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[105],xiao;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	xiao=a[0];
	sort(a,a+n*m,cmp);
	int ans=0;//shi ji bei " n "
	for(int i=0;i<n*m;i++){
		if(a[i]==xiao){
			xiao=i+1;//xuan shou de ming ci
		}
	}
	int j=0;
	while(j<xiao){
		j+=n;
		ans++;
	}
	if(ans*n==xiao){
		if(ans%2==0){
			cout<<ans<<" "<<1;
		}
		else{
			cout<<ans<<" "<<n;
		}
	}
	else{
		if(ans%2==0){
			cout<<ans<<" "<<1+ans*n-xiao;
		}
		else{
			cout<<ans<<" "<<n-ans*n+xiao;
		}
	}
	return 0;
}
