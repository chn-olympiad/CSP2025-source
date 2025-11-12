#include<bits/stdc++.h>
using namespace std;
long long n,k,sum=0,d=0;
long long a[1000005];
bool f1=1,f2=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=0;
		if(a[i]!=1&&a[i]!=0) f2=0;
	}
	if(f1==1){
		cout<<n/2;
		return 0;
	}
	if(f2==1){
		int ans=0,ans1=0,p=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
			else ans1++;
		}
		if(k==1) cout<<ans;
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1) p++;
				if(a[i]==0) p++;
			}
			cout<<p;
		}
		return 0;
   	}
   	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(sum==k) d++,sum=0;
	}
	cout<<d;
	return 0;
}