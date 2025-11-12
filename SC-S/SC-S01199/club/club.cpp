#include<bits/stdc++.h> //70pts
using namespace std;
#define int long long
int t;
int a[100005][3];
int n;
int qzhx[100005];
int zg; 
int ans;
int qqr[100005];
void dfs(int dq1,int dq2,int dq3,int sum,int k){
	if(sum+qzhx[n]-qzhx[k-1]<=ans) return;
	if(k==n+1){
		if(sum>ans) ans=sum;
		return;
	}
	if(dq1<zg) dfs(dq1+1,dq2,dq3,sum+a[k][0],k+1);
	if(dq2<zg) dfs(dq1,dq2+1,dq3,sum+a[k][1],k+1);
	if(dq3<zg) dfs(dq1,dq2,dq3+1,sum+a[k][2],k+1);
	return;
}
bool cmp(int x,int y){
	return x>y;
}
struct node{
	int num;
	int val;
}ac[100005];
bool cmp2(node x,node y){
	return x.val>y.val;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		int xx2=0,xx3=0;
		for(int i=0;i<100005;++i){
			for(int j=0;j<3;++j){
				a[i][j]=0;
			}
			qzhx[i]=0;
			qqr[i]=0;
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				cin>>a[i][j];
			}
			if(a[i][1]!=0) xx2=1;
			if(a[i][2]!=0) xx3=1;
			qzhx[i]=qzhx[i-1]+max(a[i][0],max(a[i][1],a[i][2]));
		}
		zg=n/2;
		if(n<=30) dfs(0,0,0,0,1);
		else{
			if(xx2==0&&xx3==0){
				for(int i=1;i<=n;++i) qqr[i]=a[i][0];
				sort(qqr+1,qqr+1+n,cmp);
				for(int i=1;i<=zg;++i) ans+=qqr[i]; 
			}else if(xx3==0){
				for(int i=1;i<=n;++i){
					ac[i].num=i;
					ac[i].val=a[i][0]-a[i][1];
				}
				sort(ac+1,ac+1+n,cmp2);
				for(int i=1;i<=zg;++i) ans+=a[ac[i].num][0];
				for(int i=n;i>zg;--i) ans+=a[ac[i].num][1];
			}else{
				for(int i=1;i<=n;++i){
					ans+=max(a[i][0],max(a[i][1],a[i][2]));
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}