#include<bits/stdc++.h>
using namespace std;
int a[5010];
int maxn;
int ans; 
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout);
	int m,n=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=3;i<=m;i++){
		for(int j=0;j<=m-i+1;j++){
			for(int y=1;y<=i;y++){
				n+=a[y+j];
				maxn=max(maxn,a[y+j]);
			}
			if(n>m){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
