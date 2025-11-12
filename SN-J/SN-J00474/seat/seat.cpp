#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ans,nes,xyz;
	cin>>n>>m;
	int v[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>v[i];
	}
	ans=v[1];
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=n*m-i;j++){
			if(v[j]>v[(j+1)]){
				xyz=v[j];
				v[j]=v[(j+1)];
				v[(j+1)]=xyz;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(v[i]==ans) nes=n*m+1-i;
	}
	int x,y;
	if(nes%n==0) x=nes/n;
	else x=(nes-nes%n)/n+1;
	if(x%2==0){
		if(nes%n==0) y=1;
		else y=n-nes%n+1;
	}
	else if(nes%n==0) y=n;
	else y=nes%n;
	cout<<x<<" "<<y;
	return 0;
}
