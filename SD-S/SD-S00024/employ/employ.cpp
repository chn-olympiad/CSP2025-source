#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[1000010],b[1000010];
string s;
bool f=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='1') f=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(f){
		int ans=6;
		int nn=n;
		for(int i=1;i<=n;i++){
			if(a[i]==0) nn--;
		}
		if(nn==1) cout<<"1"<<endl;
		else if(nn==2) cout<<"2"<<endl;
		else if(nn==3) cout<<"6"<<endl;
		else{
			for(int i=4;i<=nn;i++){
				ans*=i;
				ans%=mod;
			}
			cout<<ans%mod<<endl;
		}
		return 0;
	}
	int cnt=0;
	while(next_permutation(a+1,a+n+1)){ 
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(b[i]>0&&s[i-1]=='1') ans++;
			if(b[i-1]=='0'){
				for(int j=i+1;j<=n;j++){
					b[j]--;
				}
			}
		}
		if(ans>=m) cnt++;
	}
	cout<<cnt%mod<<endl;
	return 0;
}
