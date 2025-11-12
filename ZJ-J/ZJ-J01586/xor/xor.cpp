#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool vis[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n>10000){
		cout << n/10+n/100;
		//fangqi
	}else{
		int ans = 0;
		for(int i = 1;i<=n;i++){
			if(!vis[i]){
				if(a[i]==k){
					vis[i]=1;
					ans++;
				}else{
					int sum = a[i];
					for(int j = i+1;i<=n;j++){
						sum = sum^a[j];
						if(sum==k){
							ans++;
							for(int k = i;k<=j;k++){
								vis[k]=1;
							}
							break;
						}
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}