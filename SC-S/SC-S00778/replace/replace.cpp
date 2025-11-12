#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,pq,ph;
long long tot;
struct edge{
	string x,s;//x替换为s 
}e[N];
string p,tmp,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>e[i].x>>e[i].s;
	while(q--){
		cin>>p>>ans;
		tot=0;
		for(int i=1;i<=n;i++){
			if(p.find(e[i].x)<p.size()){
				tmp=p;
				tmp=tmp.replace(p.find(e[i].x),e[i].x.size(),e[i].s);
				if(tmp==ans) tot++;
			}
		} 
		cout<<tot<<'\n';
	}
	return 0;
} 