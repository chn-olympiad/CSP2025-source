#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int cnta,cntb,cntc;
ll ans;
int vis[20010];
struct N{
	int mx,mid;
}bb[100010],aa[100010],cc[100010];
bool cmp(N ovo,N owo){
	return ovo.mx-ovo.mid>owo.mx-owo.mid;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int oa,ob,oc,omx,omi,omid;
			cin>>oa>>ob>>oc;
			omx=max(oa,max(ob,oc));
			ans+=omx;
			omi=min(oa,min(ob,oc));
			if(oa!=omx&&oa!=omi){
				omid=oa;
			}else if(ob!=omx&&ob!=omi){
				omid=ob;
			}else if(oc!=omx&&oc!=omi){
				omid=oc;
			}else{
				vis[oa]++;vis[ob]--;vis[oc]++;
				if(vis[oa]>=2){
					omid=oa;
				}else{
					omid=ob;
				}
				vis[oa]--;vis[ob]--;vis[oc]--;
			}
			if(oa==omx){
				aa[++cnta].mid=omid;aa[cnta].mx=omx;
			}else if(ob==omx){
				bb[++cntb].mid=omid;bb[cntb].mx=omx;
			}else{
				cc[++cntc].mid=omid;cc[cntc].mx=omx;
			}
		}
		if(cnta>n/2){
			sort(aa+1,aa+cnta+1,cmp);
			for(int i=n/2+1;i<=cnta;i++){
				ans+=aa[i].mid;ans-=aa[i].mx;
			}
		}else if(cntb>n/2){
			sort(bb+1,bb+cntb+1,cmp);
			for(int i=n/2+1;i<=cntb;i++){
				ans+=bb[i].mid;ans-=bb[i].mx;
			}
		}else if(cntc>n/2){
			sort(cc+1,cc+cntc+1,cmp);
			for(int i=n/2+1;i<=cntc;i++){
				ans+=cc[i].mid;ans-=cc[i].mx;
			}
		}
		cout<<ans<<"\n";
		ans=0;cnta=0;cntb=0;cntc=0;
	}
	return 0;
}
//етЬт
//1000+
