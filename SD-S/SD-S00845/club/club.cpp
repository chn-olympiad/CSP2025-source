#include<bits/stdc++.h>
using namespace std;
int club(int n){
	long long all[n][3],sum=0,check[3],bid[n][3],half=n/2,solve[n];
	for(int i=0;i<n;i++){
        solve[i]=0;
		for(int j=0;j<3;j++){
			cin>>all[i][j];
			bid[i][j]=0;
		}
	}for(int i=0;i<n;i++){
		bid[0][i]=max(bid[0][i],all[0][i]);
		bid[1][i]=max(bid[1][i],all[1][i]);
		bid[2][i]=max(bid[2][i],all[2][i]);
		
	}
	for(int j=0;j<3;j++){
		for(int i=0;i<n;i++){
		    sum+=bid[j][i];
		    if(bid[j][i]!=0){
			check[i]++;
			}
		    
	}
	for(int i=0;i<n;i++){
		if(check[i]>half){
		for(int j=0;j<3;j++){
			if(bid[i][j]!=0)
			sum=sum-bid[i-1][j];
			for(int x=j;x<3;x++){
				sum+=bid[i][x];
			}
		}	
		}
	}

	return sum;


}
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n;
	cin>>n;
	long long b[n],c[n];
	for(int i=0;i<n;i++){
		cin>>b[i];
		c[i]=club(b[i]);
	}
	for(int i=0;i<n;i++){
		cout<<c[i]<<endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
