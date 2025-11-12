#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,T;
int a[N][5];
int dp[N];
typedef pair<int,pair<int,int> > pii;
priority_queue<pii,vector<pii>,greater<pii> > q1;//放入的是(min(a[x][1]-a[x][2],a[x][1]-a[x][3])，(x,1或3))
priority_queue<pii,vector<pii>,greater<pii> > q2;
priority_queue<pii,vector<pii>,greater<pii> > q3;
int check(int x){
	int t1=-1,t2=-1,t3=-1,t4=-1,t5=-1,t6=-1;
	//cout<<q1.size()<<" "<<q2.size()<<" "<<q3.size()<<"::";
	if(q1.size()<m) t1=a[x][1];
	if(q2.size()<m) t2=a[x][2];
	if(q3.size()<m) t3=a[x][3];
	if(q1.size() && q2.size()<m)t4=max(t4,a[x][1]-a[q1.top().second.first][1]+a[q1.top().second.first][2]);
	if(q1.size() && q3.size()<m)t4=max(t4,a[x][1]-a[q1.top().second.first][1]+a[q1.top().second.first][3]);
	if(q2.size() && q1.size()<m){
		t5=max(t5,a[x][2]-a[q2.top().second.first][2]+a[q2.top().second.first][1]);
		//cout<<a[x][2]<<"--"<<a[q2.top().second][2]<<"--"<<a[q2.top().second][1]<<"--";
	}
	if(q2.size() && q3.size()<m){
		t5=max(t5,a[x][2]-a[q2.top().second.first][2]+a[q2.top().second.first][3]);
		//cout<<a[x][2]<<"--"<<a[q2.top().second][2]<<"--"<<a[q2.top().second][3]<<"--";
	}
	if(q3.size() && q2.size()<m)t6=max(t6,a[x][3]-a[q3.top().second.first][3]+a[q3.top().second.first][2]);
	if(q3.size() && q1.size()<m)t6=max(t6,a[x][3]-a[q3.top().second.first][3]+a[q3.top().second.first][1]);
	int maxn=-1;
	//cout<<x<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<"\n";         
	maxn=max(t1,max(t2,max(t3,max(t4,max(t5,t6)))));
	if(maxn==t1) q1.push({min(a[x][1]-a[x][2],a[x][1]-a[x][3]),{x,(a[x][1]-a[x][2])>(a[x][1]-a[x][3])?3:2}});
	else if(maxn==t2) q2.push({min(a[x][2]-a[x][1],a[x][2]-a[x][3]),{x,(a[x][2]-a[x][1])>(a[x][2]-a[x][3])?3:1}});
	else if(maxn==t3) q3.push({min(a[x][3]-a[x][1],a[x][3]-a[x][2]),{x,(a[x][3]-a[x][2])>(a[x][3]-a[x][1])?1:2}});
	else if(maxn==t4){
		if(q1.top().second.second==2){
			q2.push({min(a[q1.top().second.first][2]-a[q1.top().second.first][1],a[q1.top().second.first][2]-a[q1.top().second.first][3]),{q1.top().second.first,(a[q1.top().second.first][2]-a[q1.top().second.first][1])>(a[q1.top().second.first][2]-a[q1.top().second.first][3])?3:1}});
		}else if(q1.top().second.second==3){
			q3.push({min(a[q1.top().second.first][3]-a[q1.top().second.first][1],a[q1.top().second.first][3]-a[q1.top().second.first][2]),{q1.top().second.first,(a[q1.top().second.first][3]-a[q1.top().second.first][2])>(a[q1.top().second.first][3]-a[q1.top().second.first][1])?1:2}});
		}
		q1.pop();
		q1.push({min(a[x][1]-a[x][2],a[x][1]-a[x][3]),{x,(a[x][1]-a[x][2])>(a[x][1]-a[x][3])?3:2}});
	}else if(maxn==t5){
		if(q2.top().second.second==1){
			q1.push({min(a[q2.top().second.first][1]-a[q2.top().second.first][2],a[q2.top().second.first][1]-a[q2.top().second.first][3]),{q2.top().second.first,(a[q2.top().second.first][1]-a[q2.top().second.first][2])>(a[q2.top().second.first][1]-a[q2.top().second.first][3])?3:2}});
		}else if(q2.top().second.second==3){
			q3.push({min(a[q2.top().second.first][3]-a[q2.top().second.first][1],a[q2.top().second.first][3]-a[q2.top().second.first][2]),{q2.top().second.first,(a[q2.top().second.first][3]-a[q2.top().second.first][2])>(a[q2.top().second.first][3]-a[q2.top().second.first][1])?1:2}});
		}
		q2.push({min(a[x][2]-a[x][1],a[x][2]-a[x][3]),{x,(a[x][2]-a[x][1])>(a[x][2]-a[x][3])?3:1}});
		q2.pop();
	}else if(maxn==t6){
		if(q3.top().second.second==2){
			q2.push({min(a[q3.top().second.first][2]-a[q3.top().second.first][1],a[q3.top().second.first][2]-a[q3.top().second.first][3]),{q3.top().second.first,(a[q3.top().second.first][2]-a[q3.top().second.first][1])>(a[q3.top().second.first][2]-a[q3.top().second.first][3])?3:1}});
		}else if(q3.top().second.second==1){
			q1.push({min(a[q3.top().second.first][1]-a[q3.top().second.first][2],a[q3.top().second.first][1]-a[q3.top().second.first][3]),{q3.top().second.first,(a[q3.top().second.first][1]-a[q3.top().second.first][2])>(a[q3.top().second.first][1]-a[q3.top().second.first][3])?3:2}});
		}
		q3.push({min(a[x][3]-a[x][1],a[x][3]-a[x][2]),{x,(a[x][3]-a[x][2])>(a[x][3]-a[x][1])?1:2}});
		q3.pop();
	}
	return maxn+dp[x-1];
}
void solve(){
	cin>>n;
	m=n/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=3;i++){
		dp[1]=max(dp[1],a[1][i]);              
	}
	if(dp[1]==a[1][1]){
		q1.push({min(a[1][1]-a[1][2],a[1][1]-a[1][3]),{1,(a[1][1]-a[1][2])>(a[1][1]-a[1][3])?3:2}});
	}else
	if(dp[1]==a[1][2]){
		q2.push({min(a[1][2]-a[1][3],a[1][2]-a[1][1]),{1,(a[1][2]-a[1][1])>(a[1][2]-a[1][3])?3:1}});
	}else
	if(dp[1]==a[1][3]){
		q3.push({min(a[1][3]-a[1][1],a[1][3]-a[1][2]),{1,(a[1][3]-a[1][1])>(a[1][3]-a[1][2])?2:1}});
	}
	for(int i=2;i<=n;i++){
		dp[i]=check(i);
	}
	cout<<dp[n]<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		while(q3.size()) q3.pop();
		solve();
	} 
	return 0;
} 