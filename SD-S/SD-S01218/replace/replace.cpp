#include<bits/stdc++.h>
#include<string>
#define M 998244353
#define P 1000000007
using namespace std;
int n,q;
string a[200005],b[200005];
int st[200005],fi[200005];
long long hq[200005],ha[200005],hb[200005],hh[200005];
long long hc[5000005],hd[5000005];
long long bas[5000005];
int hashc(int l,int r){
	return (hc[r]+P-hc[l-1]*bas[r-l+1]%P)%P;
}
int hashd(int l,int r){
	return (hd[r]+P-hd[l-1]*bas[r-l+1]%P)%P;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	bas[0]=1;
	for(int i=1;i<=5000005;i++)bas[i]=(bas[i-1]*M)%P;
//	for(int i=1;i<=10;i++)cout<<bas[i]<<' ';cout<<'\n';
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]==b[i])continue;
		int bg=-1,ed=-1;
		for(int j=0;j<a[i].size();j++){
			if(bg==-1 and a[i][j]!=b[i][j]){
				bg=j;break;
			}
		}
		for(int j=a[i].size()-1;j>=0;j--){
			if(ed==-1 and a[i][j]!=b[i][j]){
				ed=j;break;
			}
		}ed++;
		st[i]=bg;fi[i]=ed;
//		cout<<st[i]<<'\t'<<fi[i]<<'\n';
		for(int j=0;j<bg;j++){
			hq[i]=hq[i]*M+a[i][j]-'a';
			hq[i]%=P;
		}
		for(int j=bg;j<ed;j++){
			ha[i]=ha[i]*M+a[i][j]-'a';ha[i]%=P;
			hb[i]=hb[i]*M+b[i][j]-'a';hb[i]%=P;
		}
		for(int j=ed;j<a[i].size();j++){
			hh[i]=hh[i]*M+a[i][j]-'a';
		}
	}
	while(q--){
		long long ans=0;
		string c,d;
		cin>>c>>d;
		int bg=-1,ed=-1;
		for(int i=0;i<c.size();i++){
			if(c[i]!=d[i]){
				bg=i;
				break;
			}
		}
		for(int i=c.size()-1;i>=0;i--){
			if(c[i]!=d[i]){
				ed=i+1;
				break;
			}
		}
		hc[0]=c[0]-'a';hd[0]=d[0]-'a';
		for(int i=1;i<c.size();i++){
			hc[i]=hd[i]=0;
			hc[i]=hc[i-1]*M%P+c[i]-'a';hc[i]%=P;
			hd[i]=hd[i-1]*M%P+d[i]-'a';hd[i]%=P;
		}
//		for(int i=1;i<c.size();i++){
//			cout<<hc[i]<<"\t\t"<<hd[i]<<'\n';
//		}
		for(int i=1;i<=n;i++){
//			cout<<bg<<' '<<ed<<'\t'<<hh[i]<<' '<<ed<<' '<<bg-st[i]+(fi[i]-st[i])+1+1<<' '<<bg-st[i]+a[i].size()-1<<'\n';
			if(bg-st[i]>bg-1 or ed>bg-st[i]+a[i].size()-1)continue;
			if(hashc(bg,ed-1)!=ha[i] or hashd(bg,ed-1)!=hb[i]){
//				cout<<1<<'\n';
				continue;
			}
			if(hashc(bg-st[i],bg-1)!=hq[i] \
			or hashc(ed,bg-st[i]+a[i].size()-1)!=hh[i]){
//				cout<<2<<'\n';
				continue;
			}
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
