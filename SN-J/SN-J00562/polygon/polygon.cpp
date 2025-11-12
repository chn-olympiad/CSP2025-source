#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5001];
long long ans;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n<=3){
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			ans=ans+a[i];
		}
		if(ans>a[1]*2){
			cout<<1;
		}
	}
	return 0;
}

