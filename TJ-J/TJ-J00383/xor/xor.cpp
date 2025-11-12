#include<bits/stdc++.h>
using namespace std;
int n,k,a[20005][20005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[0][i];
		for(int j=1;j<=i;j++){
			a[j][i]=a[0][i]^a[j-1][i-1];
		}
	}for(int j=0;j<n;j++){
		for(int i=j;i<n;i++){
			if(a[j][i]==k&&a[j][i]!=-1){
				for(int ii=0;ii<i;ii++){
					for(int jj=0;jj<=j;jj++){
						a[jj][ii]=-1;
					}
				}for(int ii=i;ii<n;ii++){
					for(int jj=n;jj>=j-i+ii;jj--){
						a[jj][ii]=-1;
					}
				}ans++;
			}
		}
	}cout<<ans;
	return 0;
}

