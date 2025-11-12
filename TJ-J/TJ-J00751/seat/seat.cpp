#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[15][15],b[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	int ans=b[1];
	for(int i=1;i<n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(b[i]>b[j])swap(b[i],b[j]);
		}
	}
	int w=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(b[w]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				w++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(b[w]==ans){
					cout<<i<<" "<<j;
					return 0;
				}
				w++;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
