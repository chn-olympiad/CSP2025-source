#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int b[500005];
		int j=1;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1&&i+1<=n)b[j]=0,i++;
			else b[j]=a[i];
			j++;
		}
		for(int i=1;i<=j-1;i++){
			if(b[i]==0)ans++;
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
