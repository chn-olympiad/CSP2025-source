#include<bits/stdc++.h>
//priority_queue
//unsigned
//cout.flush()
//sync_with_stdio
//long long,file,momrey
using namespace std;
//club
int n;
struct z{
	int a,b;
}l[5];
int id(int i){
	if(i==0){
		return 1e9;
	}
	return abs(i);
}
bool cmp(z a,z b){
	return a.b<b.b;
}
vector<int>b[5];
int cnt=0;
void ans(int id){
	for(int i=0;i+n/2<b[id].size();i++){
		cnt-=b[id][i];
	}
}
void tmin(){
	cnt=0;
	b[1].clear();
	b[2].clear();
	b[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[1].b>>l[2].b>>l[3].b;
		l[1].a=1;
		l[2].a=2;
		l[3].a=3;
		sort(l+1,l+1+3,cmp);
		b[l[3].a].push_back(l[3].b-l[2].b);
		cnt+=l[3].b;
	}
	sort(b[1].begin(),b[1].end());
	sort(b[2].begin(),b[2].end());
	sort(b[3].begin(),b[3].end());
	if(b[1].size()>n/2){
		ans(1);
	}
	if(b[2].size()>n/2){
		ans(2);
	}
	if(b[3].size()>n/2){
		ans(3);
	}
	cout<<cnt<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		tmin();
	}
}
