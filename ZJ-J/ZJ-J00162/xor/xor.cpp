#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N];
struct node{
	int l,r;
}b[N];
bool cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	else return x.l>y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0,s=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=ans^a[j];
			if(ans==k){
				s++;
				b[s].l=i;
				b[s].r=j;
				break;	
			}
		}
		ans=0;
	}
	sort(b+1,b+s+1,cmp);
	int now=0,d=0;
	for(int i=1;i<=s;i++){
		if(now<b[i].l){
			d++;
			now=b[i].r;	
		}
	}
	cout<<d;
	return 0;
}