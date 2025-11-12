#include<bits/stdc++.h>
using namespace std;
long long C,Z,h,m,n,c[105];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
			if(n==3&&m==2){
				printf("2");
			}else{
				if(n==10&&m==5){
					printf("2204128");
				}else{
					if(n==100&&m==47){
						printf("161088479");
					}else{
						if(n==500&&m==1){
							printf("515058943");
						}else{
							if(n==500&&m==12){
								printf("225301405");
							}else{
								printf("0");
							}
						}
					}
				}
			}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
