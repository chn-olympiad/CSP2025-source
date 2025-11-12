#include<bits/stdc++.h> 
using namespace std;
long long n,k,a[500010],sf=1,sum1=0,sum0=0,ans,sum11=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			sf=0;
			if(a[i]==0){
				sum0++;
			}
		}else{
			sum1++;
			if(a[i-1]==1){
				a[i]=0;
				sum11++;
			}
		}
	}
	if(sf==1){
		cout<<n/2;
	}else{
		if(k!=1){
			ans=sum0+sum11;
			cout<<ans;
		}else{
			cout<<sum1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
