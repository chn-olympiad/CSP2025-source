#include<bits/stdc++.h>
using namespace std;
int f[500010];
int xo(int x,int y){
	int a[10],b[10],c[10],cnt1=0,cnt2=0,w=x,f1=x,f2=y;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	if(x==0){
		cnt1=1;
		a[cnt1]=0;
	}
	if(y==0){
		cnt2=1;
		b[cnt2]=0;
	}
	while(f1!=0){
		cnt1++;
		a[cnt1]=f1%2;
		f1/=2;
	}
	while(f2!=0){
		cnt2++;
		b[cnt2]=f2%2;
		f2/=2;
	} 
	for(int i=1;i<=max(cnt1,cnt2);i++){
		if(a[i]!=b[i])c[i]=1;
		else c[i]=0;
	}
	int ret=0,o=1;
	for(int i=1;i<=max(cnt1,cnt2);i++){
		if(c[i]==1)ret+=o;
		o*=2;
	}
	return ret;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ret1=0,ct=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(f[i]==k)ret1++;
	}
	for(int i=2;i<=n;i++){
		for(int l=1;l<=n-i+1;l++){
			ct=f[l];
		    for(int r=l+1;r<l+i;r++){
		    	ct=xo(ct,f[r]);
			}
			cout<<i<<f[l]<<ct<<endl;
			if(ct==k){
				ret1++;	
			}
		}
	}
	cout<<ret1;
	return 0;
} 
