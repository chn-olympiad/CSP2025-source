#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int t,n;

struct node{
	int d1,d2,d3,val,s;
}a[N];
bool cmp(node x,node y){
	if(x.d1!=y.d1){
		return x.d1>y.d2;
	}else if(x.d2!=y.d2){
		return x.d2>y.d2;
	}else{
		return x.d3>y.d3;
	}
}
int maxn(node num){
	return max({num.d1,num.d2,num.d3});
}
int minn(node num){
	return min({num.d1,num.d2,num.d3});
}
int mid(node num){
	vector<int> v;
	v.push_back(num.d1);
	v.push_back(num.d2);
	v.push_back(num.d3);
	sort(v.begin(),v.end());
	return v[1];
}
bool operator < (const node x,const node y){
	return x.val<y.val;
}
priority_queue<node> q[5];
void init(){
	priority_queue<node> x;
	q[1]=q[2]=q[3]=x;
}
void solve(){
	init();
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
		a[i].val=max({a[i].d1,a[i].d2,a[i].d3})-mid(a[i]);
		if(a[i].d1==mid(a[i])) a[i].s=1;
		else if(a[i].d2==mid(a[i])) a[i].s=2;
		else a[i].s=3;
	}
	sort(a+1,a+1+n,cmp);
	long long ans = 0;
	for(int i = 1;i<=n;i++){
		if(a[i].d1==maxn(a[i])){
			if(q[1].size()>=n/2){
				if(q[1].top().val<a[i].val){
					ans-=q[1].top().val;
					q[q[1].top().s].push(q[1].top());
					q[1].pop();
					q[1].push(a[i]);
					ans+=a[i].d1;
				}else{
					ans+=mid(a[i]);
					q[a[i].s].push(a[i]);
				}
			}else{
				ans+=a[i].d1;
				q[1].push(a[i]);
			}
		}else if(a[i].d2==maxn(a[i])){
			if(q[2].size()>=n/2){
				if(q[2].top().val<a[i].val){
					ans-=q[2].top().val;
					q[q[2].top().s].push(q[2].top());
					q[2].pop();
					q[2].push(a[i]);
					ans+=a[i].d2;
				}else{
					ans+=mid(a[i]);
					q[a[i].s].push(a[i]);
				}
			}else{
				ans+=a[i].d2;
				q[2].push(a[i]);
			}
		}else if(a[i].d3==maxn(a[i])){
			if(q[3].size()>=n/2){
				if(q[3].top().val<a[i].val){
					ans-=q[3].top().val;
					q[q[3].top().s].push(q[3].top());
					q[3].pop();
					q[3].push(a[i]);
					ans+=a[i].d3;
				}else{
					ans+=mid(a[i]);
					q[a[i].s].push(a[i]);
				}
			}else{
				ans+=a[i].d3;
				q[3].push(a[i]);
			}
		}
	}
	cout<<ans<<endl;
}	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
}
