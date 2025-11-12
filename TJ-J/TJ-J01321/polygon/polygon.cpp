#include<bits/stdc++.h>
using namespace std;
int n,a[5005]={},b[5005]={},c[2005][2005]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int mx=0;
			for(int x=i;x<=j;x++){
				mx=max(mx,a[x]);
			}
			c[i][j]=mx;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int q=b[j]-b[i];
			if(q<3){
				continue;
			}
			if(q>=c[i][j]*2){
				s+-=1;
				s%=998244353;
			}
		}
	}
	cout<<s;
}
