#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

int n,k;
int a[N];
int s[N];
struct node{
	int l,r;
}squ[N];
int cnt;
bool cmp(node x,node y){
	if(x.r!=y.r) return x.r<y.r;
	return x.l>y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=s[j]^s[i-1];
			if(num==k){
				squ[++cnt]={i,j};
			}
		}
	}
	
	sort(squ+1,squ+cnt+1,cmp);
	int endt=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(squ[i].l>endt){
			ans++;
			endt=squ[i].r;
		}
	}
	cout<<ans;
	

	return 0;
}
