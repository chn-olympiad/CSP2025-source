#include<bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void fileIO(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int T,n,a[100010][4],pa[100010],pb[100010],pc[100010],ca,cb,cc;
bool cmpa(int i,int j){
	if (a[i][1]-max(a[i][2],a[i][3])>a[j][1]-max(a[j][2],a[j][3])) return true;
	return false;
}
bool cmpb(int i,int j){
	if (a[i][2]-max(a[i][1],a[i][3])>a[j][2]-max(a[j][1],a[j][3])) return true;
	return false;
}
bool cmpc(int i,int j){
	if (a[i][3]-max(a[i][1],a[i][2])>a[j][3]-max(a[j][1],a[j][2])) return true;
	return false;
}
void solve(){
	ca=cb=cc=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=max(a[i][1],max(a[i][2],a[i][3]));
		if (maxn==a[i][1]) pa[++ca]=i;
		else if (maxn==a[i][2]) pb[++cb]=i;
		else if (maxn==a[i][3]) pc[++cc]=i;
	}
	int maxc=max(ca,max(cb,cc));
	if (maxc==ca){
		sort(pa+1,pa+ca+1,cmpa);
		while (ca>n/2){
			if (a[pa[ca]][2]>a[pa[ca]][3]) pb[++cb]=pa[ca];
			else pc[++cc]=pa[ca];
			ca--;
		}
	}
	else if (maxc==cb){
		sort(pb+1,pb+cb+1,cmpb);
		while (cb>n/2){
			if (a[pb[cb]][1]>a[pb[cb]][3]) pa[++ca]=pb[cb];
			else pc[++cc]=pb[cb];
			cb--;
		}
	}
	else{
		sort(pc+1,pc+cc+1,cmpc);
		while (cc>n/2){
			if (a[pc[cc]][1]>a[pc[cc]][2]) pa[++ca]=pc[cc];
			else pb[++cb]=pc[cc];
			cc--;
		}
	}
	int ans=0;
	for (int i=1;i<=ca;i++) ans+=a[pa[i]][1];
	for (int i=1;i<=cb;i++) ans+=a[pb[i]][2];
	for (int i=1;i<=cc;i++) ans+=a[pc[i]][3];
	cout<<ans<<endl;
}
int main(){
	fileIO();
	fastIO();
	cin>>T;
	while (T--) solve();
	return 0;
}