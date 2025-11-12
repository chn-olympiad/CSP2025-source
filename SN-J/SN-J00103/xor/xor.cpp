#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1050000];
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int f1=0,f2=0,maxa=1050000;
	memset(a,sizeof(a),-1);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==1) ++f1;
		if(a[i]==0||a[i]==1) ++f2;
		if(a[i]>maxa) maxa=a[i];
	}
	if(f1==n){
		if(k==0){
			printf("%d",n/2);
		}else{
			putchar('0');
		}
	}else if(f2==n){
		if(k==0){
			for(int i=1;i<=n;++i){
				if(a[i]==0){
					++ans;
				}else if(a[i]==1&&a[i+1]==1){
					++ans;
					++i;
				}
			}
		}else if(k==1){
			for(int i=1;i<=n;++i){
				if(a[i]==1){
					++ans;
				}
			}	
		}else{
			putchar('0');
		}
	}else{
		if(maxa%2){
			if(k>maxa) putchar('0');
		}else{
			if(k>maxa+1) putchar('0');
		}
	}
	return 0;
}
