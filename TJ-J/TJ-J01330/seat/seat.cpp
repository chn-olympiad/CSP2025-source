#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int nn,mm;
int xx;
int dashu;
int ziji;
int aa[10005];
int hang,lie;
bool pan=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&nn,&mm);
	scanf("%d",&xx);
	aa[1]=xx;
	dashu=0;
	for(int i=2;i<=nn*mm;i++){
		scanf("%d",&aa[i]);
		if(aa[i]>xx){
			dashu+=1;
		}
	}
	ziji=dashu+1;
	if(ziji%nn!=0){
		lie=ziji/nn;
		lie+=1;
	}else if(ziji<=nn){
		lie=1;
	}else{
		lie=ziji/nn;
	}
	if(lie%2==0){
		hang=2*nn-ziji+1;
	}else{
		if(lie==1){
			hang=ziji;
		}else{
			if(ziji%nn==0){
				hang=nn;
			}else{
				hang=ziji%(nn*(lie-1));
			}
		}
	}
	printf("%d %d",lie,hang);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
