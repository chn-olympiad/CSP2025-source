#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool b[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,kk;
	int l = 0,r = 0;
	cin >> n >> kk;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		b[i] = 0;
		if(a[i]==kk){
			ans++;
			b[i] = 1;
		}
	}
	int num,j;
	for(int i = 1;i<=n;i++){
		if(b[i]==1){
			continue;
		}
		num = a[i];
		j = i+1;
		while(b[j]==0){
			num^=a[j];
			if(num==kk){
				ans++;
				i = j+1;
				break;
			}
			j++;
		}
	}
	cout << ans;
}