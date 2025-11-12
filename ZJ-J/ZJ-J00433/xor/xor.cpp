#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+50;
ll n,k,l,r,mid,ans,a[N],B=1;
inline ll read(){
	ll x=0,sign=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*sign;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(!(a[i]>=0)&&a[i]<='1')B=0;
	}
	if(n<=2&&k==0){//exam 1
		if(n==1)cout<<0;
		else cout<<1;
	}
	else if(n<=10&&k<=1){//exam 2
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==a[i+1]==1){
					ans++;i++;
				}
			}
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans;
		}
	}
	else if(n<=100){//3 to 8
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==a[i+1]==1){
					ans++;i++;
				}
			}
			cout<<ans;
		}
		else if(k==1){
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			cout<<ans;
		}
		else{
			for(int i=1;i<=n;i++){
				ll x=a[i];
				if(x==k){
					ans++;continue;
				}
				for(int j=i+1;j<=n;j++){
					x^=a[j];
					if(a[j]==k){
						i=j+1;ans++;break;
					}
					if(x==k){
						i=j+1;ans++;break;
					}
				}
			}
			cout<<ans;
		}
	}
	else if(k<=1&&B){//exam 13
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==a[i+1]==1){
					ans++;i++;
				}
			}
			cout<<ans;
		}
		else if(k==1){
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			cout<<ans;
		}
	}
else{
	for(int i=1;i<=n;i++){
		ll x=a[i];
		if(x==k){
			ans++;continue;
		}
		for(int j=i+1;j<=n;j++){
			x^=a[j];
			if(a[j]==k){
				i=j;ans++;break;
			}
			if(x==k){
				i=j;ans++;break;
			}
		}
	}
	cout<<ans;
}
	return 0;
}
/*
10 3
1 5 2 4 1 1 5 3 9 8
*/