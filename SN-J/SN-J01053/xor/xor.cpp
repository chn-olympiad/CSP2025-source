//SN-J01053  TongChuanShiTaoYuanDiErZhongXiaoXue  HaoTianZhe
#include <bits/stdc++.h>
using namespace std;
int a[500001],n,k,f=1;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			f=0;
			break;
		}
	}
	if(f){
		if(!k){
			printf("0\n");
			return 0;
		}else if(k==1){
			printf("%d\n",n);
			return 0;
		}else{
			printf("0\n");
			return 0;
		}
	}
	f=1;
	int s1=0,s2=0;
	for(int i=1;i<=n;i++){
		if((a[i]!=1)&&(a[i]!=0)){
			f=0;
			break;
		}else if(a[i]==1){
			s1++;
		}else if(!a[i]){
			s2++;
		}
	}
	if(f){
		if(k==1){
			printf("%d\n",s1);
			return 0;
		}else if(!k){
			printf("%d\n",s2);
			return 0;
		}
	}
	return 0;
}
