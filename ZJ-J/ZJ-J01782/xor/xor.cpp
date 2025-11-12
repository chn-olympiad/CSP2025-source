#include<bits/stdc++.h>
using namespace std;
const int N=1e6+90;
int n,k,m,a[N],ans=1;
struct node{
	int l,r;
}s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				m++;
				s[m].l=i;
				s[m].r=j;
			}
		}
	}
	int o=1;
	for(int i=2;i<=m;i++){
		if(s[o].r<s[i].l){
			ans++;
			o=i;
		}
	}
	if(m==0) cout<<0;
	else cout<<ans;
	return 0;
}
