//SN-J01065 郭子羽 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,k,r,ans,a[10010],b[10010];
int xor1(int a,int b){
	return int(a | b) - int(a & b);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} for(int i = 1;i <= n;i++){
		int x = a[i];
		if(x == k){
			b[i] = i; continue;
		}
		b[i] = -1;
		for(int j = i + 1;j <= n;j++){
			x = xor1(x,a[j]);
			if(x == k){
				b[i] = j; break;
			}
		}
	} for(int i = 1;i <= n;i++){
		r = b[i];
		if(r == -1) continue;
		for( ;i <= r;i++){
			if(b[i] == -1) continue;
			if(b[i] < r) r = b[i];
		} ans++; i--;
	} cout << ans;
	return 0;
}//复杂度O(n^2)，预计60+
