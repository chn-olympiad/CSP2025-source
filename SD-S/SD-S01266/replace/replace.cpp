#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string u[N][2];
struct pp{
	int l1,l2,l3,l4;
}v[N];
int f(string s1,string s2,string s3,string s4,int l,int r){
	int p=0,q=0;
	q=s4.find(s2,q);
	for(;;){
		p=s3.find(s1,p);
		if (p==string::npos||p>l) break;
		while (p>q&&q!=string::npos) q=s4.find(s2,q+1);
		if (p==q&&p+s1.length()>r) return 1;
		p++;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool p2=1;
	for (int i=1;i<=n;++i){
		cin>>u[i][0]>>u[i][1];
		for (int j=0;j<u[i][0].length();++j) if (u[i][0][j]!='a'&&u[i][0][j]!='b') p2=0;
 	}
	string a,b;
	if (p2){
		for (int i=1;i<=n;++i){
			int j=0;
			while (u[i][0][j]!='b') j++;
			v[i].l1=j;
			v[i].l2=u[i][0].length()-j-1;
			j=0;
			while (u[i][1][j]!='b') j++;
			v[i].l3=j;
			v[i].l4=u[i][1].length()-j-1;
		}
		while (q--){
			int ans=0;
			cin>>a>>b;
			if (a.length()!=b.length()) {
				printf("%d\n",0);
				continue;
			}
			pp r;
			int j=0;
			while (a[j]!='b') j++;
			r.l1=j;
			r.l2=a.length()-j-1;
			j=0;
			while (b[j]!='b') j++;
			r.l3=j;
			r.l4=b.length()-j-1;
			for (int i=1;i<=n;++i){
				int l1=v[i].l1,l2=v[i].l2,l3=v[i].l3,l4=v[i].l4;
				
				if (r.l1>=l1&&r.l2>=l2&&r.l1-l1+l3==r.l3) ans++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	while (q--){
		int ans=0;
		cin>>a>>b;
		if (a.length()!=b.length()) {
			printf("%d\n",0);
			continue;
		}
		int l=0,r=0;
		while (a[l]==b[l]) l++;
		r=a.length()-1;
		while (a[r]==b[r]) r--;
		for (int i=1;i<=n;++i)
		ans+=f(u[i][0],u[i][1],a,b,l,r);
		printf("%d\n",ans);
	}
	return 0;
}

