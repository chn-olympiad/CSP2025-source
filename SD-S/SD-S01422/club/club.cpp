#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n;
ll l;
struct qw{
	int a,b,c,ma,p,cm;
}a[N];
vector<int>v[5];
priority_queue<pair<int,int> >p;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a==max(a[i].a,max(a[i].b,a[i].c))){
				a[i].ma=a[i].a,a[i].p=1;
				a[i].cm=max(a[i].b,a[i].c);
			}else if(a[i].b==max(a[i].a,max(a[i].b,a[i].c))){
				a[i].ma=a[i].b,a[i].p=2;
				a[i].cm=max(a[i].a,a[i].c);
			}else{
				a[i].ma=a[i].c,a[i].p=3;
				a[i].cm=max(a[i].a,a[i].b);
			}
			p.push({a[i].ma,i});
		}
		v[1].clear();v[2].clear();v[3].clear();
		l=0;
		while(p.size()){
			pair<int,int>q=p.top();
			p.pop();
			int x=q.second;
			l=l+a[x].ma;
			v[a[x].p].push_back(a[x].cm-a[x].ma);
//			cout<<a[x].ma<<"a"<<a[x].p<<endl;
		}
		if(v[1].size()>n/2){
			sort(v[1].begin(),v[1].end());
			for(int i=v[1].size()-1;i>=n/2;i--){
				l+=v[1][i];
			}
		}else if(v[2].size()>n/2){
			sort(v[2].begin(),v[2].end());
			for(int i=v[2].size()-1;i>=n/2;i--){
				l+=v[2][i];
			}
		}else if(v[3].size()>n/2){
			sort(v[3].begin(),v[3].end());
			for(int i=v[3].size()-1;i>=n/2;i--){
				l+=v[3][i];
			}
		}
		cout<<l<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
