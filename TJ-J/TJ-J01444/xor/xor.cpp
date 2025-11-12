#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,b,a) for(int i=(b);i>=(a);i--)
#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=5e5+5;
int n,k,a[N],len,tot,ans,b[500][500],a0,a1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]==0) a0++;
		if(a[i]==1) a1++;
	}
	if(a1==n&&k==0) cout<<n/2;
	else if(a0+a1==n){
		if(k==0) cout<<a0;
		if(k==1) cout<<a1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

