#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool camp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[101],a[11][11];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	sort(b,b+n*m);
	int x=m*n;
	for(int i=0;i<n;i++){
		int t=i;
		for(int j=0;j<m;j++){
			a[j][i]=b[x];
			x--;	
		}			
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==b[1]){
				cout<<i<<' '<<j;
				return 0;
			}
		}
		cout<<endl; 
	}
	return 0;
} 
