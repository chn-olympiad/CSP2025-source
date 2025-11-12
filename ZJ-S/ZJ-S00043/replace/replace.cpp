#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	string xa,ya,xb,yb;
	int k,js;
}s[N];
bool cmp(node x,node y){
	return x.xb<y.xb;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].xa>>s[i].ya;
		int bg,en;
		s[i].xb=s[i].yb="";
		if(s[i].xa==s[i].ya){
			continue;
		}
		for(int j=0;j<s[i].xa.size();j++){
			if(s[i].xa[j]!=s[i].ya[j]){
				bg=j;
				break;
			}
		}
		for(int j=s[i].xa.size()-1;j>=0;j--){
			if(s[i].xa[j]!=s[i].ya[j]){
				en=j;
				break;
			}
		}
		for(int j=bg;j<=en;j++){
			s[i].xb+=s[i].xa[j];
			s[i].yb+=s[i].ya[j];
		}
	//	cout<<bg<<" "<<en<<" "<<i<<" "<<s[i].xb<<" "<<s[i].yb<<"--\n";
		s[i].k=bg;
		s[i].js=en;
	}
	sort(s+1,s+n+1,cmp);
	while(q--){
		string sa,sb,saa="",sbb="";
		cin>>sa>>sb;
		if(sa.size()!=sb.size()){
			cout<<"0\n";
			continue;
		}
		int bg,en,ans=0;
		for(int j=0;j<sa.size();j++){
			if(sa[j]!=sb[j]){
				bg=j;
				break;
			}
		}
		for(int j=sa.size()-1;j>=0;j--){
			if(sa[j]!=sb[j]){
				en=j;
				break;
			}
		}
		for(int j=bg;j<=en;j++){
			saa+=sa[j];
			sbb+=sb[j];
		}
		int l=1,r=n,t;
		while(l<=r){
			int mid=(l+r)>>1;
			if(s[mid].xb>=saa){
				r=mid-1;
				t=mid;
			}
			else{
				l=mid+1;
			}
		}
		for(int i=t;i<=n;i++){
			if(s[i].xb!=saa){
				break;
			}
			else if(s[i].yb!=sbb){
				continue;
			}
			int aa=bg,bb=s[i].k;
			bool fl=0;
			while(aa>=0&&bb>=0&&sa[aa]==s[i].xa[bb]){
				if(bb==0){
					fl=1;
					break;
				}
				if(aa==0){
					break;
				}
				aa--;
				bb--;
			}
			if(!fl){
				continue;
			}
			aa=en;
			bb=s[i].js;
			fl=0;
			while(aa<sa.size()&&bb<s[i].xa.size()&&sa[aa]==s[i].xa[bb]){
				if(bb==s[i].xa.size()-1){
					fl=1;
					break;
				}
				if(aa==sa.size()-1){
					break;
				}
				aa++;
				bb++;
			}
			if(fl){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
