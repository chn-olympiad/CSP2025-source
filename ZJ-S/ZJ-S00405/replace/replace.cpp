#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+100;
int n,q,ans[N],ff;
string x,y,sx,sy;
struct node {
	string fi,se,qq,p;
	int id;
}s[N],b[N];
bool cmp(node x,node y){
	if (x.fi!=y.fi) return x.fi<y.fi;
		else return x.se<=y.se;
}
bool cmp1(node x,node y){
	return x.id<y.id;
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	cin>>n>>q;
	int u=0;
	for (int i=1;i<=n;i++){
		cin>>x>>y;
		int l=0,len=x.size();
		while (x[l]==y[l]&&l<x.size()) l++;
		if (l==x.size()) continue;
		int r=x.size()-1;
		while (x[r]==y[r]) r--;
		u++;
		s[u].qq=x;
		s[u].p=y;
		for (int j=l;j<=r;j++) s[u].fi+=x[j],s[u].se+=y[j];
//		cout<<s[i].fi<<' '<<s[i].se<<endl;
	}
	n=u;
//	cout<<n<<endl;
	sort(s+1,s+1+n,cmp);
////	for (int i=1;i<=n;i++) cout<<s[i].fi<<' '<<s[i].se<<endl;
//	for (int i=1;i<=q;i++){
//		cin>>sx>>sy;
////		if (i==1) cout<<sx<<' '<<sy<<endl;
//		if (sx.size()!=sy.size()) {
//			b[i].fi=char ('z'+1)+char('z'+1);
//			b[i].se=char ('z'+1);
//			ans[i]=0;
//			continue;
//		}
//		int len=sx.size();
//		int l=0;
//		while (sx[l]==sy[l]) l++;
//		int r=len-1;
//		while (sx[r]==sy[r]) r--;
//		for (int j=l;j<=r;j++) b[i].fi+=sx[j],b[i].se+=sy[j];
//		b[i].qq=sx,b[i].p=sy;
////		cout<<b[i].fi<<' '<<b[i].se<<endl;
//		b[i].id=i;
//	}
////	cout<<b[1].fi<<' '<<b[1].se;
//	sort(b+1,b+1+q,cmp);
//	int l=1;
//	for (int i=1;i<=q;i++){
//		if (b[i].fi.size()!=b[i].se.size()) continue;
////		if (s[l])
////		cout<<l<<endl;
//		while ((s[l].fi<b[i].fi||s[l].fi==b[i].fi&&s[l].se<b[i].se)&&l<=n) l++;
////		cout<<s[l].fi<<' '<<b[i].fi<<' '<<s[l].se<<' '<<b[i].se<<endl;
////		if (l>n-1) return 0;
//		ff=l;
//		while (s[l].fi==b[i].fi&&s[l].se==b[i].se){
//			l++;
//			if (s[l].qq.size()<=b[i].qq.size()) ans[b[i].id]++;
//		} 
//		l=ff;
////		if (b[i].fi==b[i-1].fi&&b[i].se==b[i-1].se) ans[b[i].id]=ans[b[i-1].id];
//	}
//	sort(b+1,b+1+q,cmp1);
//	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
	for (int i=1;i<=q;i++){
		string tx="",ty="";
		int ls=0;
		cin>>sx>>sy;
		if (sx.size()!=sy.size()) {
			continue;
		}
		int len=sx.size();
		int l=0;
		while (sx[l]==sy[l]) l++;
		int r=len-1;
		while (sx[r]==sy[r]) r--;
		for (int j=l;j<=r;j++) tx+=sx[j],ty+=sy[j];
		for (int j=1;j<=n;j++){
			if (tx==s[j].fi&&ty==s[j].se&&s[j].fi.size()<=tx.size()) ls++;
		}
		cout<<ls<<endl;
	}
}
