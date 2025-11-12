//SN-J00738 王子铭 西安市曲江第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int a[N],n,k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int key = 1;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i]==0){
			key = 0;
		}
	}
	if(key){
		cout << n/2;
	}else{
		if(k == 1){
			int ans = 0;
			for(int i = 1;i <= n;i ++){
				if(a[i] == 1){
					ans++;
				}
			}
			cout << ans;
		}else{
			int ans = 0;
			for(int i = 1;i <= n;i ++){
				if(a[i]==1&&a[i+1]!=0){
					a[i+1] = -1;
					ans ++;
				}else if(a[i] == 0){
					ans ++;
				}
			}
			cout << ans;
		}
	}
	return 0; 
}
