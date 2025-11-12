#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	int n,k,a[230],b[230],ans;
	cin>>n>>k;
	b[0]=1;
	b[1]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]+=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j+1]%b[i]==k){
				ans++;
			}
		}
	}
cout<<ans;
return 0;
}
