#include<bits/stdc++.h>
using namespace std;
int las[3000005];
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=0,np=-1,ans=0;
	las[0]=0;
	for(int i=1;i<=n;i++){
		sum=sum^a[i];
		if(las[sum^k]!=0||sum==k){
			if(np<=las[sum^k]){
				np=i;
				ans++;
			}
		}
		las[sum]=i;
	}
	cout<<ans;
	return 0;
}