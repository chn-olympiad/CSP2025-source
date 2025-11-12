#include<bits/stdc++.h>
using namespace std;
long long i,a[500005],n,k,s,m=0,j,ans=1,r;
struct node{
	long long x,y;
}b[500005];
bool cmp(node q,node p){
	if (q.y<p.y) return 1;
	if (q.y==p.y&&q.x<p.x) return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (i=1;i<=n;i++)
		cin>>a[i];
	for (i=1;i<=n;i++){
		s=a[i];
		if (s==k){
			m++;
			b[m].x=i;
			b[m].y=i;
		}
		for (j=i+1;j<=n;j++){
			s^=a[j];
			if (s==k){
				m++;
				b[m].x=i;
				b[m].y=j;
				break;
			}
		}
	}
	if (m==0){
		cout<<0;
		return 0;
	}
	sort(b+1,b+1+m,cmp);
	r=b[1].y;
	for (i=2;i<=m;i++){
		if (b[i].x>r){
			r=b[i].y;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
