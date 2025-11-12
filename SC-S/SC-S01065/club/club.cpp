#include<bits/stdc++.h>
using namespace std;

ifstream fin("club.in");
ofstream fout("club.out");
#define cin fin
#define cout fout

int n;

priority_queue<int> q[3];

void work(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;++i){
		vector<int> v(3),id={0,1,2};
		cin>>v[0]>>v[1]>>v[2];
		sort(id.begin(),id.end(),[&](int a,int b){
			return v[a]>v[b];
		});
		ans+=v[id[0]];
		q[id[0]].push(v[id[1]]-v[id[0]]);
	}
	if(q[1].size()>q[0].size()) q[0].swap(q[1]);
	if(q[2].size()>q[0].size()) q[0].swap(q[2]);
	while(q[0].size()>n/2){
		ans+=q[0].top();
		q[0].pop();
	}
	cout<<ans<<"\n";
	while(q[0].size()) q[0].pop();
	while(q[1].size()) q[1].pop();
	while(q[2].size()) q[2].pop();
}

signed main(){
	int T;
	for(cin>>T;T--;work());
	return 0;
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(); }
} wtl;