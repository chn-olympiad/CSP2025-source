#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	//freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];

int hzh=0;
if(n>=3){
	for(int lzc1=1;lzc1<n-1;lzc1++){
		int maxn=0;
		for(int i=0;i<=2;i++){
			maxn=max(maxn,a[lzc1+i]);
		}
		if(a[lzc1]+a[lzc1+1]+a[lzc1+2]>2*maxn)hzh++;
	}
}
cout<<hzh<<" ";
if(n>=4){
	for(int lzc1=1;lzc1<n-1-1;lzc1++){
		int maxn=0;
		for(int i=0;i<=3;i++){
			maxn=max(maxn,a[lzc1+i]);
		}
		if(a[lzc1]+a[lzc1+1]+a[lzc1+2]+a[lzc1+3]>2*maxn)hzh++;
	}
}
cout<<hzh<<" ";
if(n>=5){
	for(int lzc1=1;lzc1<n-1-1-1;lzc1++){
		int maxn=0;
		for(int i=0;i<=3+1;i++){
			maxn=max(maxn,a[lzc1+i]);
		}
		if(a[lzc1]+a[lzc1+1]+a[lzc1+2]+a[lzc1+3]+a[lzc1+4]>2*maxn)hzh++;
	}
}
cout<<hzh;
	return 0;
}

