#include<bits/stdc++.h>//3
using namespace std;
const int N=500010;
int n,k,a[N],ret;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}if(k==0){
		int flag=0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ret++;flag=0;
			}if(a[i]==1){
				flag++;
				if(flag==2){
					flag=0;
					ret++;
				}
			}
		}printf("%d",ret);
	}else if(k==1){
		int flag=1;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				ret++;
				flag=1;
			}else {
				if(flag==0){
					ret++;
					flag=1;
				}else flag=0;
			}
		}
	}else printf("0");
	return 0;
}
