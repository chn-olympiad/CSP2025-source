#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int t,n[5],a[5][N][3],Max[5];
int chose(int b[N][3],int nn){
	int Max=0,total[N]={0};
	for(int i=0;i<nn;i++){
		 total[i]=b[i][0];
	}
	sort(total,total+nn);
	for(int i=nn-1;i>nn/2-1;i--){
		Max+=total[i];
	}
	return Max;
}
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			for(int k=0;k<3;k++){
				cin>>a[i][j][k];
			}
		}
	}
	for(int i=0;i<t;i++){
		Max[i]=chose(a[i],n[i]);
	}
	for(int i=0;i<t;i++)
		printf("%d\n",Max[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}