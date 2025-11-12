#include<bits/stdc++.h>
using namespace std;
int c[502];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=1;
	int newn=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)newn--;
	}n=newn;
	for(int i=m;i<=n;i++){
		ans*=i;
		ans=ans%998244353;
	}for(int i=1;i<=m;i++){
		ans/=i;
	}
	cout<<ans%998244353<<endl;
	return 0;
}