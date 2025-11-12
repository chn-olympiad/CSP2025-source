#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
bool mp[100005];
bool A=true,B=true;
struct node{
	int a,b,c;
}a[100005];
vector<pair<int,int>>l,r;
int f[2][4][100005];
int ans=0;
void dfs(int now,int sum,int cnt_a,int cnt_b,int cnt_c){
	if(now>n)ans=max(ans,sum);
	else{
		if(cnt_a<(n/2))dfs(now+1,sum+a[now].a,cnt_a+1,cnt_b,cnt_c);
		if(cnt_b<(n/2))dfs(now+1,sum+a[now].b,cnt_a,cnt_b+1,cnt_c);
		if(cnt_b<(n/2))dfs(now+1,sum+a[now].c,cnt_a,cnt_b,cnt_c+1);
	}
}
signed main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		A=B=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			A&=(a[i].b==0&&a[i].c==0);
			B&=(a[i].c==0);
		}
		if(A){//A
			sort(a+1,a+n+1,[](node x,node y){return x.a>y.a;});
			for(int i=1;i<=(n/2);i++)
				ans+=a[i].a;
			cout<<ans<<'\n'; 
		}else if(B){//B
			int cnt_b=0,cnt_c=0;
			memset(mp,0,sizeof mp);
			for(int i=1;i<=n;i++){
				if(a[i].a>=a[i].b)l.push_back({a[i].a,a[i].b});
				else r.push_back({a[i].b,a[i].a});
			}
			sort(l.begin(),l.end(),[](pair<int,int>x,pair<int,int>y){return x.first>=y.first;});
			for(int i=0;i<min(signed(l.size()),signed((n/2)));i++)
				ans+=l[i].first;
			for(int i=(n/2);i<l.size();i++)
				r.push_back({l[i].second,l[i].first});
			sort(r.begin(),r.end(),[](pair<int,int>x,pair<int,int>y){return x.first>=y.first;});
			for(int i=0;i<min(signed(n/2),signed(r.size()));i++)
				ans+=r[i].first;
			cout<<ans<<'\n';
		}else if(n>10){//n^114514 
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)
					f[i&1][1][j]=f[i&1][2][j]=f[i&1][3][j]=0;
				int maxn[4];
				memset(maxn,0,sizeof maxn);
				for(int id=1;id<=3;id++)
					for(int j=0;j<=min(i,(n/2));j++)
						maxn[id]=max(maxn[id],f[(i+1)&1][id][j]);
				for(int id=1;id<=3;id++){
					for(int j=1;j<=min((n/2),i);j++){
						f[i&1][id][j]=max({f[(i+1)&1][id][j-1],(id!=1?maxn[1]:0ll),(id!=2?maxn[2]:0ll),(id!=3?maxn[3]:0ll)})+(id==1?a[i].a:0)+(id==2?a[i].b:0)+(id==3?a[i].c:0);
					}
				}
			}
			for(int j=1;j<=(n/2);j++)
				ans=max({ans,f[n&1][1][j],f[n&1][2][j],f[n&1][3][j]});
			cout<<ans<<endl;
		}else{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}

