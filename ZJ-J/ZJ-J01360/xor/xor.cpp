#include <bits/stdc++.h>
using namespace std;
long long ans,a[511111],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]&&k==0){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
