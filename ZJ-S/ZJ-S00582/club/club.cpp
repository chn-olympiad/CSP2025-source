#include<bits/stdc++.h>
#define lon long long
using namespace std;
int t;//5
int n;//1e5
int gs[4];//RE
struct str{
	lon a[4];
	int maxw,mxw;//RE
}s[100010];
lon ans;//RE
bool qwq;//RE
int w,tj;//RE
priority_queue<lon,vector<lon>,greater<lon> > q;//RE
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		gs[1]=gs[2]=gs[3]=0;
		ans=0;
		while(!q.empty()) q.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			s[i].maxw=s[i].mxw=0;
			for(int j=1;j<=3;j++){
				cin>>s[i].a[j];
				if(s[i].a[j]>s[i].a[s[i].mxw]) s[i].mxw=j;
				if(s[i].a[s[i].mxw]>s[i].a[s[i].maxw]) swap(s[i].maxw,s[i].mxw);
			}
			gs[s[i].maxw]++;
			ans+=s[i].a[s[i].maxw];
		}
		qwq=0;
		for(int i=1;i<=3;i++) if(gs[i]>n/2){
			w=i;
			tj=gs[i]-n/2;
			qwq=1;
			break;
		}
		if(!qwq){
			cout<<ans<<'\n';
			continue ;
		}
		for(int i=1;i<=n;i++) if(s[i].maxw==w){
			q.push(s[i].a[s[i].maxw]-s[i].a[s[i].mxw]);
		}
		for(int i=1;i<=tj;i++) ans-=q.top(),q.pop();
		cout<<ans<<'\n';
	}
	return 0;
}
