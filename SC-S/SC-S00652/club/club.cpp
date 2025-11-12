#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+10;
int T;
int n;
struct NODE{
	int x,y,z;
}d[N];
int t1,t2,t3,t[N];
int ans=0;
priority_queue<int> st;
void solve(){
	cin>>n;ans=t1=t2=t3=0;
	for(int i=1;i<=n;i++){
		cin>>d[i].x>>d[i].y>>d[i].z;
		int aa=max({d[i].x,d[i].y,d[i].z});
		if(aa==d[i].x)t1++,t[i]=1;
		if(aa==d[i].y)t2++,t[i]=2;
		if(aa==d[i].z)t3++,t[i]=3;
		ans+=aa;
	}
	int tmx=max({t1,t2,t3});
	if(tmx<=n/2){
		cout<<ans<<'\n';
		return;
	}
	while(!st.empty())st.pop();
	if(t1>(n/2)){
//		cout<<1<<'\n';
		for(int i=1;i<=n;i++){
			if(t[i]==1){
				if(d[i].y>d[i].z)st.push(-d[i].x+d[i].y);
				else st.push(-d[i].x+d[i].z);
			}
		}
		while(st.size()>n/2){
			auto it=st.top();st.pop();
			ans+=it;
		}
		cout<<ans<<'\n';
		return;
	}
	if(t2>(n/2)){
		for(int i=1;i<=n;i++){
			if(t[i]==2){
				if(d[i].x>d[i].z)st.push(-d[i].y+d[i].x);
				else st.push(-d[i].y+d[i].z);
			}
		}
		while(st.size()>n/2){
			auto it=st.top();st.pop();
			ans+=it;
		}
		cout<<ans<<'\n';
		return;
	}
	if(t3>(n/2)){
//	cout<<1<<'\n';
		for(int i=1;i<=n;i++){
			if(t[i]==3){
				if(d[i].y>d[i].x)st.push(-d[i].z+d[i].y);
				else st.push(-d[i].z+d[i].x);
			}
		}
		while(st.size()>n/2){
			auto it=st.top();st.pop();
			ans+=it;
		}
		cout<<ans<<'\n';
		return;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}