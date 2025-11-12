#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,a[105],z;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	z=a[1];
	for(int j=1;j<=n*m;j++){
		if(a[j]<a[j+1]){
			int temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	for(int l=1;l<=n*m;l++){
		if(z==a[l]){
			if(n==m){
				if(l<=n){
					cout<<1<<" "<<l;
					return 0;
				}
				else{
					if(m%2==0){
						if(l%n==0){
							cout<<l/n<<" "<<1;
						}
						else{
							cout<<l%n+1<<" "<<m-l%n+1;
						}
					}
					else{
						if(l%n==0){
							cout<<l/n<<" "<<1;
						}
						else{
							cout<<l/n+1<<" "<<l%n;
						}
					}
				}
			}
		}
	}
	return 0;
}
