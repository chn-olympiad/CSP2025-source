#include<bits/stdc++.h>
using namespace std;
long long n,m,q=998244353;
string s;
int a[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long x,ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				x=i;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]>x){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		if(m==n){
			for(int i=0;i<n;i++){
				if(s[i]=='0'||a[i]==0){
					cout<<0;
					return 0;
				}
			}
		}
		long long cnt=0,ans=1;
		for(int i=0;i<n;i++){
			if(a[i]>0){
				cnt++;
			} 
		}
		for(int i=2;i<=cnt;i++){
			ans*=i;
			ans%=q;
		}
		if(cnt==0){
			cout<<0;
		}
		else{
			cout<<ans;
		}
	}
	return 0;
}

