#include<bits/stdc++.h>
using namespace std;
long long a[10000],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
		}
	}
	for(long long i=0;i<n;i++){
		for(long long j=i+1;j>i&&j!=n;j++){
				int x=a[i];
				x^=a[j];
				if(x==k)cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
