#include<bits/stdc++.h>
using namespace std;
int n,m,a[501010],k,ans;
int mp[(1<<21)+10];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)a[i]=(a[i-1]^a[i]);
	int r=0,l=0;
	mp[0]=1;
	for(r=1;r<=n;r++){
		int x=a[r]^k;
		if(mp[x]){
			ans++;
			for(;l<r;l++)mp[a[l]]--;
		}mp[a[r]]++;
	}cout<<ans;
	return 0;
}

