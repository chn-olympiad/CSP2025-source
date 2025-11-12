#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int T,n,t[5],vis[maxn],p[maxn],q[maxn],r[maxn];
long long ans;
struct node{
	int a,b,c;
}mp[maxn];
void dfs(int d,long long sum){
	if(d>n){
		ans=max(ans,sum);
		return;
	}
	if(t[1]+1<=n/2){
		t[1]++;vis[d]=1;
		dfs(d+1,sum+mp[d].a);
		t[1]--;vis[d]=0;
	}
	if(t[2]+1<=n/2){
		t[2]++;vis[d]=1;
		dfs(d+1,sum+mp[d].b);
		t[2]--;vis[d]=0;
	}
	if(t[3]+1<=n/2){
		t[3]++;vis[d]=1;
		dfs(d+1,sum+mp[d].c);
		t[3]--;vis[d]=0;
	}
}
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		bool flag=1,f=1;
		for(int i=1;i<=n;i++){
			cin>>mp[i].a>>mp[i].b>>mp[i].c;
			if(!(mp[i].b==0&&mp[i].c==0)) flag=0;
			if(mp[i].c!=0) f=0;
		}
		if(flag){
			sort(mp+1,mp+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=mp[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(f){
			int l1=0,l2=0;
			for(int i=1;i<=n;i++){
				if(mp[i].a>mp[i].b){
					l1++;
					ans+=mp[i].a;
					p[l1]=mp[i].a-mp[i].b;
				}else{
					l2++;
					ans+=mp[i].b;
					q[l2]=mp[i].b-mp[i].a;
				}
			}
			//cout<<l1<<" "<<l2<<endl;
			if(l1>n/2){
				sort(p+1,p+1+l1);
				for(int i=1;i<=l1-n/2;i++) ans-=p[i];
			}else if(l2>n/2){
				sort(q+1,q+1+l2);
				for(int i=1;i<=l2-n/2;i++) ans-=q[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n<=10){
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
			if(mp[i].a==mp[i].b&&mp[i].a>mp[i].c){
				ans+=mp[i].a;
				if(l1<l2){
					l1++;
					p[l1]=mp[i].a-mp[i].c;
				}else{
					l2++;
					q[l2]=mp[i].b-mp[i].c;
				}
			}else if(mp[i].b==mp[i].c&&mp[i].b>mp[i].a){
				ans+=mp[i].b;
				if(l2<l3){
					l1++;
					q[l2]=mp[i].b-mp[i].a;
				}else{
					l3++;
					r[l3]=mp[i].c-mp[i].a;
				}
			}else if(mp[i].a==mp[i].c&&mp[i].a>mp[i].b){
				ans+=mp[i].a;
				if(l1<l3){
					l1++;
					p[l1]=mp[i].a-mp[i].b;
				}else{
					l3++;
					r[l3]=mp[i].c-mp[i].b;
				}
			}else if(mp[i].a==mp[i].b&&mp[i].a==mp[i].c){
				if(l1<l2&&l1<l3){
					l1++;
					p[l1]=mp[i].a-mp[i].b;
				}else if(l2<l1&&l2<l3){
					l2++;
					q[l2]=mp[i].a-mp[i].b;
				}else {
					l3++;
					r[l3]=mp[i].a-mp[i].b;
				}
			}else if(mp[i].a>mp[i].b&&mp[i].a>mp[i].c){
				l1++;
				ans+=mp[i].a;
				p[l1]=min(mp[i].a-mp[i].b,mp[i].a-mp[i].c);
			}else if(mp[i].b>mp[i].a&&mp[i].b>mp[i].c){
				l2++;
				ans+=mp[i].b;
				q[l2]=min(mp[i].b-mp[i].a,mp[i].b-mp[i].c);
			}else{
				l3++;
				ans+=mp[i].c;
				r[l3]=min(mp[i].c-mp[i].a,mp[i].c-mp[i].b);
			}
		}
		if(l1>n/2){
			sort(p+1,p+1+l1);
			for(int i=1;i<=l1-n/2;i++) ans-=p[i];
		}else if(l2>n/2){
			sort(q+1,q+1+l2);
			for(int i=1;i<=l2-n/2;i++) ans-=q[i];
		}else if(l3>n/2){
			sort(r+1,r+1+l3);
			for(int i=1;i<=l3-n/2;i++) ans-=r[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
