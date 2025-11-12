#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],d[N],k[N][4],loc[N][4],t[4];
int n,ans,T;
int mid;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > a1,b1,c1;
void pl(priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > &q,int ma,int i){
	if(ans-q.top().first+ma+k[q.top().second][2]>ans){
		if(t[loc[q.top().second][2]]<mid){
			if(loc[q.top().second][2]==1){
				a1.push(q.top());
				q.pop();
				q.push({ma,i});
			}
			if(loc[q.top().second][2]==2){
				b1.push(q.top());
				q.pop();
				q.push({ma,i});
			}
			if(loc[q.top().second][2]==3){
				c1.push(q.top());
				q.pop();
				q.push({ma,i});
			}
			t[loc[q.top().second][2]]++;
		}
		else{
			if(loc[q.top().second][2]==1){
				pl(a1,k[q.top().second][2],q.top().second);
			}
			if(loc[q.top().second][2]==2){
				pl(b1,k[q.top().second][2],q.top().second);
			}
			if(loc[q.top().second][2]==3){
				pl(c1,k[q.top().second][2],q.top().second);
			}
		}
		ans=ans-q.top().first+ma+k[q.top().second][2];
	}
	else{
		if(loc[q.top().second][3]==1){
				a1.push(q.top());
				q.pop();
				q.push({ma,i});
			}
			if(loc[q.top().second][3]==2){
				b1.push(q.top());
				q.pop();
				q.push({ma,i});
			}
			if(loc[q.top().second][3]==3){
				c1.push(q.top());
				q.pop();
				q.push({ma,i});
			}
			ans+=k[q.top().second][3];
			t[loc[q.top().second][3]]++;
	}
} 
void solve(){
	mid=n/2;
	ans=0;
	for(int i=1;i<=n;i++){
		t[1]=t[2]=t[3]=0;
		cin>>a[i]>>b[i]>>c[i];
		int ma=0,idx;
		if(a[i]>ma) ma=a[i],idx=1;
		if(b[i]>ma) ma=b[i],idx=2;
		if(c[i]>ma) ma=c[i],idx=3;
		k[i][1]=ma,loc[i][1]=idx;
		if(idx==1) {
			k[i][2]=max(b[i],c[i]),k[i][3]=min(b[i],c[i]);
			if(k[i][2]==b[i]) loc[i][2]=2,loc[i][3]=3;
			else loc[i][2]=3,loc[i][3]=2;
		}
		if(idx==2) {
			k[i][2]=max(a[i],c[i]),k[i][3]=min(a[i],c[i]);
			if(k[i][2]==a[i]) loc[i][2]=1,loc[i][3]=3;
			else loc[i][2]=3,loc[i][3]=1;
		}
		if(idx==3){
			k[i][2]=max(a[i],b[i]),k[i][3]=min(a[i],b[i]);
			if(k[i][2]==a[i]) loc[i][2]=1,loc[i][3]=2;
			else loc[i][2]=2,loc[i][3]=1;
		} 
		if(t[idx]<mid) {
			t[idx]++;
			ans+=ma;
			if(idx==1) a1.push({ma,i});
			if(idx==2) b1.push({ma,i});
			if(idx==3) c1.push({ma,i});
		} 
		else{
			if(idx==1) pl(a1,ma,i);
			if(idx==2) pl(b1,ma,i);
			if(idx==3) pl(c1,ma,i);
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	bool f=0;
	while(T--){
		cin>>n;
		if(n>200||f){
			int ans=0;
			f=1;
			for(int i=1;i<=n;i++){
				cin>>b[i]>>c[i]>>d[i];
				sort(b+1,b+n+1);
				for(int i=n;i>=n/2;i--){
					ans+=b[i];
				} 
				cout<<ans<<endl;
			}
		}
		else solve();
	}
	return 0;
} 
