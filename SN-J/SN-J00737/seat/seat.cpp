#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
int f[100][100];
int a[10010];
int z=0;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(a[i]>a[j]){
				int c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(i%2!=0){
			for(int j=1;j<=m;++j){
				if(a[z]==x){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				z++;
			}
		}else{
			for(int j=m;j>=1;--j){
				if(a[z]==x){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				z++;
			}	
		}
	}
	return 0;
}
