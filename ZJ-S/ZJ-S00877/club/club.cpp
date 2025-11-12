#include<bits/stdc++.h>
using namespace std;
int t;
int ab(int x){
	if(x>=0){
		return x;
	}
	return -x;
}
int min(int a,int b){
	if(a<=b)return a;
	return b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		int a[205][10]={0};
		int b[5][205]={0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a[i][4]=1;
				if(a[i][2]>=a[i][3]){
					a[i][5]=2;
					a[i][6]=3;
				}
				else{
					a[i][5]=3;
					a[i][6]=2;
				}
			}
			else{
				if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					a[i][4]=2;
					if(a[i][1]>=a[i][3]){
						a[i][5]=1;
						a[i][6]=3;
					}
					else{
						a[i][5]=3;
						a[i][6]=1;
					}
				}
				else{
					a[i][4]=3;
					if(a[i][1]>=a[i][2]){
						a[i][5]=1;
						a[i][6]=2;
					}
					else{
						a[i][5]=2;
						a[i][6]=1;
					}
				}
			}
			a[i][7]=a[i][1]-a[i][2];
			a[i][8]=a[i][1]-a[i][3];
			a[i][9]=a[i][2]-a[i][3];
			b[a[i][4]][0]++;
			b[a[i][4]][b[a[i][4]][0]]=i;
		}
		while(b[1][0]>n/2){
			int m=1;
			int i=2;
			for(;i<=b[1][0];i++){
				if(min(ab(a[b[1][i]][7]),ab(a[b[1][i]][8]))<min(ab(a[b[1][m]][7]),ab(a[b[1][m]][8]))){
					m=i;
				}
			}
			int j;
			if(ab(a[b[1][m]][7])<=ab(a[b[1][m]][8])){
				j=2;
			}
			else{
				j=3;
			}
			b[j][0]++;
			b[j][b[j][0]]=b[1][m];
			b[1][m]=b[1][b[1][0]];
			b[1][0]--;
		}
		while(b[2][0]>n/2){
			int m=1;
			int i=2;
			for(;i<=b[2][0];i++){
				if(min(ab(a[b[2][i]][7]),ab(a[b[2][i]][9]))<min(ab(a[b[2][m]][7]),ab(a[b[2][m]][9]))){
					m=i;
				}
			}
			int j;
			if(ab(a[b[2][m]][7])<=ab(a[b[2][m]][9])){
				j=1;
			}
			else{
				j=3;
			}
			b[j][0]++;
			b[j][b[j][0]]=b[2][m];
			b[2][m]=b[2][b[2][0]];
			b[2][0]--;
		}
		while(b[3][0]>n/2){
			int m=1;
			int i=2;
			for(;i<=b[3][0];i++){
				if(min(ab(a[b[3][i]][9]),ab(a[b[3][i]][8]))<min(ab(a[b[3][m]][9]),ab(a[b[3][m]][8]))){
					m=i;
				}
			}
			int j;
			if(ab(a[b[3][m]][9])<=ab(a[b[3][m]][8])){
				j=2;
			}
			else{
				j=1;
			}
			b[j][0]++;
			b[j][b[j][0]]=b[3][m];
			b[3][m]=b[3][b[3][0]];
			b[3][0]--;
		}
		int cnt=0;
		for(int i=1;i<=b[1][0];i++){
			cnt+=a[b[1][i]][1];
		}
		for(int i=1;i<=b[2][0];i++){
			cnt+=a[b[2][i]][2];
		}
		for(int i=1;i<=b[3][0];i++){
			cnt+=a[b[3][i]][3];
		}
		printf("%d\n",cnt);
	}
	return 0;
}
