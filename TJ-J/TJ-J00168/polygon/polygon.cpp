#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int la(long long x){//最后一位1的位置 
	return -((-x^x)>>1);
}
int fpow(int x){
	int ans=0;
	while(x!=2){
		x=x/2;
		ans++;
		if(x==0){
			ans--;
			break;
		}
	}
	return ans+1;
}
int cnt(long long x){
	int ans=0;
	while(x!=0){
		x-=la(x);
		if(x==0){
			break;
		}
		ans+=a[n-fpow(la(x))+1];
		cout<<n-fpow(la(x))+1<<" ";
	}
	cout<<endl;
	return ans;
}
int ma(long long x){
	int ans=0;
	while(x!=0){
		x-=la(x);
		ans=max(a[fpow(la(x))]*2,ans);
	}
	return ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=(1<<n);i++){
		if(cnt(i)>ma(i)){
			ans++;
			cout<<"aaa\n";
			ans=ans%998244353;
		}
	}
	cout<<endl<<ans;
	return 0;
}
