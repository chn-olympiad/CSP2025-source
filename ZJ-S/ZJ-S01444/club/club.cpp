#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=1e5+5;
int t,n;
int a[N][4],cnt[4];
struct node{
	int t1,t2,t3;//zuida,cida,zuixiao
}id[N];
struct edge{
	int data,id;
};
bool cmp(edge x,edge y){
	if(x.data!=y.data)return x.data>y.data;
	if(cnt[x.id]!=cnt[y.id])return cnt[x.id]<cnt[y.id];
	return x.id<y.id;
} 
void paixu(int i){
	edge s[]={{a[i][1],1},{a[i][2],2},{a[i][3],3}};
	sort(s,s+3,cmp);
	id[i].t1=s[0].id;
	id[i].t2=s[1].id;
	id[i].t3=s[2].id;
}
void solve(){
	//<cha,id>
	priority_queue<PII,vector<PII>,greater<PII> >q1;
	priority_queue<PII,vector<PII>,greater<PII> >q2;
	priority_queue<PII,vector<PII>,greater<PII> >q3;
	memset(id,0,sizeof(id));
	memset(a,0,sizeof(a));
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		paixu(i);
		if(cnt[id[i].t1]+1>n/2){
			if(id[i].t1==1){
				PII x=q1.top();
				if(x.first<a[i][id[i].t1]-a[i][id[i].t2]){
					q1.pop();
					if(id[x.second].t2==2)q2.push({a[x.second][id[x.second].t1]-a[x.second][id[x.second].t2],x.second}),cnt[2]++;
					if(id[x.second].t2==3)q3.push({a[x.second][id[x.second].t1]-a[x.second][id[x.second].t2],x.second}),cnt[3]++;
					q1.push({a[i][id[i].t1]-a[i][id[i].t2],i});
				}
				else{
					if(id[i].t2==2)q2.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[2]++;
					if(id[i].t2==3)q3.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[3]++;
				}	
			}
			
			else if(id[i].t1==2){
				PII x=q2.top();
				if(x.first<a[i][id[i].t1]-a[i][id[i].t2]){
					q2.pop();
					if(id[x.second].t2==1)q1.push({a[x.second][id[x.second].t1]-a[x.second][id[x.second].t2],x.second}),cnt[1]++;
					if(id[x.second].t2==3)q3.push({a[x.second][id[x.second].t1]-a[x.second][id[x.second].t2],x.second}),cnt[3]++;
					q2.push({a[i][id[i].t1]-a[i][id[i].t2],i});
				}
				else{
					if(id[i].t2==1)q1.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[1]++;
					if(id[i].t2==3)q3.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[3]++;
				}
			}
			
			else{
				PII x=q3.top();
				if(x.first<a[i][id[i].t1]-a[i][id[i].t2]){
					q3.pop();
					if(id[x.second].t2==1)q1.push({a[x.second][id[x.second].t1]-a[x.second][id[x.second].t2],x.second}),cnt[1]++;
					if(id[x.second].t2==2)q2.push({a[x.second][id[x.second].t1]-a[x.second][id[x.second].t2],x.second}),cnt[2]++;
					q3.push({a[i][id[i].t1]-a[i][id[i].t2],i});
				}
				else{
					if(id[i].t2==1)q1.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[1]++;
					if(id[i].t2==2)q2.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[2]++;
				}
			}
		}
		else{
			if(id[i].t1==1)q1.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[1]++;
			if(id[i].t1==2)q2.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[2]++;
			if(id[i].t1==3)q3.push({a[i][id[i].t1]-a[i][id[i].t2],i}),cnt[3]++;
		}
	}
	int ans=0;
	while(!q1.empty()){
		ans+=a[q1.top().second][1];
		q1.pop();
	}
	while(!q2.empty()){
		ans+=a[q2.top().second][2];
		q2.pop();
	}
	while(!q3.empty()){
		ans+=a[q3.top().second][3];
		q3.pop();
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
