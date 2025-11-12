#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,arr[5005],f[5005];
void xxx(int x,int q){
	if(x==0){
		int num=0,maxx=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1){
				num=num+arr[i];
				if(maxx<arr[i]){
					maxx=arr[i];
				}
			}
		}
		if(num>maxx*2){
			ans++;
			ans=ans%998244353;
		}
		return ;
	}
	for(int i=q+1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			xxx(x-1,i);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=3;i<=n;i++){
		xxx(i,0);
	}
	cout<<ans<<endl;
	return 0;
}
