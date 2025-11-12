#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin >> n >> k;
	bool fg=0,kl=0;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i]!=1){
			fg=1;
		}
		if (a[i]>1){
			kl=1;
		}
	}
	if (fg==0){
		cout << n/2;
		return 0;
	}
	if (kl==0){
		if (k==0){
			for (int i=1;i<=n;i++){
				if (a[i]==0){
					sum++;
				}
				else if (a[i]==1 && a[i+1]==1){
					sum++;
					i++;
				}
			}
			cout << sum;
			return 0;
		}
		else{
			for (int i=1;i<=n;i++){
				if (a[i]==1){
					sum++;
				}
			}
			cout << sum;
			return 0;
		}
	}
	else{
		for (int i=1;i<=n;i++){
			if (a[i]==k){
				a[i]=-1;
				sum++;
			}
		}
		int tg=0;
		for (int i=1;i<=n;i++){
			if (tg==k){
				sum++;
				tg=0;
			}
			if (a[i]!=-1){
				tg=tg^a[i];
			}
			else{
				tg=0;
			}
		}
		cout << sum;
		return 0; 
	}
	return 0;
}

