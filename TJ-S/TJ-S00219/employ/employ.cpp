#include<iostream>
#include<cstring>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int f[505]={0};
	for(int i=0;i<n;++i){
		cin>>f[i];
	}
	if(m==n){
		int sum=0;
		for(int i=0;i<n;++i){
			if(a[i]=='0'){
				sum++;
			}
		}
		for(int i=0;i<n;++i){
			if(f[i]<sum){
				cout<<0;
				return 0;
			}
		}
	}
	long long ans=n;
	for(int i=n-1;i>0;--i){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}             //Ren5Jie4Di4Ling5%          998244353
