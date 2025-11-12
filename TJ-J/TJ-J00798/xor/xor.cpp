#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,a[500007],ans,m;
bool vis[500007] = {false};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i] == k){
			ans++;
			vis[i] = 1;
		}
		a[i] ^= a[i-1];
		
	}
	for(int i = 1;i<=n-1;i++){
		for(int j = i+1;j<=n;j++){
			bool flag = true;
			for(int z = i;z<=j;z++){
				if(vis[z] != 0){
					flag = false;
					break;
				}
			}
			if(flag == false){
				continue;
			}
			ll num = a[j]^a[i-1];
			if(num == k){
				ans++;
//				cout << i << " "<< j << endl;
				for(int z = i;z<=j;z++){
					vis[z] = 1;
				}
//				for(int z = 1;z<=n;z++){
//					cout << vis[z] << " ";
//				}
//				cout <<endl;
			}
		}
	}
	cout << ans;
	return 0;
} 
