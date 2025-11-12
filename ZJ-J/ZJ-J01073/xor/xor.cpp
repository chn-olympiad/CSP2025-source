#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,a[1002],b[5002],mx;
struct nn{
	int l,r,s;
};
int f[5002];
vector<nn> q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if((b[j]^b[i-1])==m){
				q.push_back({i,j,(b[j]^b[i])});
			}
		}
	}
	 f[0]=0;
	 t=q.size();
	 for(i=1;i<=n;i++){
		for(j=0;j<i;j++){
			for(k=0;k<t;k++){
				if(q[k].l>j&&q[k].r<=i){
					f[i]=max(f[i],f[j]+1);
				}
			}
		}
	 }
	cout<<f[n];
	return 0;
}
