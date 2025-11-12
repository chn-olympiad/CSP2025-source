#include <bits/stdc++.h>
using namespace std;
int dp[500002]={0},a[500002]={0};
int main(){ 
	FILE *fin=NULL,*fout=NULL;
	fin=fopen("xor.in","r");
	fout=fopen("xor.out","w");
	//if(fin==NULL)cout<<"?";
	int n,k;
	fscanf(fin,"%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		fscanf(fin,"%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int xo=0;
		for(int j=i;j>=1;j--){
			xo^=a[j];
			if(xo==k){
				if((dp[j-1]+1)>dp[i])dp[i]=dp[j-1]+1;
			}
		}
	}
	fprintf(fout,"%d",dp[n]);
	return 0;
}
