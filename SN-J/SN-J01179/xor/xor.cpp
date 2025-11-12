#include<bits/stdc++.h>
using namespace std;
long long a[500010],c[500010];
string b[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		int f=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]==1&&f==1)f=0;
			else if(a[i]==1&&f==0)f=1;
			if(f==0)ans++;
		}
	}
	else{
		int f=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&f==1)f=0;
			else if(a[i]==1&&f==0)f=1;
			if(f==k)ans++;
		}
	}
	cout<<ans;
	return 0;
}
