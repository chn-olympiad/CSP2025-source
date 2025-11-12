#include<bits/stdc++.h>
using namespace std;
int n,k,A[500500],ans;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(A[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(A[i]==0){
				ans++;
			}if(A[i]==1){
				if(A[i+1]==1){
					ans++;
					A[i+1]=-1;
				}
			}
		}
		cout<<ans;
		return 0;
	}
}
