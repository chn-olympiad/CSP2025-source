#include<iostream>
using namespace std;
int main(){
	/*freopen("s","r",stdin);
	freopen("s","r",stdin);*/
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		if(a[i][j]>a[i+1][j+1]){
			a[i][j]=a[i][j+1];
			if(j%2!=0){
				h++;
				i+=h;
				j-=2;
				cout<<a[i][j];
			}
		}
		}
	}
	/*fclose(stdout);
	fclose(stdout);*/
}
