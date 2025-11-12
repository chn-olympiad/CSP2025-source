#include<bits/stdc++.h>
using namespace std;
int b[15][15];
int a[120];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int aa=n*m;
	for(int i=1;i<=aa;i++){
		cin>>a[i];
	}
	int o=a[1];
	sort(a+1,a+1+aa,cmp);
	
	int om=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[om];
				om++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[om];
				om++;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==o)cout<<j<<" "<<i;
		}
	}
	
	
	return 0;
}
