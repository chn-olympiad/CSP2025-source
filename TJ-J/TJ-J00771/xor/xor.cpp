#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n],cnt1 = 0,cnt2 = 0,f = 1;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<0;
		return 0;
	}
	for(int i = 0;i<n;i++){
		cnt1 = 0;
		for(int j = i;j<n;j++){
			if(j == i&&a[j] == k){
				cnt2++;
				break;
			}
			cnt1+=a[j]|a[j-1];
			if(cnt1 == k){
				cnt2++;
				break;
			}
		}
	}
	cout<<cnt2;
}
