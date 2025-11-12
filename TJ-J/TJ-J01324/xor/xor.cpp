#include<bits/stdc++.h>
using namespace std;
int sum[500005],a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,x,ans=0;
	bool flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum[i]=sum[i-1]^x;
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum[j]^sum[j-i+1]==k){
				for(int w=j-i+1;w<=j;w++){
					if(a[w]==1){
						flag=0;
						break;
					}
				}
				if(flag){
					ans++;
					for(int w=j-i+1;w<=j;w++){
						a[w]=1;
					}
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
