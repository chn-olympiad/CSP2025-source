#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0;
int la(long long x){//最后一位1的位置 
	return -((-x^x)>>1);
}
int xr(long long x,long long y){
	int re=0,l=0;
	while(x!=0||y!=0){
		if(la(x)==la(y)){
			l++;
		}else{
			re+=pow(2,l);
			l++;
		}
		x=x>>1;
		y=y>>1;
	}
	return re;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=a[1];
	for(int i=1,j=1;j<=n;j++){
		if(cnt==k){
			//cout<<"ans++ "<<i<<" "<<j<<endl;
			i=j+1;
			cnt=a[i];
			ans++;
		}
		if(j-i>0){
			cnt=xr(cnt,a[j]);
		}
		if(cnt==k){
			//cout<<"ans++ "<<i<<" "<<j<<endl;
			i=j+1;
			cnt=a[i];
			ans++;
		}
		//cout<<"cnt "<<cnt<<" "<<i<<" "<<j<<endl;
	}
	cout<<ans;
	return 0;
}
