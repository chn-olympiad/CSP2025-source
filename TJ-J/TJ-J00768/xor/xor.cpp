#include<bits/stdc++.h>
#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

//暴力：30分 差不多可以 >=10万带不动 
int n,k1,a[500001],b[101];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	rep(i,1,n-1){
		rep(i_,i,n-1) rep(j_,i_,n){
			int c=a[i_];
			rep(k,i_+1,j_) c^=a[k];
			b[c]++;
			i_+=j_;
			j_=i_;
		}
	}
	cout<<b[k1];
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
