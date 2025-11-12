#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],t1=1,t2=1,t3=1;
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=1)t1=0;
		if(a[i]>1)t2=0;
		if(a[i]>255)t3=0;
	}
	if(t1)cout<<n/2;
	else if(t2){
		if(!k){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(!a[i])ans++;
				else if(a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)if(a[i])ans++;
			cout<<ans;
		}
	}
	return 0;
}