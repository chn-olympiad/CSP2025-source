#include <bits/stdc++.h>
#define N 10010
using namespace std;
int n,m,k;
struct coord{
	int lian;
	int fei;
};
int a,b,e;
vector<coord>v[N];
int cun[20][N];
coord tmp;
bool mx=true,mo=false,jian=false;
bool cheng[20];
int xiao;
coord dai[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(cheng,false,sizeof(cheng));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>e;
		tmp.fei=e;
		tmp.lian=b;
		v[a].push_back(tmp);
		tmp.lian=a;
		v[b].push_back(tmp);
	}
	for(int i=1;i<=k;i++){
		cin>>cun[i][0];
		for(int j=1;j<=n;j++){
			cin>>cun[i][j];
			if(cun[i][j]!=0){
				mx=false;
			}
		}
		if(mx&&cun[0]==0){
			mo=true;
			jian=true;
		}
	}
	if(jian){
		cout<<0;
	}
}
