#include<bits/stdc++.h>
#define ll long long
#define mn 211111
using namespace std;
int n,q;
struct node {
	int l,r;
	string x,y;
} a[mn];
struct nod {
	int x,l,r;
	vector<node> vs;
};
bool cmp(node xx,node yy) {
	if(xx.x==yy.x) return xx.y<yy.y;
	return xx.x<yy.x;
}
string ss[mn];
map<string,map<string,nod> > mpmp;
int main() {
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
		string s11="",s22="";
		int n1=a[i].x.size(),l=-1,r=n1;
		for(int j=0;j<n1;j++) {
			l++;
			if(a[i].x[j]!=a[i].y[j]) break;
		}
		for(int j=n1-1;j>=0;j--) {
			r--;
			if(a[i].x[j]!=a[i].y[j]) break;
		}
		for(int j=l;j<=r;j++) s11+=a[i].x[j],s22+=a[i].y[j];
		a[i].l=l,a[i].r=r;
		mpmp[s11][s22].x++;
		a[i].x=s11,a[i].y=s22;
	}
	/*for(auto x : mpmp) {
		for(auto xx : mpmp[x.first]) {
			cout<<x.first<<" "<<xx.first<<" "<<xx.second<<endl;
		}
	}*/
	sort(a+1,a+n+1,cmp);
	while(q--) {
		string s1,s2;
		cin>>s1>>s2;
		int n1=s1.size(),n2=s2.size();
		if(n1!=n2) {
			cout<<0<<endl;
			continue;
		}
		string s11="",s22="";
		int l=-1,r=n1;
		for(int j=0;j<n1;j++) {
			l++;
			if(s1[j]!=s2[j]) break;
		}
		for(int j=n1-1;j>=0;j--) {
			r--;
			if(s1[j]!=s2[j]) break;
		}
		for(int j=l;j<=r;j++) s11+=s1[j],s22+=s2[j];
		//cout<<s1<<" "<<s2<<endl;
		l=1,r=n;
		int mid;
		while(l<r-1) {
			mid=(l+r)/2;
			if(s11>=a[mid].x) l=mid;
			else r=mid-1;
		}
		if(a[l].x != s11) {
			cout<<0<<endl;
			continue;
		}
		else cout<<mpmp[s11][s22].x<<endl;
	}		
	fclose(stdin),fclose(stdout);
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/