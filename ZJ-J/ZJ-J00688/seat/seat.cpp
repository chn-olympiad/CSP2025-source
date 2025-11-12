#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],m,now;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) now++;
	}
	if(m==0){
		return 0;
	}
	now++;
	if(((now-1)/n)%2==0){
		cout<<(now-1)/n+1<<" "<<(now-1)%n+1;
		return 0;	
	}else{
		cout<<(now-1)/n+1<<" "<<n-(now-1)%n;
	}
	return 0;
}
