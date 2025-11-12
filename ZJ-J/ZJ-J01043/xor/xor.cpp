#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c,l=1,r=l,ans=0;
	cin>>n>>k;
	vector<int> m(n+1);
	for(int i=1;i<=n;i++){
		cin>>c;
		m[i]=c^m[i-1];
	}
	for(int i=1;i<=n;i++){
		int l=r=i,cnt=0;
		while(r<=n){
			while(r<=n&&(m[r]^m[l-1])!=k) r++;
			if(r>n) break;
			l=++r;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
