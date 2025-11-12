#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m[3][15000];
int dp[15000];
int jc[3];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		
		for(int i=0;i<n;i++){
			cin>>m[0][i]>>m[1][i]>>m[2][i];
		}
		
for(int i=0;i<3;i++)sort(m[i],m[i]+15000,cmp);
	for(int i=0;i<n;i++){
		int mwww=jc[0];
		for(int j=n-1;j>=0;j--){
			for(int mw=0;mw<3;mw++){
			
			if(jc[mw]<n/2 and dp[j]<dp[j-1]+m[mw][j]){
				
			dp[j]=dp[j-1]+m[mw][j];
			jc[mw]=mwww;
			if(mw!=2)mwww=jc[mw+1];
			jc[mw]++;}
			}
		}
			
		}
cout<<dp[n-1]<<endl;
}
fclose(stdin);
fclose(stdout);
	return 0;
} 
