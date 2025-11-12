#include<bits/stdc++.h>
using namespace std;
int a[1000005],b,k,c=1,d=1,ans;
int xorr(int x,int y){
	if(x==y){
        return a[x];
	}
	return (a[x]^xorr(x-1,y));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>b>>k;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	while(1){
		if(d==b+1){
			break;
		}
		if(xorr(d,c)==k){
			ans++;
			c=d+1;
		}
		d++;
	}
	cout<<ans;
}
