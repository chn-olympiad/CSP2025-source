#include<bits/stdc++.h>
using namespace std;
int a[10001],n,k,ans,c=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//cin>>n>>k;
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<=n;i++){
	ans=0;
	for(int j=i;j<=n;j++)ans^=a[j];
	if(ans==k){
		c++;
	}
}
cout<<c;
	return 0;
}
 
