#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin>>n>>k;
	bool b=1;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		if (a[i]==0) b=0;
	}
	if (b) cout<<n/2;
	else{
		if (k==0){
			int cnt=0;
			for (int i=1; i<=n; i++){
				if (a[i]==0) cnt++;
				if (a[i]==1&&a[i-1]==1){
					i++;
					cnt++;
				}
			}
			cout<<cnt;
		}
		else{
			int cnt=0;
			for (int i=1; i<=n; i++) 
				if (a[i]==1) cnt++;
			cout<<cnt;	
		}
	}
	return 0;
}