//周琪明 SN-J00213 西安滨河学校
#include<bits/stdc++.h>
#define ll long long
#define str string
int zh_n,zh_m,zh_b[100],zh_a[10][10],zh_zc,zh_yg=0,zh_fs;
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>zh_n>>zh_m;
	for(int i=0;i<zh_n*zh_m;i++){
		cin>>zh_b[i];
	}
	zh_fs=zh_b[0];
	for(int i=0;i<zh_n*zh_m;i++){
		if(zh_b[i]<zh_b[i+1]){
			zh_zc=zh_b[i];
			zh_b[i]=zh_b[i+1];
			zh_b[i+1]=zh_zc;
		}
	}
	for(int i=0;i<zh_m;i++){
		if(i%2==1){
			for(int j=0;j<zh_n;j++){
				zh_a[j][i]=zh_b[zh_yg];
				zh_yg++;
			}
		}
		else{
			for(int j=zh_n-1;j>=0;j--){
				zh_a[j][i]=zh_b[zh_yg];
				zh_yg++;
			}
		}
	}
	for(int i=0;i<zh_m;i++){
		for(int j=0;j<zh_n;j++){
			if(zh_a[j][i]==zh_fs){
				if((j+2)%zh_m>0){
					printf("%d %d",i+1,(j+2)%zh_m);
				}
				else{
					printf("%d %d",i+1,zh_m);
				}
				return 0;
			}
		}
	}
	return 0;
}
