#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int base=1e9+7;
int n,q;
string a[N],b[N];
int m[N];
int ap[N][2];
string u,v;
namespace SUBB{
	struct Subb{
		int p,pre,nxt;
		bool operator <(const Subb& o)const{
			return p<o.p;
		}
	}t[N];
	int find(int x,int y,int v){
		while(x<y){
			int mid=x+y>>1;
			if(t[mid].p<v)	x=mid+1;
			else	y=mid;
		}
		return x;
	}
	void SUB(){
		for(int i=1;i<=n;i++){
			t[i].p=ap[i][1]-ap[i][0];
			if(ap[i][0]>ap[i][1])	swap(ap[i][0],ap[i][1]);
			t[i].pre=ap[i][0];
			t[i].nxt=m[i]-ap[i][1];
		}
		sort(t+1,t+1+n);
		while(q--){
			cin>>u>>v;
			int len=u.size(),l,r,ans=0;
			for(int j=0;j<len;j++){
				if(u[j]=='b')
					l=j;
				if(v[j]=='b')
					r=j;
			}
			int v=r-l;
			if(l>r)	swap(l,r);
			int p=find(1,n,v);
//			cout<<l<<' '<<r<<' '<<p<<'\n';
			while(v==t[p].p){
//				cout<<p<<' '<<t[p].pre<<' '<<t[p].nxt<<'\n';
				if(t[p].pre<=l&&t[p].nxt<=len-r)
					ans++;
				p++;
			}
			cout<<ans<<'\n';
		}
		return;
	}
}
bool check(int id,int l,int r){
	for(int i=0;i+r-l<m[id];i++){
		for(int j=i;j<=r-l+i;j++){
			if(a[id][j]!=u[l+j-i])	break;
			if(b[id][j]!=v[l+j-i])	break;
			if(j==r-l+i){
				int F=0;
				for(int k=i-1;k>=0;k--)
					if(a[id][k]!=u[l+k-i]){
						F=1;
						break;
					}
				if(F)	break;
				F=0;
				for(int k=i-1;k>=0;k--)
					if(b[id][k]!=v[l+k-i]){
						F=1;
						break;
					}
				if(F)	break;
				return 1;
			}
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bool FB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m[i]=a[i].size();
		for(int j=0;j<m[i];j++){
			if(!(a[i][j]=='a'||a[i][j]=='b')&&!(b[i][j]=='a'||b[i][j]=='b'))
				FB=0;
			if(a[i][j]=='b')
				ap[i][0]=j;
			if(b[i][j]=='b')
				ap[i][1]=j;
		}
	}
	if(FB){
		SUBB::SUB();
		return 0;
	}
	while(q--){
		int ans=0;
		cin>>u>>v;
		int len=u.size(),l=-1,r=-1;
		for(int i=0;i<len;i++){
			if(u[i]!=v[i]&&l==-1)	l=i;
			if(u[i]!=v[i]&&l>-1)	r=i;
		}
		for(int i=1;i<=n;i++)
			ans+=check(i,l,r);
		cout<<ans<<'\n';
	}
	return 0;
}
