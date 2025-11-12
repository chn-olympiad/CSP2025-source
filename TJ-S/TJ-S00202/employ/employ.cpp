#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,c[505],a[505],b[2],sum[505],ans=1;
char s[505];
int main(){
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		b[s[i]-'0']++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[c[i]]++;
	}
	for(int i=1;i<=500;i++){
		sum[i]=sum[i-1]+a[i];
	}
	cout<<a[0]<<"\n";
	if(b[1]==n){
		int k=0;	
		k=sum[a[0]]-1;
		if(n-k>=m){
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}else if(b[1]==0){
		if(m==0){
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}
			cout<<ans;
		}else{
			cout<<0;
		}		
	}else if(m==0){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;		
	}else if(m==n){
		if(a[0]<=1 && b[1]==n){
			for(int i=1;i<=n;i++){
				ans*=i;
				ans%=998244353;
			}	
			cout<<ans;		
		}else{
			cout<<0;
		}
	}else if(m==1){
		for(int i=1;i<=b[1]-sum[a[0]]+1;i++){
			ans*=i;
			ans%=998244353;
		}	
		cout<<ans;		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
