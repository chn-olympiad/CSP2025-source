#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int T,n;
ll ans;
int cnt[5];
struct node{
	int a,b,c;
	bool operator<(const node &y)const{
		return max({a,b,c})<max({y.a,y.b,y.c});
	}
}x[N];
priority_queue<int,vector<int>,greater<int> >q[5];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		while(!q[1].empty())q[1].pop();
		while(!q[2].empty())q[2].pop();
		while(!q[3].empty())q[3].pop();
		cin>>n;
		for(int i=1;i<=n;i++)cin>>x[i].a>>x[i].b>>x[i].c;
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			int mx=max({x[i].a,x[i].b,x[i].c});
			if(x[i].a==mx){
				int val=0;
				if(x[i].b>x[i].c)val=x[i].a-x[i].b;
				else val=x[i].a-x[i].c;
				if(cnt[1]+1>n/2){
					if(!q[1].empty()&&q[1].top()<val){
						ans-=q[1].top();
						ans+=x[i].a;
						q[1].pop();
						q[1].push(val);
					}
					else ans+=x[i].a-val;
				}
				else{
					++cnt[1];
					ans+=x[i].a;
					q[1].push(val);
				}
			}
			else if(x[i].b==mx){
				int val=0;
				if(x[i].a>x[i].c)val=x[i].b-x[i].a;
				else val=x[i].b-x[i].c;
				if(cnt[2]+1>n/2){
					if(!q[2].empty()&&q[2].top()<val){
						ans-=q[2].top();
						ans+=x[i].b;
						q[2].pop();
						q[2].push(val);
					}
					else ans+=x[i].b-val;
				}
				else{
					++cnt[2];
					ans+=x[i].b;
					q[2].push(val);
				}
			}
			else if(x[i].c==mx){
				int val=0;
				if(x[i].a>x[i].b)val=x[i].c-x[i].a;
				else val=x[i].c-x[i].b;
				if(cnt[3]+1>n/2){
					if(!q[3].empty()&&q[3].top()<val){
						ans-=q[3].top();
						ans+=x[i].c;
						q[3].pop();
						q[3].push(val);
					}
					else ans+=x[i].c-val;
				}
				else{
					++cnt[3];
					ans+=x[i].c;
					q[3].push(val);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
