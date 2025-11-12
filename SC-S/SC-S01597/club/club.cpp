#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int T,n;
struct stu{
	int lov[5],que;
	pii fav={0,0},lfav={0,0};
	void init(){
		fav=make_pair(0,0),lfav=make_pair(0,0);
		for(int i=1;i<=3;i++) if(fav.first<lov[i]) fav=make_pair(lov[i],i);
		for(int i=1;i<=3;i++){
			if(i==fav.second) continue;
			if(lfav.first<lov[i]) lfav=make_pair(lov[i],i);
		}
		que=fav.first-lfav.first;
	}
} clu[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>clu[i].lov[1]>>clu[i].lov[2]>>clu[i].lov[3];
		for(int i=1;i<=n;i++) clu[i].init();
		int bo[5]={0},sum=0;
		for(int i=1;i<=n;i++){
			bo[clu[i].fav.second]++;
			sum+=clu[i].fav.first;
		}
		int mx=-1;
		for(int i=1;i<=3;i++){
			if(bo[i]>(n/2)) mx=i;
		}
		if(mx==-1){
			cout<<sum<<"\n";
		}else{
			priority_queue<int,vector<int>,greater<int> >q;
			for(int i=1;i<=n;i++){
				if(clu[i].fav.second==mx) q.push(clu[i].fav.first-clu[i].lfav.first);
			}
			for(int i=1;i<=bo[mx]-(n/2);i++){
				sum-=q.top();q.pop();
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}