#include<bits/stdc++.h>
using namespace std;
int a[100007];
int check(int b[100007],int z){
	if(z==2){
		return 11;
	}
	int p=0,q=2;
	int c[z+8];
	for(int i=1;i<z;i++){
		c[i]=abs(b[i]-b[i+1]);
		p=max(c[i],p);
		q=min(c[i],q);
	}
	if(p=q){
		return z*10;
	}
	return check(c,z-1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,w=0,x=345,ans;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		w=max(w,a[i]);
		x=min(x,a[i]);
	}
	if(k==0&&w==x){
		cout<<n-1;
	}else if(k==1&&w==x){
		cout<<0;
	}else if((w-x)<=1){
		ans=check(a,n);
		if(ans==11&&k==1){
			cout<<n-1;
		}else if(ans%10==0){
			int g=ans/10;
			if(k==0){
				cout<<n-1;
			}else{
				cout<<n-g+1;
			}
		}else{
			cout<<n-2;
		}
	}
	return 0;
}
