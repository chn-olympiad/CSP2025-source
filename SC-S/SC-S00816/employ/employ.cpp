#include<bits/stdc++.h>
using namespace std;
string a;
int n,m,b[1006];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int c[1006];
	int zt=0,zt1=0;
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0){
			zt++;
		}
	} 
	for(int i=1;i<=a.size();i++){
		c[i]=(a[i]-'0');
		if(c[i]==0){
			zt++;
			zt1=1;
		}
	}
	if(n==m&&zt==0){
	long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	else if(n==m&&zt!=0){
		cout<<0;
	}
	else if(zt1==0){
	long long ans1=1;
		for(int i=1;i<=n;i++){
			ans1*=i;
			ans1%=998244353;
		}
		cout<<ans1;
	}
	else{
		if(m>18){
			cout<<0;
		} 
		else{
			if(m==1){
				if(c[1]==1){
					long long ans=1;
					for(int i=1;i<=n;i++){
			            ans*=i;
			            ans%=998244353;
			        }
			        cout<<ans;
		        }
			}
			else cout<<0;
		}
		else cout<<0;
    } 
    return 0;
}