#include<stdio.h>
#include<iostream>
#include<string.h>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)

const int N=5e5+10;

int n,k,a[N],s[N];

int main() {
	int flag=1;//分别代表 0 无特殊性质		1 特殊性质A		2 特殊性质B		3 特殊性质C 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,1,n)
	{
		scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
		if(a[i]==0&&flag==1) flag=2;
		if(a[i]>1&&a[i]<256&&flag!=0) flag=3;
		if(a[i]>255) flag=0;
	}
	if(flag==1) {
		if(k==1) printf("%d",n);
		else if(k==0) printf("%d",n/2);
		else printf("0");
		return 0;
	}
	if(flag==2) {
		if(k>1) return!printf("0");
		if(k==1) {
			int ans=0;
			rep(i,1,n) if(a[i]==1) ans++;
			printf("%d",ans);
		}
		else {//k=0
			int ans=0;
			rep(i,1,n) {
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1) ans++,i++;
			}
			printf("%d",ans);
		}
		return 0;
	}
	printf("%d",0 and 1);
	return 0;
}
//没想到，先去看看T4 09:34 
//10:05 回来拿特殊性质AB分了
//10:30 AB应该没问题了，去想n<=1e3了
//10:40 没想出来，6 
//#Shang4Shan3Ruo6Shui4
