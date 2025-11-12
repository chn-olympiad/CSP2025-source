#include<bits/stdc++.h>
using namespace std;
long long n,arr[5100],ans;
void f(long long a,long long maxx,long long sum,long long num){
	if(a>n){
		if(sum>maxx*2ll){
			ans++;
			ans%=998244353;
		}
		return ;
	}
	f(a+1,max(maxx,arr[a]),sum+arr[a],num+1);
	f(a+1,maxx,sum,num);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	f(1,0,0,0);
	cout<<ans;
}
