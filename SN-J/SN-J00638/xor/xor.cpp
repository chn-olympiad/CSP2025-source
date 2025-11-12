#include<bits/stdc++.h>
using namespace std;
int n,k,cc;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans=0;
			for(int l=i;l<=j;l++){
				ans=ans^a[l];
			}
			if(ans==k){
				cc++;	
				i=j+1;
				break;
			}
		}
	}
	cout<<cc;
	return 0;
}
