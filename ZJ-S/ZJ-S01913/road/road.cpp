#include<bits/stdc++.h>
using namespace std;
int n,m,k,sl,o,p,op,jg[15],lg[1030],cnt,xy;
long long ans=0x3f3f3f3f3f3f3f3f,an;
bitset<15> v2;
bitset<10015> v;
vector<pair<int,int> > tu[10015];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
inline int lowbit(int x){
	return x&-x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,h;i<=m;++i){
		scanf("%d%d%d",&x,&y,&h);
		tu[x].emplace_back(make_pair(y,h));
		tu[y].emplace_back(make_pair(x,h));
	}
	sl=1;
	for(int i=1;i<=k;++i){
		lg[sl]=i;
		sl<<=1;
		scanf("%d",&jg[i]);
		for(int j=1,x;j<=n;++j){
			scanf("%d",&x);
			tu[i+n].emplace_back(make_pair(j,x));
			tu[j].emplace_back(make_pair(i+n,x));
		}
	}
	for(int i=0;i<sl;++i){
		o=i;
		p=lowbit(i);
		v.reset();
		v2.reset();
		xy=n;
		an=0;
		while(o){
			v2[lg[p]]=1;
			an+=jg[lg[p]];
			xy++;
			o-=p;
			p=lowbit(o);
		}
		if(an>=ans){
			continue;
		}
		while(q.size()){
			q.pop();
		}
		cnt=1;
		v[1]=1;
		for(pair<int,int> to:tu[1]){
			o=to.first;
			p=to.second;
			if(o>n&&v2[o-n]==0){
				continue;
			}
			q.push({p,o});
		}
		while(q.size()){
			pair<int,int> now=q.top();
			q.pop();
			o=now.first;
			p=now.second;
			if(v[p]){
				continue;
			}
			v[p]=1;
			an+=o;
			cnt++;
			if(cnt==xy||an>=ans){
				break;
			}
			for(pair<int,int> to:tu[p]){
				o=to.first;
				op=to.second;
				if(v[o]||(o>n&&v2[o-n]==0)){
					continue;
				}
				q.push({op,o});
			}
		}
		ans=min(ans,an);
	}
	printf("%lld",ans);
	return 0;
}

