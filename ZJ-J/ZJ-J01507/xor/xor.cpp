#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n),sum(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i]=((i>0)*sum[i-1])^a[i];
	}
	int cnt=0,ed=-1;
	for(int i=0;i<n;i++){
		for(int j=ed;j<i;j++){
			if((sum[i]^(sum[j]*(j>=0)))==k){
				cnt++;
				ed=i;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
