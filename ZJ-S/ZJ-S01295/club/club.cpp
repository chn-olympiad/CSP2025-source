#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e5+10;
int n,_;
struct node{
	int a,b,c;
	bool operator<(const node& y) const {
		int dx=max(a,max(b,c)),dy=max(y.a,max(y.b,y.c));
		return dx>dy;
	}
}p[N];
vector<int> ac,bc,cc;
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> _;
	while(_--){
		ac.clear();
		bc.clear();
		cc.clear();
		ans=0;
		cin >> n;
		for(int i = 1;i <= n;i ++){
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		sort(p+1,p+1+n);
		for(int i = 1;i <= n;i ++){
			int d=max(p[i].a,max(p[i].b,p[i].c));
			if(d==p[i].a){
				int x=1,minn=ac.size();
				if(d==p[i].b && bc.size()<minn)	minn=bc.size(),x=2;
				if(d==p[i].c && cc.size()<minn)	minn=cc.size(),x=3;
				if(x==1)	ac.pb(i);
				else if(x==2)	bc.pb(i);
				else cc.pb(i);
			}else if(d==p[i].b){
				int x=2,minn=bc.size();
				if(d==p[i].c && cc.size()<minn)	minn=cc.size(),x=3;
				if(x==2)	bc.pb(i);
				else cc.pb(i);
			}else{
				cc.pb(i);
			}
		}
		int A=ac.size(),B=bc.size(),C=cc.size();
		for(int i = 0;i < A;i ++){
			ans+=p[ac[i]].a;
		}
		for(int i = 0;i < B;i ++){
			ans+=p[bc[i]].b;
		}
		for(int i = 0;i < C;i ++){
			ans+=p[cc[i]].c;
		}
		if(ac.size()>n/2){
			int k=ac.size()-n/2,cnt1=0,cnt2=0;
			priority_queue<pii> q;
			for(int i = 0;i < ac.size();i ++){
				if(cnt2+1+cc.size()>n/2 || (p[ac[i]].b > p[ac[i]].c && cnt1+1+bc.size() <= n/2)){
					if(p[ac[i]].c > p[ac[i]].b){
						if(q.top().se==3 && q.top().fi>p[ac[i]].a-p[ac[i]].c){
							q.pop();
							q.push({p[ac[i]].a-p[ac[i]].c,3});
							continue;
						}
					}
					cnt1++;
					q.push({p[ac[i]].a-p[ac[i]].b,2});
				}else{
					if(p[ac[i]].b > p[ac[i]].c){
						if(q.top().se==2 && q.top().fi>p[ac[i]].a-p[ac[i]].b){
							q.pop();
							q.push({p[ac[i]].a-p[ac[i]].b,2});
							continue;
						}
					}
					cnt2++;
					q.push({p[ac[i]].a-p[ac[i]].c,3});
				}
				if(q.size() > k){
					int x=q.top().se;
					if(x==2)	cnt1--;
					else	cnt2--;
					q.pop();
				}
			}
			while(!q.empty() && k){
				k--;
				ans-=q.top().fi;
				q.pop();
			}
		}else if(bc.size()>n/2){
			int k=bc.size()-n/2,cnt1=0,cnt2=0;
			priority_queue<pii> q;
			for(int i = 0;i < bc.size();i ++){
				if(cnt2+1+cc.size()>n/2 || (p[bc[i]].a > p[bc[i]].c && cnt1+1+ac.size() <= n/2)){
					if(p[bc[i]].c > p[bc[i]].a){
						if(q.top().se==3 && q.top().fi>p[bc[i]].b-p[bc[i]].c){
							q.pop();
							q.push({p[bc[i]].b-p[bc[i]].c,3});
							continue;
						}
					}
					cnt1++;
					q.push({p[bc[i]].b-p[bc[i]].a,1});
				}else{
					if(p[bc[i]].a > p[bc[i]].c){
						if(q.top().se==1 && q.top().fi>p[bc[i]].b-p[bc[i]].a){
							q.pop();
							q.push({p[bc[i]].b-p[bc[i]].a,1});
							continue;
						}
					}
					cnt2++;
					q.push({p[bc[i]].b-p[bc[i]].c,3});
				}
				if(q.size() > k){
					int x=q.top().se;
					if(x==1)	cnt1--;
					else	cnt2--;
					q.pop();
				}
			}
			while(!q.empty() && k){
				k--;
				ans-=q.top().fi;
				q.pop();
			}
		}else if(cc.size()>n/2){
			int k=cc.size()-n/2,cnt1=0,cnt2=0;
			priority_queue<pii> q;
			for(int i = 0;i < cc.size();i ++){
				if(cnt2+1+bc.size()>n/2 || (p[cc[i]].a > p[cc[i]].b && cnt1+1+ac.size() <= n/2)){
					if(p[cc[i]].b > p[cc[i]].a){
						if(q.top().se==2 && q.top().fi>p[cc[i]].c-p[cc[i]].b){
							q.pop();
							q.push({p[cc[i]].c-p[bc[i]].b,2});
							continue;
						}
					}
					cnt1++;
					q.push({p[cc[i]].c-p[cc[i]].a,1});
				}else{
					if(p[cc[i]].a > p[cc[i]].b){
						if(q.top().se==1 && q.top().fi>p[cc[i]].c-p[cc[i]].a){
							q.pop();
							q.push({p[cc[i]].c-p[bc[i]].a,1});
							continue;
						}
					}
					cnt2++;
					q.push({p[cc[i]].c-p[cc[i]].b,2});
				}
				if(q.size() > k){
					int x=q.top().se;
					if(x==1)	cnt1--;
					else	cnt2--;
					q.pop();
				}
			}
			while(!q.empty() && k){
				k--;
				ans-=q.top().fi;
				q.pop();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
