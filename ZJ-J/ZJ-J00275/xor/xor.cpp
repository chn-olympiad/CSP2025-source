#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,mm,m,ma;
int a[210000],b[210000],d[210000];
struct no{
	int l,r;
}c[1100000];
void dfs(int x,int s){
	if(x==n+1){
		ma=max(ma,s);
		return;
	}
	if(x>n+1||s+n-x+1<=ma) return;
	if(d[x]) dfs(d[x]+1,s+1);
	dfs(x+1,s);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	b[i]=(b[i-1]^a[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			mm=m;
			if(i==j){
				if(a[i]==k){
					c[++m].l=i;
					c[m].r=j;
					d[i]=j;
				}
				else continue;
			}
			else if((b[j]^b[i-1])==k){
				c[++m].l=i;
				c[m].r=j;
				d[i]=j;
			}
			if(m>mm) break;
		}
	}
	dfs(1,0);
	cout<<ma;
	return 0;
}