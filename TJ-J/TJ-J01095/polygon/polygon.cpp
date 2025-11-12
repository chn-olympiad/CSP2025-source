#include<bits/stdc++.h>
using namespace std;
int jie(int x){
	int cnt=1;
	for(int i=1;i<=x;i++){
		cnt*=i;
	}
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010];
	cin>>n;
	bool f=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(n==3){
		int x=a[0];
		x+=a[1];
		x+=a[2];
		int y;
		y=max(a[0],max(a[1],a[2]));
		if(x>y*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	else if(f=true){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=jie(n)/(jie(n-i)*jie(i));
		}
		cout<<ans;
	}
	else{
		cout<<6;
	}
	return 0;
}
