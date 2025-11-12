#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			for(int k=1;k<=n;k++){
				if(k==i||k==n) continue;
				if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k]))*2) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
