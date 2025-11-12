#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int cnt = 0;
	int a[n],b[n];
	b[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		b[i] = (b[i-1]^a[i]);
	}
	int l = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i-1;j >= l;j--){
			if((b[j]^b[i]) == k){
				cnt++;
				l = i;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
} 
