#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int T,n,a[100005][3],cv[100005][3];
vector<int> club[3],agn;
bool cmp1(int x,int y){
	return a[1][x]>a[1][y];
}
bool cmp2(int x,int y){
	return a[2][x]>a[2][y];
}
bool cmp3(int x,int y){
	return a[3][x]>a[3][y];
}
void init(){
	club[1].clear();club[2].clear();club[0].clear();
	agn.clear();
	memset(a,0,sizeof(a));memset(cv,0,sizeof(cv));
}
void solve(){
	cin>>n;
	int sum0=0,sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		cv[i][0]=a[i][0],cv[i][1]=a[i][1],cv[i][2]=a[i][2];
		sum0+=a[i][0];sum1+=a[i][1];sum2+=a[i][2];
	} 
	sum0/=n,sum1/=n,sum2/=n;
	for(int i=1;i<=n;i++){
		a[i][0]-=sum0,a[i][1]-=sum1,a[i][2]-=sum2;
		int maxx=max(a[i][0],max(a[i][1],a[i][2]));
		if(maxx==a[i][0]) club[0].push_back(i);
		else if(maxx==a[i][1]) club[1].push_back(i);
		else club[2].push_back(i);
	}	
	int maxn=n/2;
	sort(club[1].begin(),club[1].end(),cmp1);
	sort(club[2].begin(),club[2].end(),cmp2);
	sort(club[3].begin(),club[3].end(),cmp3);
	for(int i=0;i<3;i++){
		while(club[i].size()>maxn){
			int pos=club[i].back();
			agn.push_back(pos);
			club[i].pop_back();
		}
	}
	for(int i:agn){
		int maxx=max(max(a[i][1],a[i][2]),a[i][0]);
		int minn=min(min(a[i][1],a[i][2]),a[i][0]);
		if(maxx!=a[i][1]&&minn!=a[i][1]) club[1].push_back(i);
		if(maxx!=a[i][2]&&minn!=a[i][2]) club[2].push_back(i);
		if(maxx!=a[i][0]&&minn!=a[i][0]) club[0].push_back(i);
	}
	for(int i=0;i<3;i++){
		while(club[i].size()>maxn){
			int pos=club[i].back();
			agn.push_back(pos);
			club[i].pop_back();
		}
	}
	for(int i:agn){
		int minn=min(min(a[i][1],a[i][2]),a[i][0]);
		if(minn==a[i][1]) club[1].push_back(i);
		if(minn==a[i][2]) club[2].push_back(i);
		if(minn==a[i][0]) club[0].push_back(i);
	}
	int ans=0;
	for(int i=0;i<3;i++){
		for(int j:club[i]){
	 		ans+=cv[j][i];
		}
	}
	cout<<ans<<'\n';
	init();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
}
