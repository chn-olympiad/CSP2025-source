#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5+5;
int  T,n,max_ans=0,ans;
struct node{
	pair<int,int> t[5];
	int id,p=1;
	friend bool operator <(node a,node b){
		return (a.t[a.p].first-a.t[a.p+1].first)>(b.t[b.p].first-b.t[b.p+1].first);
	}
}mp[maxn];
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}
priority_queue<node> q1,q2,q3;
void Blance(){
	if(q1.size()>n/2){
		node x=q1.top();
		q1.pop();
		ans-=mp[x.id].t[mp[x.id].p].first;
		mp[x.id].p++;
		ans+=mp[x.id].t[mp[x.id].p].first;
		if(mp[x.id].t[mp[x.id].p].second==1){
			q1.push(mp[x.id]);
		}
		if(mp[x.id].t[mp[x.id].p].second==2){
			q2.push(mp[x.id]);
		}
		if(mp[x.id].t[mp[x.id].p].second==3){
			q3.push(mp[x.id]);
		}
	}else if(q2.size()>n/2){
		node x=q2.top();
		q2.pop();
		ans-=mp[x.id].t[mp[x.id].p].first;
		mp[x.id].p++;
		ans+=mp[x.id].t[mp[x.id].p].first;
		if(mp[x.id].t[mp[x.id].p].second==1){
			q1.push(mp[x.id]);
		}
		if(mp[x.id].t[mp[x.id].p].second==2){
			q2.push(mp[x.id]);
		}
		if(mp[x.id].t[mp[x.id].p].second==3){
			q3.push(mp[x.id]);
		}
	}else if(q3.size()>n/2){
		node x=q3.top();
		q3.pop();
		ans-=mp[x.id].t[mp[x.id].p].first;
		mp[x.id].p++;
		ans+=mp[x.id].t[mp[x.id].p].first;
		if(mp[x.id].t[mp[x.id].p].second==1){
			q1.push(mp[x.id]);
		}
		if(mp[x.id].t[mp[x.id].p].second==2){
			q2.push(mp[x.id]);
		}
		if(mp[x.id].t[mp[x.id].p].second==3){
			q3.push(mp[x.id]);
		}
	}
}
void add(int id){
	int to=mp[id].t[mp[id].p].second;
	if(to==1){
		q1.push(mp[id]);
	}
	if(to==2){
		q2.push(mp[id]);
	}
	if(to==3){
		q3.push(mp[id]);
	}
	ans+=mp[id].t[mp[id].p].first;
	Blance();
}
void clear(){
	while(!q1.empty()){
		q1.pop();
	}
	while(!q2.empty()){
		q2.pop();
	}
	while(!q3.empty()){
		q3.pop();
	}
	max_ans=0;
	ans=0;
	for(int i=1;i<=n;i++){
		mp[i].p=1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>mp[i].t[j].first;
				mp[i].t[j].second=j;
			}
			sort(mp[i].t+1,mp[i].t+4,cmp);
			mp[i].id=i;
		}
		for(int i=1;i<=n;i++){
			add(i);
			max_ans=max(ans,max_ans);
		}
		cout<<max_ans<<endl;
		clear();
	}
}