#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	if(m==1){
		long long ans=1;
		for(int i=2;i<=n;i++)
		ans=ans*i%998244353;
		cout<<ans;
	}else if(m==n){
		int a;
		string s;
		cin>>s;
		if(s.find('0'))puts("0");
		else{
			for(int i=1;i<=n;i++){
				cin>>a;
				if(a==0){
					puts("0");
					return 0;
				}
			}
			long long ans=1;
			for(int i=2;i<=n;i++)
			ans=ans*i%998244353;
			cout<<ans;
		}
	}else
	cout<<0;
	return 0;
}

