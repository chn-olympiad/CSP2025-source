#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005],now=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int zhi=a[i];
		if(zhi==k){
			if(i>now){
				ans++;
				now=i;
			}
			else now=min(now,i);
			continue;
		}
		for(int j=i+1;j<=n;j++){
			zhi=zhi^a[j];
			if(zhi==k){
				if(i>now){
					ans++;
					now=j;
				}
				else now=min(now,j);
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
