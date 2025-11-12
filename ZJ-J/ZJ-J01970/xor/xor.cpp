#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005];
struct node{
	int z,l,r;
};
node dfs(int l,int i){
	if(l==1){
		node u;
		u.l=i,u.r=i,u.z=0;
		if(a[i]==k){
			u.l=i-1,u.r=i+1,u.z++;
		}
		return u;
	}
	node x=dfs(l/2,i),y=dfs(l/2,l/2+i),z;
	z.l=x.l,z.r=y.r,z.z=x.z+y.z;
	if(y.z==0)z.r=x.r;
	if(x.z==0)z.l=y.l;
	if((b[y.l]^b[x.r-1])==k){
		z.z++;
		z.r=y.l+1;
		z.l=x.r-1;
	}
	return z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	node ans=dfs(n,1);
	cout<<ans.z;
	return 0;
}

