#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],x,k=1,ans,b[2200000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	b[0]=1;
	for(int i=1;i<=n;i++){
		x=x^a[i];
		if(b[x^m]==k)
			k++,x=0;
		b[x]=k;
	}
	cout<<k-1;
}