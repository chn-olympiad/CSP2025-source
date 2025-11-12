#include<bits/stdc++.h>
using namespace std;
long long n,m,a[520],ans,o[520];
int b[520];
bool used[520];

string s;
long long f(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			n--;
		}
	}
	long long x=1;
	for(int i=n;i>=1;i--){
		x*=i;
		x%=99824453;
	}
	return x;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			return 0;
		}
	}
	
	return 1;
}
void dfs(int step){
	if(step==n+1){	
		long long sum1=0,sum2=0,sum=0;
		for(int i=1;i<=n;i++){
			if(sum2>=a[o[i]]){
				sum2++;
			}
			else if(b[i]==0){
				sum2++;
			}
			else{
				sum++;
				sum1++;
			}
		}
		if(sum>=m){
			ans++;
			ans%=99824453;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]){
			continue;
		}
		o[step]=i;
		used[i]=1;
		dfs(step+1);
		used[i]=0;
		
	}
	return;
}
bool cmp(long long q,long long p){
	return p<q;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		b[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check()){
		cout<<f();
		return 0;
	}
	long long popo=0;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			popo++;
		}
	}
	if(n-popo<m){
		cout<<0;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	dfs(1);
	cout<<ans;
	return 0;
}
//		for(int i=1;i<=n;i++){
//				cout<<o[i]<<" ";
//			}
//			cout<<endl;
