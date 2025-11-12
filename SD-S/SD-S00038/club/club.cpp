#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1e5+5;
int n,ans;
struct Person{
	int p1,p2,p3;
	int ma,mc,pa,pc;
}a[N];
struct node{
	int x,id;
	bool operator < (const node & a)const{
		return x < a.x;
	}
};
priority_queue<node> pq[4]; 
int cnt[4];
bool cmp1(Person x,Person y){
	return -x.ma+x.mc>-y.ma+y.mc;
}
void compare(int i){
	if(a[i].p1>=a[i].p2&&a[i].p1>=a[i].p3){
		a[i].ma=a[i].p1;a[i].pa=1;
		if(a[i].p2>=a[i].p3){a[i].mc=a[i].p2;a[i].pc=2;}
		else{a[i].mc=a[i].p3;a[i].pc=3;}
	}
	if(a[i].p2>=a[i].p1&&a[i].p2>=a[i].p3){
		a[i].ma=a[i].p2;a[i].pa=2;
		if(a[i].p1>=a[i].p3){a[i].mc=a[i].p1;a[i].pc=1;}
		else{a[i].mc=a[i].p3;a[i].pc=3;
		}
	}
	if(a[i].p3>=a[i].p1&&a[i].p3>=a[i].p2){
		a[i].ma=a[i].p3;a[i].pa=3;
		if(a[i].p1>=a[i].p2){a[i].mc=a[i].p1;a[i].pc=1;}
		else{a[i].mc=a[i].p2;a[i].pc=2;}
	}
}
void init(){
	ans=0;
	for(int i=1;i<=3;i++){
		cnt[i]=0;
		while(!pq[i].empty())pq[i].pop();
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].p1>>a[i].p2>>a[i].p3;
			compare(i);
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].pa]<n/2){
				ans+=a[i].ma;
				cnt[a[i].pa]++;
				pq[a[i].pa].emplace(node{-a[i].ma+a[i].mc,i});
			}
			else{
				int val=pq[a[i].pa].top().x;
				int ex=pq[a[i].pa].top().id;
				if(val+a[i].ma>=0){
					ans+=val+a[i].ma;
					cnt[a[ex].pc]++;
					pq[a[i].pa].pop();
					pq[a[i].pa].emplace(node{-a[i].ma+a[i].mc,i});
				}
				else if(val+a[i].ma<0){
					ans+=a[i].mc;
					cnt[a[i].pc]++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
