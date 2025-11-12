#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,a[200010],s,t,w;
struct no{
	int t,w;
}b[200010];
bool cmp(no q,no h){
	return q.w<h.w;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i],a[i]=(a[i-1] xor a[i]);
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if((a[j] xor a[i-1])==k)
				t++,b[t].t=i,b[t].w=j;
	sort(b+1,b+t+1,cmp);
	w=b[1].w;s=1;
	for(i=2;i<=t;i++)
		if(b[i].t>w)
			s++,w=b[i].w;
	cout<<s;
	return 0;
}