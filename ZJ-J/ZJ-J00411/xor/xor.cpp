#include<bits/stdc++.h>
using namespace std;
long long n,k,a,s[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
	}
	for(int i=0;i<n;i++){
		long long l=0,m=i,cnt=0,f;
		while(l+m<n){
			l++;
			f=s[m]^s[l+m];
			if(f==k){
				m+=l;
				l=0;
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
