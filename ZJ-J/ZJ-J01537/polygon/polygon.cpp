#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005];
long long sum;
bool f[5005];
void dfs(int x){
	if(x>n){
		int sum1=0,sum2=0,max1=0;
		for(int i=1;i<=n;i++){
			if(f[i]){
				sum1++;
				sum2+=a[i];
				max1=max(max1,a[i]);
			}
		}
		if(sum1<3)return;
		if(max1>=sum2-max1)return;
		sum++;
		sum%=N;
		return;
	}
	dfs(x+1);
	f[x]=1;
	dfs(x+1);
	f[x]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=25){
		dfs(1);
		cout<<sum;
	}
	else{
		sum=1;
		for(int i=1;i<=n;i++){
			sum=sum*2%N;
		}
		cout<<(sum+N-1-n-n*(n-1)/2)%N;
	}
	return 0;
}
