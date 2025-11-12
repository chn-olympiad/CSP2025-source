#include<iostream>
using namespace std;
int n,k;
int a[500005];
int cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	int num=1;
	while(num<=n){
		int q;
		for(int i=1; i<=n-num; ++i){
			for(int j=i; j<=i+num; ++j){
				q=q^a[j];
			}
			if(q==k){
				cnt++;
			}
		}
		num++;
	}
	cout<<cnt;
	return 0;
}
