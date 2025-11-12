//wsli 2025
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[24];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto i:s) {
		if(i-'0'>=0&&i-'0'<=9) {
			a[i-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		if(a[i]!=0) {
			while(a[i]!=0) {
				printf("%d",i);
				a[i]--;
			}
		}
	}
	return 0;
}
