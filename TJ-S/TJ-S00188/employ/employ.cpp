#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,a[501],num,b[501];
char s[501];
bool check(){
	int c=0;
	for(int i=1;i<=n;i++){
		if(c>=a[b[i]]) c++;
		else if(s[i]=='0') c++;
	}
	return n-c>=m?true:false;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		num+=s[i]-'0';
	}
	if(num<m){
		cout<<0;
		return 0;
	}
	if(num==n){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%p;
		}
		cout<<ans%p;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	if(n<=10){
		int ans=0;
		do{
			if(check()){
				ans++;
			}
		}while(next_permutation(b+1,b+n+1));
		cout<<ans;
	}
	if(m==1){
		long long ans=1,sum=1,dd[501]={};
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int c=0;
			for(int j=1;j<=n;j++){
				if(c>=a[j]) c++;
				else if(s[j]=='0') c++;
			}
			dd[i]=n-c;
			sum*=dd[i];
		}
		for(int i=1;i<=sum;i++){
			ans=(ans*i)%p;
		}
		for(int i=1;i<=n-sum;i++){
			ans=(ans*i)%p;
		}
		cout<<ans%p;
		return 0;
	}
	
	return 0;
}
