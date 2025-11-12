#include<bits/stdc++.h>
using namespace std;
int a[5010];
int maxn;
long long sum;
long long jie(int n){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	long long num=jie(n);
	for(int i=3;i<=n;i++){
		sum+=num/(jie(i)*jie(n-i));
	}
	cout<<sum%998244353;
	return 0;
}
