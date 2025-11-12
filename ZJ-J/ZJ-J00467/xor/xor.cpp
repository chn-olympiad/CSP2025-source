#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[500005],c[500005],b[1200000],Ans[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<(1<<20);i++)
	    b[i]=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];ans^=a[i];
		c[i]=b[ans^k];b[ans]=i;
		if(c[i]==-1)
			Ans[i]=Ans[i-1];
		else Ans[i]=max(Ans[i-1],Ans[c[i]]+1);
	}
	cout<<Ans[n];
	return 0;
}
