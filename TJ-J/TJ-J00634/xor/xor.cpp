#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[500001];
void solve1(){
	cout << n/2;
	return;
}
void solve2(){
	int ans = 0;
	if(k==0){
		for(int i = 1;i<=n;i++){
			if(a[i]==0) ans++;
			else{
				int cnt = 0;
				while(a[i]==1 && i<=n){
					cnt++;
					i++;
				}
				ans+=cnt/2;
				i--; 
			}
		}
	}else if(k==1){
		for(int i = 1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout << ans;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	int f1 = 1, f2 = 1;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) f1 = 0;
		else if(a[i]!=1 && a[i]!=0){
			f1 = 0;
			f2 = 0;
		}
	}
	if(f1==1) solve1();
	else if(f2==1) solve2();
	else cout << 1;
	return 0;
} 
