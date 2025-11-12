#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0;
	cin>>n;
	int a[n];
	cin>>a[n];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[i]*2>a[j]+a[k]&&a[i]!=a[j]&&a[i]!=a[k]){
					m++;
				}
			}
		}
	}
	cout<<m;	
}
