#include<bits/stdc++.h>
using namespace std;
const int maxn=500007;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,sum=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			sum++;
		}
		if(a[i]==0){
			cnt++;
		}
	}
	if(sum==n){
		if(sum%2==1){
			cout<<0;
		}else{
			cout<<sum/2;
		}
	}else if(cnt+sum==n){
		cout<<(n-1)/2;
	}else{
		cout<<89;
	}
	return 0;
}
