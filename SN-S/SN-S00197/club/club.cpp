//CSP-S
//SN-S00197
//张之奇
//西安市铁一中学 

#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
struct ST{
	long long id,num,tid;
	friend bool operator < (const ST &x,const ST &y){
		return x.num>y.num;
	}
};
int n;
long long a[maxn][5];
priority_queue<ST> Q[4];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		long long ans=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][1]>=a[i][2]&&a[i][2]>=a[i][3])	Q[1].push({i,a[i][1]-a[i][2],2}),ans+=a[i][1];
			else if (a[i][1]>=a[i][3]&&a[i][3]>=a[i][2])	Q[1].push({i,a[i][1]-a[i][3],3}),ans+=a[i][1];
			else if (a[i][2]>=a[i][1]&&a[i][1]>=a[i][3])	Q[2].push({i,a[i][2]-a[i][1],1}),ans+=a[i][2];
			else if (a[i][2]>=a[i][3]&&a[i][3]>=a[i][1])	Q[2].push({i,a[i][2]-a[i][3],3}),ans+=a[i][2];
			else if (a[i][3]>=a[i][1]&&a[i][1]>=a[i][2])	Q[3].push({i,a[i][3]-a[i][1],1}),ans+=a[i][3];
			else	Q[3].push({i,a[i][3]-a[i][2],2}),ans+=a[i][3];
		}
		while ((int)Q[1].size()>n/2){
			ST t=Q[1].top();Q[1].pop();
			ans-=t.num;
		}
		while ((int)Q[2].size()>n/2){
			ST t=Q[2].top();Q[2].pop();
			ans-=t.num;
		}
		while ((int)Q[3].size()>n/2){
			ST t=Q[3].top();Q[3].pop();
			ans-=t.num;
		}
		cout<<ans<<"\n";
		for (int i=1;i<=3;i++){
			while ((int)Q[i].size()>0)	Q[i].pop();
		}
	}
	return 0;
}
