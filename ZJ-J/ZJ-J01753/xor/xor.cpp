#include<bits/stdc++.h>
using namespace std;
long long sum[200005],e[2];
bool st[200005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	bool flag1=0,flag2=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		long long a;
		cin>>a;
		if(a!=1){
			flag1=1;
			if(a!=0){
				flag2=1;
			}
		}
		if(a==1||a==0){
			e[a]++;
		}
		sum[i]=sum[i-1]^a;
	}
	if(flag1==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(flag2==0&&k<=1){
		cout<<e[k];
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			bool flag=0;
			for(long long q=j-i+1;q<=j;q++){
				if(st[q]==1){
					flag=1;
					break;
				}
			}
			if(flag==1) continue;
			long long z=sum[j-i]^sum[j];
			if(z==k){
				st[j-i+1]=1;
				st[j]=1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
