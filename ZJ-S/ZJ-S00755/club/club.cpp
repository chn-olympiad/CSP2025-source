#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n;
int a[N][5];
vector<int> v[5];
int ans;
int D(int x){
	return max(max(a[x][1],a[x][2]),a[x][3])-(a[x][1]+a[x][2]+a[x][3]-max(max(a[x][1],a[x][2]),a[x][3])-min(min(a[x][1],a[x][2]),a[x][3]));
}
bool cmp(int x,int y){
	int d1=D(x);
	int d2=D(y);
	return d1<d2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		v[1].clear();v[2].clear();v[3].clear();
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])v[1].push_back(i),ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])v[2].push_back(i),ans+=a[i][2];
			else v[3].push_back(i),ans+=a[i][3];
		}
		int id;
		if(v[1].size()>=v[2].size()&&v[1].size()>=v[3].size())id=1;
		else if(v[2].size()>=v[1].size()&&v[2].size()>=v[3].size())id=2;
		else id=3;
		sort(v[id].begin(),v[id].end(),cmp);
		for(int i=0;v[id].size()-i>n/2;i++){
			ans-=D(v[id][i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
