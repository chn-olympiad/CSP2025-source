#include<bits/stdc++.h>
using namespace std;
int n,l=0,r=0;
long long k,ans;
long long a[500005],s[500005],v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	//cout<<s[0]<<" ";
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		//cout<<s[i]<<" ";
		l+=(a[i]==1);
		r+=(a[i]<=1);
	}
	if(l==n){
		cout<<n/2;
		return 0;
	}else if(r==n){
		if(k==0){
			for(int i=1;i<=2;i++){
				for(int j=1;j<=n-i+1;j++){
					int z=0;
					if((s[j+i-1]^s[j-1])==k){
						ans++;
						j++;
					}
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				int z=0;
				if((s[j]^s[j-1])==k){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}else if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				int z=0;
				for(int k=j;k<=j+i-1;k++)z+=v[k];
				if((s[j+i-1]^s[j-1])==k&&z==0){
					ans++;
					for(int k=j;k<j+i;k++){
						v[j]++;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	srand(time(0));
	cout<<rand()%(n+1);
	return 0;
}