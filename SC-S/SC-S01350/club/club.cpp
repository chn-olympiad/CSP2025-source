#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int s[4];
	int mx;
	int use;
}a[100010];
bool cmpmx(node a,node b){
	return a.mx>b.mx;
}
int hv[4];
struct Node{
	int id,x;
};
bool operator<(Node a,Node b){
	return a.x<b.x;
}
priority_queue<int>q[4];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
//	q[1].push(1),q[1].push(2);
//	cout<<q[1].top()<<endl;
	while(T--){
		cin>>n;
		hv[1]=hv[2]=hv[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
			a[i].mx=max(a[i].s[1],max(a[i].s[2],a[i].s[3]));
			if(a[i].s[1]>a[i].s[2]&&a[i].s[1]>a[i].s[3])a[i].use=1;
			else if(a[i].s[2]>a[i].s[3])a[i].use=2;
			else a[i].use=3;
//			cout<<a[i].use<<endl;
		}
//		cout<<"---"<<endl;
		sort(a+1,a+n+1,cmpmx);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(hv[a[i].use]==n/2){
				int now=-1e9;
				if(a[i].use!=1)now=max(now,a[i].s[1]-a[i].s[a[i].use]);
				if(a[i].use!=2)now=max(now,a[i].s[2]-a[i].s[a[i].use]);
				if(a[i].use!=3)now=max(now,a[i].s[3]-a[i].s[a[i].use]);
//				cout<<now<<endl;
				ans+=a[i].s[a[i].use];
				if(now<q[a[i].use].top()){
					ans+=q[a[i].use].top();
//					cout<<q[a[i].use].top()<<endl;
					q[a[i].use].pop();
					q[a[i].use].push(now);
				}else{
					ans+=now;
				}
			}else{
				int now=-1e9;
				if(a[i].use!=1)now=max(now,a[i].s[1]-a[i].s[a[i].use]);
				if(a[i].use!=2)now=max(now,a[i].s[2]-a[i].s[a[i].use]);
				if(a[i].use!=3)now=max(now,a[i].s[3]-a[i].s[a[i].use]);
				q[a[i].use].push(now);
				hv[a[i].use]++;
				ans+=a[i].s[a[i].use];
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=3;i++)while(!q[i].empty())q[i].pop();
	}
	
	return 0;
}
/*
感觉是反悔贪心 

先按照自己的意愿去，如果满了，就需要跟人交换 
用优先队列记录当前换到其他地方的最小值 
因为不存在两个都满的情况，所以没问题 

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
0 1 0
0 1 0
0 2 0
0 2 0

1
2
10 9 8
4 0 0

*/