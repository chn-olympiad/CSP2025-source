#include<bits/stdc++.h>
using namespace std;
int as[25][25];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans=0,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>as[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(as[i][j]>ans){
				a=i;
				b=j;
				ans=as[i][j];
			} 
		}
	}
	cout<<a<<" "<<b;
	return 0;
	fclose(stdin);
	fclose(stdout); 
}
