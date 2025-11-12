#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=(a[i-1]^x);
	}
	for(int len=0;len<=n;len++){
		for(int i=1;i+len<=n;i++){
			int j=i+len;
			int flag=0;
			if((a[j]^a[i-1])==k){
				for(int l=i;l<=j;l++){
					if(b[l]==1){
						flag=1;
						break;
					}
				}
				if(flag==1) continue;
				//cout<<flag<<" ";
				//cout<<i<<" "<<j<<" "<< endl;
				ans++;
				for(int l=i;l<=j;l++) b[l]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

