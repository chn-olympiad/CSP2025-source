#include<iostream>
using namespace std;
const int N = 5e5+10;
int n,k;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==n){
		if(k>=2){
			cout<<0;
		}else if(k==1){
			cout<<n;
		}else if(k==0){
			cout<<n/2;
		}
		return 0;
	}
	return 0;
}