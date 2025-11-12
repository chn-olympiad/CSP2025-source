#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
int n,k;
int a[N];
int d[N];
struct p{
	int x, y;
}asb[1100100];
bool cmp(p n1, p n2){
	if(n1.y==n2.y)return n1.x<n2.x;
	return n1.y<n2.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		d[i]=a[i]^d[i-1];
	}
	int ans=0;
	int m=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			int x=d[j]^d[i-1];
			if(x==k){
				asb[++m].x=i,asb[m].y=j;		
				break;
			}
	}
	sort(asb+1,asb+m+1,cmp);
	int l=0;
	for(int i=1;i<=m;i++){
		if(l<asb[i].x){
			ans++;
			l=asb[i].y;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

