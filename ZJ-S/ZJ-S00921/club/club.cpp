#include<bits/stdc++.h>
using namespace std;
const int MAXN=114514;
int t,n,lst[MAXN][4];
int main(){
	freopen("club.in","r+",stdin);
	freopen("club.out","w+",stdout);
	cin>>t;
	for(int kkksc03=1;kkksc03<=t;kkksc03++){
		memset(lst,0,sizeof(lst));
		cin>>n;
		vector<pair<int,int> > gp[4];
		long long ans=0,tosolve=0;
		for(int i=1;i<=n;i++){
			cin>>lst[i][1]>>lst[i][2]>>lst[i][3];
			if(lst[i][1]>=lst[i][2]&&lst[i][1]>=lst[i][3]){
				ans+=lst[i][1];
				gp[1].push_back(make_pair(lst[i][1]-max(lst[i][2],lst[i][3]),i));
			}
			else if(lst[i][2]>=lst[i][3]&&lst[i][2]>=lst[i][1]){
				ans+=lst[i][2];
				gp[2].push_back(make_pair(lst[i][2]-max(lst[i][1],lst[i][3]),i));
			}
			else{
				ans+=lst[i][3];
				gp[3].push_back(make_pair(lst[i][3]-max(lst[i][2],lst[i][1]),i));
			}
		}
		if(gp[3].size()>n/2){
			tosolve=3;
		}
		else if(gp[2].size()>n/2){
			tosolve=2;
		}
		else if(gp[1].size()>n/2){
			tosolve=1;
		}
		//cout<<tosolve<<' ';
		if(tosolve!=0){
			sort(gp[tosolve].begin(),gp[tosolve].end());
			for(int i=0;i<gp[tosolve].size()-n/2;i++){
				ans-=gp[tosolve][i].first;
//				if(lst[gp[tosolve][i].second][(tosolve+1)%3]>=lst[gp[tosolve][i].second][(tosolve+2)%3]){
//					gp[(tosolve+1)%3].push_back(make_pair(lst[gp[tosolve][i].second][(tosolve+1)%3]-lst[gp[tosolve][i].second][(tosolve+2)%3],gp[tosolve][i].second));
//				}
//				else{
//					gp[(tosolve+2)%3].push_back(make_pair(lst[gp[tosolve][i].second][(tosolve+2)%3]-lst[gp[tosolve][i].second][(tosolve+1)%3],gp[tosolve][i].second));
//				}
			}
		}
		cout<<ans<<endl;
	}
}
