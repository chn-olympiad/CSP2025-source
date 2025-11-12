#include<bits/stdc++.h>
using namespace std;
int T,n,b[4],c[4],d[4];
long long ans;
priority_queue<int,vector<int>,greater<int> > q[4];
struct x{
	int maxn,submax;
	int a1,a2,a3;
	bool operator<(const x& other) const{
		if(maxn!=other.maxn )return maxn>other.maxn;
		return submax>other.submax;
	}
};
x a[100001];
int MAX(int x1,int x2,int x3){
	int t=0,ans=0;
	if(x1>x2){
		ans=1;t=x1;
	}
	else  t=x2,ans=2;
	if(t<x3){
		ans=3;
		t=x3;
	}
	return t;
}
int submax(int i){
	int ans=0,t=0;
	if(a[i].a1<a[i].maxn) {
		ans=1;
		t=a[i].a1;
	}
	if(a[i].a2<a[i].maxn) {
		if(a[i].a2>t&&t>0) return a[i].a2;
		if(t==0)t=a[i].a2;
		ans=2;
	}
	if(a[i].a3<a[i].maxn) {
		if(a[i].a3>t) return a[i].a3;
	}
	return t;
}
int find(int x,int i){
	if(x==a[i].a1) return 1;
	else if(x==a[i].a2) return 2;
    else return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
 	cin.tie(0),cout.tie(0);

	cin>>T;
	while(T--){
		for(int i=1;i<=3;i++)while(!q[i].empty()) q[i].pop();
		ans=0;
		c[1]=c[2]=c[3]=10000001;
		cin>>n;
		b[1]=b[2]=b[3]=0;
		d[1]=d[2]=d[3]=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].maxn=MAX(a[i].a1,a[i].a2,a[i].a3);
			
			a[i].submax=submax(i);
		}
		sort(a+1,a+n+1);
		//for(int i=1;i<=n;i++) cout<<a[i].a1<<" "<<a[i].a2<<" "<<a[i].a3<<" "<<a[i].maxn<<" "<<a[i].submax<<"\n";
		for(int i=1;i<=n;i++){
			int num=find(a[i].maxn,i);
			if(b[num]<n/2) {
				//cout<<i<<" "<<b[num]<<" ";
				b[num]+=1;
				q[num].push(a[i].maxn-a[i].submax);
				//cout<<a[i].maxn<<"\n";
				ans+=a[i].maxn;
				//cout<<ans<<"\n";
			}
			else {
				//int subnum=find(a[d[i]].submax,i);
				//cout<<a[i].submax<<"\n";
				if(!q[num].empty()&&q[num].top()<a[i].maxn-a[i].submax) {
					//cout<<q[num].top()<<"\n";
					ans+=a[i].maxn-q[num].top();
					q[num].pop();
					q[num].push(a[i].maxn-a[i].submax);
					//cout<<a[i].maxn+a[d[num]].submax-c[num]<<"\n";
				 }
				
				else{
					ans+=a[i].submax;
					//cout<<a[i].submax<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
}

