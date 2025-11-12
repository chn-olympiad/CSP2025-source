#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,k,f[N],x,sum,s,a[N],cnt,sl,sr;
struct node{
	int l,r;
}b[N];
bool cmp(node sx,node sy){
	return sx.l<sy.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x^a[i-1];
		if(x==k) f[i]=1,sum++;
		if(x<=1) s++;
	}
	if(s==n){
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		if(f[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(f[j]) break;
			if((a[j]^a[i-1])==k){
				cnt++;
				b[cnt].l=i,b[cnt].r=j;
				break;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	sum+=cnt;
	sl=b[1].l,sr=b[1].r;
	for(int i=2;i<=cnt;i++){
		if(b[i].r<sr) sl=b[i].l,sr=b[i].r,sum--;
		else if(b[i].l>sr) sl=b[i].l,sr=b[i].r;
		else sum--;
	}
	cout<<sum;
	return 0;
}