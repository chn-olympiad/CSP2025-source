#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long sum=0,count=0,lowe=n;
	for(int i=n;i>=1;i--){
		sum=0;
		for(int j=i;j<=lowe;j++){
			sum=sum^a[j];
			if(sum==k){
				lowe=i-1;
				count++;
				break;
			}
		}
	}cout<<count;
	return 0;
}
