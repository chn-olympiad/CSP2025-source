#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int a[maxn];
ll n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (n<=2){
		if (n==1){
			if (a[1]==k)cout << 1;
			else cout << 0;
		}else if (n==2){
			if (a[1]==k&&a[2]==k)cout << 2;
			else if (a[1]==k||a[2]==k||a[1]^a[2]==k)cout << 1;
			else cout << 0;
		}
	}else if(n>2){
		int sum=0;
		int num=a[1];
		for (int i=2;i<=n;i++){
			if (num^a[i]!=k&&num==k){
				sum++;
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
