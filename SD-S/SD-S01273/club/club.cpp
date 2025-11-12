#include<bits/stdc++.h>
#define int long long
using namespace std;
//UID:1137851
//FUCK Magus CYB
//FUCK zzldd DJM 
//HAPPY
const int N=1e5+5;
int t;
int n;
int a[N][5];
struct node{
	int cha,val,pla,bei;
}xc[N];
vector <node> club[5];
int clubsize[5];
bool cmp(node a,node b){
	return a.cha>b.cha;
}
void solve(int num){
	sort(club[num].begin(),club[num].end(),cmp);
	for(int i=clubsize[num]-1;i>=(n/2);i--){
		node ow=club[num][i];
		club[ow.bei].push_back(ow);
		clubsize[ow.bei]++;
		clubsize[num]--;
	}
}
int cnt(){
	int ans=0;
	for(int i=1;i<=3;i++)
		for(int j=0;j<clubsize[i];j++)
			ans+=a[club[i][j].pla][i];
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--){
		memset(xc,0,sizeof(xc));
		cin>>n;
		club[1].clear();
		club[2].clear();
		club[3].clear();
		clubsize[1]=0;
		clubsize[2]=0;
		clubsize[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			xc[i].val=a[i][1]+a[i][2]+a[i][3]-min({a[i][1],a[i][2],a[i][3]})-max({a[i][1],a[i][2],a[i][3]});
			if(xc[i].val==a[i][1])
				xc[i].bei=1;
			else if(xc[i].val==a[i][2])
				xc[i].bei=2;
			else
				xc[i].bei=3;
			xc[i].pla=i;
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			xc[i].cha=maxn-xc[i].val;
			int col=0;
			if(maxn==a[i][1]){
				col=1;
				club[1].push_back(xc[i]);
				clubsize[1]++;
			}else if(maxn==a[i][2]){
				col=2;
				club[2].push_back(xc[i]);
				clubsize[2]++;
			}else{
				col=3;
				club[3].push_back(xc[i]);
				clubsize[3]++;
			}			
		}
		for(int i=1;i<=3;i++)
			if(clubsize[i]>(n/2))
				solve(i);
		cout<<cnt()<<"\n";
	}
	return 0;
}
