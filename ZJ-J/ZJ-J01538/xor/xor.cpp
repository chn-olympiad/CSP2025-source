#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],flag1=1,flag2=1,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=1)flag1=0;
		if(a[i]>1)flag2=0;
	}
	if(flag1){
		cout<<n/2;
	}else if(flag2){
		if(k==0){
			int lx=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++,cnt+=lx/2,lx=0;
				else lx++;
			}
			cout<<cnt;
		}else{
			for(int i=1;i<=n;i++){
				cnt+=(a[i]==1);
			}
			cout<<cnt;
		}
	}else{
		int x=a[1],i=1;
		while(x==k){
			i++,cnt++,x=a[i];
		}
		i++;
		for(i;i<=n;i++){
			if(a[i]==k){
				cnt++,x=0;
			}else{
				x^=a[i];
				if(x==k){
					cnt++,x=0;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
