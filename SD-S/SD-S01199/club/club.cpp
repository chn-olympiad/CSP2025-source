#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+10;
struct node{
	int x,person,kind;
}p[N];
bool cmp(node l,node r){
	return l.x>r.x;
}
int n,cnt,ans;
int mp[10],a[210][10],s[10010];
bool st[N/2];
void dfs(int now,int sum,int num1,int num2,int num3,int t){
	if(now==n+1){
//		for(int i=1;i<=n;i++) cout<<s[i]<<" ";
//		cout<<"\n";
		ans=max(ans,sum);
		return;
	}
	if(num1>n/2) return;
	if(num2>n/2) return;
	if(num3>n/2) return;
//	if(now==1) cout<<a[i][1]<<"\n";
	if(a[now][1] and num1+1<=n/2)dfs(now+1,sum+a[now][1],num1+1,num2,num3,t+1);
	if(a[now][2] and num2+1<=n/2)dfs(now+1,sum+a[now][2],num1,num2+1,num3,t+1);
	if(a[now][3] and num3+1<=n/2)dfs(now+1,sum+a[now][3],num1,num2,num3+1,t+1);
//		cout<<"\n"<<i<<"\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		memset(mp,0,sizeof mp);
		memset(st,0,sizeof st);
		cnt=0,ans=0;
		cin>>n;
		if(n==2){
			int mx1,mx2,mx3;
			int a,b,c;
			cin>>a>>b>>c;
			mx1=a,mx2=b,mx3=c;
			int x,y,z;
			cin>>x>>y>>z;
			int mx_1=max(mx1+y,mx1+z);
			int mx_2=max(mx2+x,mx2+z);
			int mx_3=max(mx3+x,mx3+y);
			cout<<max(mx_1,max(mx_2,mx_3))<<"\n";
			continue;
		}
		if(n<=30){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>a[i][j];
				}
			}
			dfs(1,0,0,0,0,1);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
				cin>>x;
				if(x) p[++cnt]={x,i,j};
			}
		}
		sort(p+1,p+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			if(st[p[i].person]) continue;
			if(mp[p[i].kind]>=n/2) continue;
			ans+=p[i].x;
			mp[p[i].kind]++;
			st[p[i].person]=1;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=cnt;i++) p[i].x=p[i].kind=p[i].person=0;
	}
	return 0;
}
