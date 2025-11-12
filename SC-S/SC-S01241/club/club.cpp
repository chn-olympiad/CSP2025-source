#include<bits/stdc++.h>
#define ri register int
#define rll register long long
#define ll long long
#define pint pair<int,int>
#define endl '\n'
using namespace std;
const int N=1e5+5;
int n;
ll ans;
int len[4];
struct people{
	int val,id;
}a[N][4];
struct person{
	int key,posid,now;
	bool operator < (const person& y)const{
		return key<y.key;
	}
	bool operator > (const person& y)const{
		return key>y.key;
	}
};
priority_queue<person,vector<person>,greater<person> >q[4];
inline bool cmp(people x,people y){
	return x.val>y.val;
}
inline void solve(){
	ans=0;
	for(ri i=0;i<=3;i++){
		while(!q[i].empty())q[i].pop();
		len[i]=0;
	}
	cin>>n;
	for(ri i=1;i<=n;i++)for(ri j=1;j<=3;j++)cin>>a[i][j].val,a[i][j].id=j;
	for(ri i=1;i<=n;i++){
		sort(a[i]+1,a[i]+4,cmp);
		int id1=a[i][1].id,id2=a[i][2].id,val1=a[i][1].val,val2=a[i][2].val;
		if(len[id1]<n/2){
			ans+=val1;
			len[id1]++;
			q[id1].push(person{val1-val2,id2,val1});
		}
		else{
			int num=q[id1].top().key,idto=q[id1].top().posid;
			if(val2>val1-num){
				ans+=val2;
				len[id2]++;
				q[id2].push(person{val2-a[i][3].val,a[i][3].id,val2});
			} 
			else{
				ans+=val1-num;
				len[idto]++;
				q[id1].pop();
				q[idto].push(person{0,0,0});
				q[id1].push(person{val1-val2,id2,val1});
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}