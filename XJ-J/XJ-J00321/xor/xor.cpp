#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],d[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool ta=1,tb=1;
	if(k!=0)ta=0;
	if(k>=2)tb=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)ta=0;
		if(a[i]>=2)tb=0;
		s[i]=s[i-1]^a[i];
	}
	if(tb){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				if(a[i]==1&&a[i+1]==1)ans++;
			}
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}
//3/10AC!!!
