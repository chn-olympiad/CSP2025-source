#include <iostream>
#include <cstdio>
using namespace std;

int n,m,ans;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++) cin >> a[i];
	int sum = 0;
	for(int i = 0;i < n;i++){
		sum = sum ^ a[i];
		if(sum == m){
			sum = 0;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
