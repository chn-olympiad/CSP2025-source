#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//BA!
struct member{
	int a;
	int b;
	int c;
	pair<int,int> ma;
	pair<int,int> sm;
	pair<int,int> mi;
	int deta;
};
member cb[N];
int n,st[4];
void solve(int sd){
	int ans=0;
	for(int i=1;i<=3;i++){
		st[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(st[cb[i].ma.second]>=sd){
			if(st[cb[i].sm.second]>=sd){
				st[cb[i].mi.second]++;
				ans+=cb[i].mi.first;
//				cerr<<cb[i].mi.second<<" "<<st[cb[i].sm.second]<<"\n";
			}else{
				ans+=cb[i].sm.first;
				st[cb[i].sm.second]++;
//				cerr<<cb[i].sm.second<<" "<<st[cb[i].sm.second]<<"\n";
			}
		}else{
			st[cb[i].ma.second]++;
			ans+=cb[i].ma.first;
//			cerr<<cb[i].ma.second<<" "<<st[cb[i].ma.second]<<"\n";
		}
	}
	cout<<ans<<"\n";
//	cerr<<ans<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cb[i].a>>cb[i].b>>cb[i].c;
			int t1=cb[i].a,t2=1,t3=-1,t4=-1,t5=cb[i].a,t6=1;
			if(t1<cb[i].b){
				t1=cb[i].b;
				t2=2;
			}if(t1<cb[i].c){
				t1=cb[i].c;
				t2=3;
			}if(t5>cb[i].b){
				t5=cb[i].b;
				t6=2;
			}if(t5>cb[i].c){
				t5=cb[i].c;
				t6=3;
			}
			for(int j=1;j<=3;j++){
				if(j!=t2&&j!=t6){
					t4=j;
					break;
				}
			}if(t4==1) t3=cb[i].a;
			else if(t4==2) t3=cb[i].b;
			else t3=cb[i].c;
			cb[i].ma={t1,t2};
			cb[i].sm={t3,t4};
			cb[i].mi={t5,t6};
			cb[i].deta=t1-t3;
		}
		int pm=n/2;
//		cerr<<"Aya\n";
		sort(cb+1,cb+1+n,[&](member x,member y){
			if(x.deta!=y.deta) return x.deta>y.deta;
			return x.ma>y.ma;
		});
		solve(pm);
	}
	return 0;
}
