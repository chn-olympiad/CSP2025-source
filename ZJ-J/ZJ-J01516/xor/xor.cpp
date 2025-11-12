#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	if(k==0){
		for(long long i=1;i<=n;){
			if(a[i]==0)i++,ans++;
			else if(i!=n&&a[i]==a[i+1])i+=2,ans++;
			else i++;
		}
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
//		cout<<sum[i]<<' ';
	}
//	cout<<'\n';
	for(long long i=1,j=0;i<=n;){
		bool flag=0;
		while(j<=n){
			j++;
//			cout<<i<<"to"<<j<<','<<sum[i-1]<<'^'<<sum[j]<<'='<<(sum[j]^sum[i-1]);
			if((sum[j]^sum[i-1])==k){
				flag=1;
				ans++;
//				cout<<"  YES\n";
				break;
			}
//			cout<<'\n';
		}
		if(flag==0)j=i;
		i=j+1;
	}
	cout<<ans;
	return 0;
}
/*
k=1
1 2 3 2 3
1 3 0 2 1

2 1 0 3
2 3 3 0

0:00
1:01
2:10
3:11
*/

