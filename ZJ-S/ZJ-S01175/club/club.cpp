#include<bits/stdc++.h>
using namespace std;
int cnta,cntb,cntc,ans,ida[100005],idb[100005],idc[100005];
struct fff{
	int a,b,c,x;
}s[100005];
bool cmp(int z,int y){
	return s[z].x<s[y].x;
}
void solve(){
	int n;
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[i].a>s[i].b){
			s[i].x=abs(s[i].a-max(s[i].c,s[i].b));
			if(s[i].a>s[i].c){
				
				ida[++cnta]=i;
				ans+=s[i].a;
			}else{
				idc[++cntc]=i;
				ans+=s[i].c;
			}
		}else{
			s[i].x=abs(s[i].b-max(s[i].c,s[i].a));
			if(s[i].b>s[i].c){
				idb[++cntb]=i;
				ans+=s[i].b;
			}else{
				idc[++cntc]=i;
				ans+=s[i].c;
			}
		}
	}
	if(cnta>n/2){
		sort(ida+1,ida+cnta+1,cmp);
		for(int i=1;i<=cnta-n/2;i++)ans-=s[ida[i]].x;
	}
	if(cntb>n/2){
		sort(idb+1,idb+cntb+1,cmp);
		for(int i=1;i<=cntb-n/2;i++)ans-=s[idb[i]].x;
	}
	if(cntc>n/2){
		sort(idc+1,idc+cntc+1,cmp);
		for(int i=1;i<=cntc-n/2;i++)ans-=s[idc[i]].x;
	}
	cout<<ans<<"\n";
	memset(ida,0,sizeof(ida));
	memset(idb,0,sizeof(idb));
	memset(idc,0,sizeof(idc));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
