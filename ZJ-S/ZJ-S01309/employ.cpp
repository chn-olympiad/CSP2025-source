#include<iostream>
using namespace std;
int n,m,a[505];
long long ans=0;
bool f=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int k=n;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0){
			k--;
		}
		if(s[i]!='1'){
			f=0;
		}
	}if(f||(m==1)){
		if(k<m){
			cout<<0;
			return 0;
		}ans=1;
		for(int i=0;i<n;i++){
			ans*=(n-i);
			ans%=998244353;
		}
	}cout<<ans;
	return 0;
}
