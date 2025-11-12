#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,b[N],k,len,ans;
struct node{
	int l,r;
}c[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=(b[i-1]^a[i]);
		for(int j=c[len-1].r;j<i;j++){
			if((b[i]^b[j])==k)c[len].l=j+1,c[len++].r=i;
		}
	}
	int lr=0;
	for(int i=0;i<len;i++){
		if(c[i].l>lr){
			ans++;
			lr=c[i].r;
		}
	}
	cout<<ans;
	return 0;
}
