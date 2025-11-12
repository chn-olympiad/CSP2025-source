#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
//#define DEBUG_MODE
using namespace std;
struct member{
	int a_best;
	int down_cost;
	int best_seat;
};
vector<member> X;
int a;
bool CostCmp(member p,member q){
	return p.down_cost<q.down_cost;
}
void Xinput(int n){
	int top_a;
	int second_a;
	int top_seat;
	for(int i=0;i<n;i++){
		top_a=0;
		second_a=0;
		for(int j=0;j<3;j++){
			scanf("%d",&a);
			if (a>top_a){
				second_a=top_a;
				top_a=a;
				top_seat=j;
			}
			else if(a>second_a)
				second_a=a;
		}
		X[i].best_seat=top_seat;
		X[i].a_best=top_a;
		X[i].down_cost=top_a-second_a;
	}
	#ifdef DEBUG_MODE
		cerr<<"--debug mode--"<<endl;
		for(int i=0;i<n;i++){
			cerr<<"member"<<i<<":"<<endl;
			cerr<<"	a_best:"<<X[i].a_best<<endl;
			cerr<<"	down_cost:"<<X[i].down_cost<<endl;
			cerr<<"	best_seat:"<<X[i].best_seat<<endl;
		}
		cerr<<"--debug ends--"<<endl;
	#endif
}
void solve(int n){
	long long ans=0;
	#ifdef DEBUG_MODE
		cerr<<"--debug mode--"<<endl;
		cerr<<ans<<endl;
		cerr<<"--debug ends--"<<endl;
	#endif
	vector<int> pcnt;
	member M;
	pcnt.resize(3);
	for(int i=0;i<n;i++){
		M=X[i];
		pcnt[M.best_seat]++;
		ans+=M.a_best*1ll;
		#ifdef DEBUG_MODE
			cerr<<"--debug mode--"<<endl;
			cerr<<ans<<endl;
			cerr<<"--debug ends--"<<endl;
		#endif
	}
	int down_cnt;
	int j;
	for(int i=0;i<3;i++){
		down_cnt=pcnt[i]-(n>>1);
		if(down_cnt>0){
			sort(X.begin(),X.end(),CostCmp);
				#ifdef DEBUG_MODE
					cerr<<"--debug mode--"<<endl;
					for(int k=0;k<n;k++){
						cerr<<"member"<<k<<":"<<endl;
						cerr<<"	a_best:"<<X[k].a_best<<endl;
						cerr<<"	down_cost:"<<X[k].down_cost<<endl;
						cerr<<"	best_seat:"<<X[k].best_seat<<endl;
					}
					cerr<<"--debug ends--"<<endl;
				#endif
			j=0;
			while(down_cnt>0){
				M=X[j];
				if(M.best_seat==i){
					ans-=M.down_cost*1ll;
					down_cnt--;
				}
				j++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	scanf("%d",&t);
	while(t>0){
		scanf("%d",&n);
		X.resize(n);
		Xinput(n);
		solve(n);
		t--;
	}
	return 0;
}
