#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int f(int x,int y){
	if(x==0) return y;
	if(y==0) return x;
	int b[25],c[25],d[25],e[25],z[25];
	int sum=0,ansk1=25,ansk2=25;
	for(int i=-25;i<=25;i++) e[i]=1;
	for(int i=-25;i<=25;i++) b[i]=1;
	for(int i=-25;i<=25;i++) c[i]=1;
	for(int i=-25;i<=25;i++) d[i]=1;
	while(1){
		if(x==0){
			break;
		}
		else{
			b[ansk1]=x%2;
			x=x/2;
			ansk1--;
		}
	}
	while(1){
		if(y==0){
			break;
		}
		else{
			c[ansk2]=y%2;
			y=y/2;
			ansk2--;
		}
	}
	for(int i=1;i<=25-ansk1;i++) d[i]=b[i+ansk1];
	for(int i=1;i<=25-ansk2;i++) e[i]=c[i+ansk2];
	int ansk3=max(25-ansk1,25-ansk2);
	if(ansk3==ansk2){
		int abc=ansk2-ansk1;
		for(int i=ansk3;i>=1;i--){
			if(d[i]==1&&e[i-abc]==1) z[i]=0;
			else if(d[i]==0&&e[i-abc]==0) z[i]=0;
			else z[i]=1;
		}   
		int l=1;
		for(int i=ansk3;i>=1;i--){
			sum=sum+z[i]*l;
			l=l*2;
		}
		return sum;
	}
	else{
		int abc2=ansk1-ansk2;
		for(int i=ansk3;i>=1;i--){
			if(e[i]==1&&d[i-abc2]==1) z[i]=0;
			else if(e[i]==0&&d[i-abc2]==0) z[i]=0;
			else z[i]=1;
		}
		int l=1;
		for(int i=ansk3;i>=1;i--){
			sum=sum+z[i]*l;
			l=l*2;
		}
		return sum;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","r",stdin);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
	}
	for(int i=1;i<n;i++){
		int qq=a[i];
		for(int j=i+1;j<=n;j++){
			qq=f(qq,a[j]);
			if(qq==k) ans++;
		}
	}
	cout<<ans;
	return 0;
}
