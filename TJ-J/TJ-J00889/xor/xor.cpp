#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			int ans=a[l];
			for(int j=l+1;j<=r;j++){
				ans=ans^a[j];
			}
			if(ans==k){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

