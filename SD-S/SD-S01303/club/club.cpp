#include<bits/stdc++.h>

using namespace std;
const int MAXN=100000+10;

	int t,n;
	int cnt[5];

struct Node{
	int a,b,c,x,sum1,sum2,gx;
	bool operator <(const Node &rhs)const{
		return gx>rhs.gx;
	}
}d[MAXN];
struct an{
	int id,dis;
}l[5];
bool cmp(an a,an b){
	return a.dis>b.dis;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;long long ans=0;
		memset(cnt,0,sizeof(cnt));
		priority_queue<Node>qa;
		priority_queue<Node>qb;
		priority_queue<Node>qc; 
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			l[1].id=1,l[1].dis=d[i].a;
			l[2].id=2,l[2].dis=d[i].b;
			l[3].id=3,l[3].dis=d[i].c;
			sort(l+1,l+3+1,cmp);
//			cout<<l[1].dis<<" "<<l[2].dis<<" "<<l[3].dis<<endl;
			d[i].x=l[1].id;
			d[i].gx=l[1].dis-l[2].dis;
			d[i].sum1=l[1].dis;
			d[i].sum2=l[2].dis;
			if(cnt[d[i].x]+1>n/2){
				if(d[i].x==1){
					Node t=qa.top();
					if(t.gx<d[i].gx){
						qa.pop();
						ans-=t.sum1;
						ans+=t.sum2;
						ans+=d[i].sum1;
						qa.push(d[i]);
					} 
					else ans+=d[i].sum2; 
				}
				if(d[i].x==2){
					Node t=qb.top();
					if(t.gx<d[i].gx){
						qb.pop();
						ans-=t.sum1;
						ans+=t.sum2;
						ans+=d[i].sum1;
						qb.push(d[i]);
					} 
					else ans+=d[i].sum2; 
				}
				if(d[i].x==3){
					Node t=qc.top();
					if(t.gx<d[i].gx){
						qc.pop();
						ans-=t.sum1;
						ans+=t.sum2;
						ans+=d[i].sum1;
						qc.push(d[i]);
					} 
					else ans+=d[i].sum2; 
				}
			}
			else{
				cnt[d[i].x]++;
				if(d[i].x==1){
					qa.push(d[i]);
					ans+=d[i].sum1;
				}
				if(d[i].x==2){
					qb.push(d[i]);
					ans+=d[i].sum1;
				}
				if(d[i].x==3){
					qc.push(d[i]);
					ans+=d[i].sum1;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
