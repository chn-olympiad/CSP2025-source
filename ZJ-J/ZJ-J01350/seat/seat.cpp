#include <bits/stdc++.h>
using namespace std;
int n,m,i,s1,s2;
struct no{
	int cj,xh;
}a[1010];
bool cmp(no q,no h){
	return q.cj>h.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n*m;i++) cin>>a[i].cj,a[i].xh=i;
	sort(a+1,a+n*m+1,cmp);
	for (i=1;i<=n*m;i++)
		if(a[i].xh==1) break;
	s1=i/n;
	s2=i%n;
	if(!s2) 
		if(s1%2) cout<<s1<<" "<<n;
		else cout<<s1<<" "<<1;
	else
		if((s1+1)%2) cout<<s1+1<<" "<<s2;
		else cout<<s1+1<<" "<<n-s2+1;
}
