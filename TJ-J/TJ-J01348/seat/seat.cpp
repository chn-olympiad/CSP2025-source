#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int n,m,b[110];
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int xm=b[0];
	int o=n*m-1;
	sort(b,b+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(b[o]==xm){
					cout<<i<<" "<<j;
					return 0;
				}
				o--;
			}
		}
		else{
			for(int j=n;j>0;j--){
				if(b[o]==xm){
					cout<<i<<" "<<j;
					return 0;
				}
				o--;
			}
		}
	}
	return 0;
}

