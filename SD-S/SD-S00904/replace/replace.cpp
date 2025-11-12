#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
unordered_map<string,string> trans;
unordered_map<string,bool> ok;
string x,y;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	if(q==1&&n>100) {
		string a[1005],b[1005];
		int lr[1005]= {0},rr[1005]= {0};
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i];
			int leni=a[i].size();
			while(a[i][lr[i]]==b[i][lr[i]]&&lr[i]<=leni) lr[i]++;
			while(a[i][leni-rr[i]-1]==b[i][leni-rr[i]-1]&&rr[i]<=leni) rr[i]++;
			a[i]=a[i].substr(lr[i],leni-rr[i]-lr[i]);
			b[i]=b[i].substr(lr[i],leni-rr[i]-lr[i]);
			trans[a[i]]=b[i];
		}
		for(int i=1; i<=q; i++) {
			string xx,yy;
			cin>>xx>>yy;
			int llr=0,rrr=0,lenx=xx.size();
			while(xx[llr]==yy[llr]&&llr<=lenx) llr++;
			while(xx[lenx-rrr-1]==yy[lenx-rrr-1]&&rrr<=lenx) rrr++;
			string xxx=xx.substr(llr,lenx-rrr-llr);
			string yyy=yy.substr(llr,lenx-rrr-llr);
			for(int i=1; i<=n; i++) {
				if(xxx==a[i]&&yyy==b[i]) {
					if(lr[i]<=llr&&rr[i]<=rrr) ans++;
				}
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin>>x>>y;
		ok[x]=1;
		trans[x]=y;
	}
	for(int i=1; i<=q; i++) {
		ans=0;
		cin>>x>>y;
		int len=x.size();
		for(int i=1; i<=len; i++) {
			for(int l=0; l+i-1<len; l++) {
				int r=l+i-1;
				string u=x.substr(l,i);
				//cout<<l<<' '<<r<<' '<<u<<'\n';
				if(ok[u]) {
					string nxt="";
					if(l>0) nxt+=x.substr(0,l);
					nxt+=trans[u];
					if(r!=len-1) nxt+=x.substr(r+1,len-r-1);
					//	cout<<l<<' '<<r<<' '<<u<<' '<<nxt<<'\n';
					if(nxt==y) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

