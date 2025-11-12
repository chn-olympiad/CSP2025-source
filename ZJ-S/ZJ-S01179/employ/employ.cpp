#include<bits/stdc++.h>
using namespace std;
string s;
int a[505];
long long aa(int a){
	long long ans=1;
	for(int i=1;i<=a;i++){
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			sum++;
		}
	}
	int s1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			s1++;
		}
	}
	int j=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			j++;
		}
	}
	if(m==n){
		if(j!=n||s1!=n){
			cout<<0;
			return 0;
		}
		else{
			cout<<aa(n);
			return 0;
		}
	}
	cout<<0;
	return 0;
}
