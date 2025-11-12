#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N],b[N],c[N],vis[N];
vector<int> vec[5];
int n1,n2,n3;
struct node{
	int x,id;
}d[N*3];
bool cmp(node A,node B){
	return A.x>B.x;
}
void sol(){
	scanf("%d",&n);
	n1=n2=n3=0;
	int ans=0;
	for(int t=1;t<=3;++t) vec[t].clear();
	for(int i=1;i<=n;++i){
		vis[i]=0;
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		if(a[i]>=b[i]&&a[i]>=c[i]) vec[1].push_back(i),++n1,ans+=a[i];
		else if(b[i]>=a[i]&&b[i]>=c[i]) vec[2].push_back(i),++n2,ans+=b[i];
		else if(c[i]>=a[i]&&c[i]>=b[i]) vec[3].push_back(i),++n3,ans+=c[i];
	}
	int p=0,cnt=0;
	if(n1>n/2){
		for(int i:vec[1]){
			d[++p].id=i; d[p].x=b[i]-a[i];
			d[++p].id=i; d[p].x=c[i]-a[i];
		}
		cnt=n1-n/2;
	}
	if(n2>n/2){
		for(int i:vec[2]){
			d[++p].id=i; d[p].x=a[i]-b[i];
			d[++p].id=i; d[p].x=c[i]-b[i];
		}
		cnt=n2-n/2;
	}
	if(n3>n/2){
		for(int i:vec[3]){
			d[++p].id=i; d[p].x=a[i]-c[i];
			d[++p].id=i; d[p].x=b[i]-c[i];
		}
		cnt=n3-n/2;
	}
//	printf("%d\n",cnt);
	if(p>0) sort(d+1,d+p+1,cmp);
	for(int i=1;i<=p && cnt>0;++i){
		if(!vis[d[i].id]){
			ans+=d[i].x;
			vis[d[i].id]=1;
			--cnt;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--) sol();
	return 0;
}
