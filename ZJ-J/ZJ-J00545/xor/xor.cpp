#include<bits/stdc++.h>
using namespace std;
int n,a[500005],s[500005],s1=0,s2,t[5];
long long k,ans,js,q=1;

bool hs(int c){
	js=0,q=1;
	for(int i=1;i<=n;i++){
		for(int j=q;j<=i;j++){
			if((s[i]^s[j-1])==k){
//				cout<<'\n'<<i<<" "<<j-1<<"   "<<(s[i]^s[j-1]);
				js++,q=j+1;
				break;
			}
		}
	}
	return js>=c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=1)t[a[i]]++;
		s[i]=(s[i-1]^a[i]);
	}
	if(t[0]+t[1]==n){
		cout<<t[1];
		return 0;
	}
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";
	s2=n;
	while(s1<=s2){
		int mid=(s1+s2)/2;
		if(hs(mid))ans=mid,s1=mid+1;
		else s2=mid-1;
	}
	cout<<ans;
	return 0;
}