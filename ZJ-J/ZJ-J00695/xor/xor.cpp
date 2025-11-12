#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,t,last,ans,a[500010];
struct no{int x,y;}b[5000010];
bool cmp(no a,no b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<=n;i++)a[i]^=a[i-1];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if((a[j]^a[i-1])==k)
				b[++t].x=i,b[t].y=j;
	sort(b+1,b+1+t,cmp);
	last=1;ans=1;
	for(i=2;i<=t;i++)
		if(b[i].x>b[last].y)ans++,last=i;
		else if(b[i].y<b[last].y)last=i;
	cout<<ans;
	return 0;
}