#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+7;
int n,k,ans=0;
int a[N],b=-1;
map<string,int>m;
string f(int x){
	string s1,s2;
	while(x){
		char c=x%10+'0';
		s1=s1+c;
		x/=10;
	}
	for(int i=s1.size()-1;i>=0;i--)s2=s2+s1[i];
	return s2;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(b==-1)b=a[i];
		else b=b^a[i];
		if(m[f(k^b)]==ans+1||k==b){
			ans++;
			b=-1;
		}
		else m[f(b)]=ans+1;
	}
	cout<<ans;
	return 0;
}
