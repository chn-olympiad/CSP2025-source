#include<bits/stdc++.h> 
using namespace std;
int n,m,a[110],x,b[11][11],k=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			k++;
			b[j][i]=a[k];
		}
		i++;
		for(int j=n;j>=1;j--){
			k++;
			b[j][i]=a[k];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
		
	return 0;
}
