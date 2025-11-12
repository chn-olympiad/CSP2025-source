#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int jieg[t];
	for(int a=0;a<t;a++){
	int sum=0;
	int n;
	int yjydrs=0;
	int fuzhu=0;
	int peo[n][3];
	int jieg[t];
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>peo[i][j];
		}
	}
	for(int i=0;i<3;i++){
		if(yjydrs==n){
			jieg[a]=sum;
			break;
		}
	for(int j=0;j<n;j++){
		if(fuzhu<peo[i][j]){
			fuzhu+=peo[i][j];
			yjydrs++;
		}if(j==n-1){
			sum+=fuzhu;
		}if(yjydrs==n){
			break;
		}	
		}
	if(i=2&&yjydrs<n){
		i=0;
	}
	}
	
	}
	for(int i=0;i<t;i++){
		cout<<jieg[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
