#include<bits/stdc++.h>
using namespace std;
const int maxn=(1<<20)+5;
int f[maxn],a[500005],pre[500005];
vector<int>b[maxn];
struct node{
	int x,y;
}c[500005];
bool cmp(node x,node y){
	if(x.y==y.y) return x.x<y.x;
	return x.y<y.y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		f[pre[i]]++;
		b[pre[i]].push_back(i);
		c[i].x=1e9;
		c[i].y=1e9;
	}
	for(int i=1;i<=n;i++){
		int x=pre[i-1]^k;
		if(b[x].size()>=1){
			int l=0,r=b[x].size()-1,mid;
			while(l<r){
				mid=(l+r)/2;
				if(b[x][mid]>=i) r=mid;
				else l=mid+1;
			}
			if(b[x][l]>=i){
				c[i].x=i;
				c[i].y=b[x][l];
			}
		}
	}
	sort(c+1,c+n+1,cmp);
	int m=0,sum=0;
	for(int i=1;i<=n;i++){
		if(c[i].x>m&&c[i].x!=1e9){
			m=c[i].y;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
