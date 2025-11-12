#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],cnt,cnt1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt++;
		}
	}
	if(k==0){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=1001;i++){
		for(int j=i;j<=1001;j++){
			if(a[j]+a[j+1]==k){
				cnt1++;
			}
		}
	}
	cout<<cnt1;
	return 0;
}