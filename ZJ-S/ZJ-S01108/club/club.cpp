#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,id;
	int fi,se;
	int fiv,sev;
};
node a[100005];
struct club{
	int val,id;
}b[4];
bool comp(club p, club q){
	return p.val>q.val;
}
bool comp2(node p, node q){
	if(p.fiv==q.fiv) return p.fiv>q.fiv;
	else return p.sev>q.sev;
}
int n, ans, num[4];
vector<int> vc[4];
struct st{
	int id, val;
};
struct cmp{
	bool operator()(st zi, st fa){
		return zi.val>fa.val;
	}
};
priority_queue<st, vector<st>, cmp> q[4];
void dfs(int x){
	if(x==n+1){
		int res=0;
		for(int i=1; i<=3; i++){
			for(int j:vc[i]){
				if(i==1) res+=a[j].x;
				if(i==2) res+=a[j].y;
				if(i==3) res+=a[j].z;
			}
		}
		ans=max(ans,res);
		return;
	}
	for(int i=1; i<=3; i++){
		if(vc[i].size()<n/2){
			vc[i].push_back(x);
			dfs(x+1);
			vc[i].pop_back();
		}
	}
}
void test(){
	ans=0;
	for(int i=1; i<=3; i++) num[i]=0, vc[i].clear();
	scanf("%d",&n);
	bool flaga=1;
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].y!=0||a[i].z!=0) flaga=0;
		a[i].id=i;
		b[1].val=a[i].x; b[1].id=1; 
		b[2].val=a[i].y; b[2].id=2; 
		b[3].val=a[i].z; b[3].id=3; 
		sort(b+1,b+1+3,comp);
		a[i].fi=b[1].id; a[i].fiv=b[1].val;
		a[i].se=b[2].id; a[i].sev=b[2].val;
	}
	if(n<=30){
		dfs(1);
		cout<<ans<<endl;
		return;
	}
	sort(a+1,a+1+n,comp2);
	if(flaga==1){
		for(int i=1; i<=n/2; i++) ans+=a[i].fiv;
		cout<<ans<<endl;
		return;
	}
	for(int i=1; i<=3; i++){
		while(!q[i].empty()) q[i].pop();
	}
	//for(int i=1; i<=n; i++){
	//	cout<<a[i].fi<<' '<<a[i].fiv<<' '<<a[i].se<<' '<<a[i].sev;
	//	cout<<endl;
	//}
	for(int i=1; i<=n; i++){
		if(q[a[i].fi].size()<n/2){
			q[a[i].fi].push({a[i].id,a[i].fiv});
			ans+=a[i].fiv;
		}
		else{
			st t=q[a[i].fi].top();
			//cout<<t.id<<' '<<t.val<<endl;
			if(a[t.id].sev+a[i].fiv>a[i].sev+a[t.id].fiv){
				q[a[i].fi].pop();
				q[a[t.id].se].push({t.id,a[t.id].sev});
				q[a[i].fi].push({a[i].id,a[i].fiv});
				ans-=a[t.id].fiv;
				ans+=a[t.id].sev+a[i].fiv;
			}
			else{
				q[a[i].se].push({a[i].id,a[i].sev});
				ans+=a[i].sev;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) test();
	return 0;
}