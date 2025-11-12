#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum = 0;
	int a[500007];
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]^a[j]==k)sum++;
		}
	}
	cout << sum;
	
	return 0;
}
