#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct pl{
	int a,b,c;
	int mx,se,cha,mxid;
	bool operator < (const pl &a) const{
		return cha>a.cha;
	}
}p[201011];
int zd[10];
priority_queue<pl> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		zd[1]=zd[2]=zd[3]=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].mx=max(p[i].a,max(p[i].b,p[i].c));
			int mi=min(p[i].a,min(p[i].b,p[i].c));
			p[i].se=p[i].a+p[i].b+p[i].c-p[i].mx-mi;
			p[i].cha=p[i].mx-p[i].se;
			if(p[i].mx==p[i].a)	p[i].mxid=1;
			if(p[i].mx==p[i].b)	p[i].mxid=2;
			if(p[i].mx==p[i].c)	p[i].mxid=3;
			zd[p[i].mxid]++;
		}
		int xx=max(zd[1],max(zd[2],zd[3])),fi,finow=0;
		if(xx==zd[1])	fi=1;
		if(xx==zd[2])	fi=2;
		if(xx==zd[3])	fi=3;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(p[i].mxid!=fi){
				ans+=p[i].mx;
			}
			else{
				if(finow<n/2){
					finow++;
					q.push(p[i]);
					ans+=p[i].mx;
				}
				else{
					pl ff=q.top();
					q.pop();
					if(ff.cha>p[i].cha){
						q.push(ff);
						ans+=p[i].se;
					}
					else{
						q.push(p[i]);
						ans=ans-ff.mx+ff.se+p[i].mx;
					}
				}
			}
		}
		cout<<ans<<endl;
		while(!q.empty()){
			q.pop();
		}
	}
	return 0;
}
//T1反悔贪心，感觉这辈子有了 
