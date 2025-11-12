#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N];
int anss;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1){
		int t;
		cin>>t;
		if(t==k)cout<<1;
		else cout<<0;
		return 0;
	}
	else if(n==2){
		int a,b,ans=0;
		cin>>a>>b;
		if(a==k)ans++;
		if(b==k)ans++;
		if(a^b==k&&a!=k&&b!=k){
			cout<<1;
		}
		else cout<<ans;
		
		return 0;
	}
	else if(n==3){
		int a,b,c,ans=0,ans1=0;
		cin>>a>>b>>c;
		if(a==k||b==k||c==k)ans=1;
		if(b==k&a==k||a==k&&c==k||b==k&&c==k)ans=2;
		if(a==k&&b==k&&c==k)ans=3;
		if(a^b==k||b^c==k||a^b^c==k)ans1=1;
		if(a^b^c==k)ans1=1;
		if(a^b==k&&c==k)ans1=2;
		if(a==k&&b^c==k)ans1=2;
		cout<<max(ans1,ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)anss++;
	} 
	cout<<anss;
	return 0;
}
