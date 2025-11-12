#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],siz[5];
struct hval{
	int from,to,idx;
	int d()const{return a[idx][from]-a[idx][to];}
	bool operator<(const hval &tmp)const{
		return d()>tmp.d();
	}
	bool operator==(const hval &tmp)const{
		return from==tmp.from&&to==tmp.to&&idx==tmp.idx;
	}
};
priority_queue<hval> h,del;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		const int m=n>>1;
		int ans=0;
		siz[1]=siz[2]=siz[3]=0;
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mxi=0;
			for(int j=1;j<=3;++j)
				if(a[i][mxi]<a[i][j])
					mxi=j;
			ans+=a[i][mxi];
			++siz[mxi];
			for(int j=1;j<=3;++j)
				if(mxi!=j)
					h.emplace(hval{mxi,j,i});
		}
		while(!h.empty()){
			while(!h.empty()&&!del.empty()&&h.top()==del.top()){
				h.pop();
				del.pop();
			}
			if(h.empty())	break;
			hval t=h.top();
			h.pop();
			if(siz[t.from]<=m||siz[t.to]>m)
				continue;
			ans-=t.d();
			--siz[t.from];
			++siz[t.to];		
			for(int i=1;i<=3;++i)
				if(i!=t.from&&i!=t.to){
					del.emplace(hval{t.from,i,t.idx});
					h.emplace(hval{t.to,i,t.idx});
					break;
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}