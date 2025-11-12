#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			a[i]=-1;
		}else{
			int j=1,x=a[i];
			while(j<=i){
				if(a[i-j]>=0){
					x=x^a[i-j];
				}else{
					break;
				}
				if(x==k){
					ans++;
					a[i]=-1;
					break;
				}
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
