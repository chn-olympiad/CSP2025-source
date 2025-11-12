#include<bits/stdc++.h>
using namespace std;
int a[1000][1000]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int q=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int goal=a[1][1];
	/*cout<<goal;
	cout<<endl;*/
	int asd=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(goal<a[i][j+1]){
				asd=a[i][j];
				a[i][j]=a[i][j+1];
				a[i][j+1]=asd;
			}
			else{
				continue;
			}
		}
	}
	
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
	}
	*/
	//cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(goal==a[i][j]){
				cout<<i<<" "<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
