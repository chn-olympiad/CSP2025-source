#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
map <string,string> m;
struct cvb{
	int fir,sec,lef,rig,id;
} a[N],b[N];
bool xcv(cvb u,cvb v){
	if(u.fir==v.fir && u.sec==v.sec && u.lef==v.lef)
		return u.rig<v.rig;
	else if(u.fir==v.fir && u.sec==v.sec) return u.lef<v.lef;
	else if(u.fir==v.fir) return u.sec<v.sec;
	else return u.fir<v.fir;
}
int n,q,sum,le,ri,fro,beh,l,r,zx,zd;
string s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		a[i].fir=s1.find('b')-s2.find('b');
		a[i].sec=s1.size()-s1.find('b')-s2.size()+s2.find('b');
		a[i].lef=s1.find('b');a[i].rig=s1.size()-s1.find('b')-1;
	}
	sort(a+1,a+1+n,xcv);
	sum=1;
	while(q--){
		cin>>s1>>s2;
		fro=s1.find('b')-s2.find('b');
		beh=s1.size()-s1.find('b')-s2.size()+s2.find('b');
		le=s1.find('b');ri=s1.size()-s1.find('b')-1;
		l=0,r=n,zx=n+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].fir==fro) zx=min(zx,mid);
			if(a[mid].fir<=fro) r=mid-1;
			else l=mid+1;
		}
		l=zx-1,r=n,zd=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].fir==fro) zd=max(zd,mid);
			if(a[mid].fir<fro) r=mid-1;
			else l=mid+1;
		}
		l=zx-1,r=zd+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].sec==beh) zx=min(zd,mid);
			if(a[mid].sec<=beh) r=mid-1;
			else l=mid+1;
		}
		l=zx-1,r=zd+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].sec==beh) zd=max(zd,mid);
			if(a[mid].sec<beh) r=mid-1;
			else l=mid+1;
		}
		l=zx-1,r=zd+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].lef<=le) zx=min(zx,mid),r=mid-1;
			else l=mid+1;
		}
		l=zx-1,r=zd+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].lef<=le) zd=max(zd,mid),l=mid+1;
			else r=mid-1;
		}
		l=zx-1,r=zd+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].rig<=ri) zx=min(zx,mid),r=mid-1;
			else l=mid+1;
		}
		l=zx-1,r=zd+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid].rig<=ri) zd=max(zd,mid),l=mid+1;
			else r=mid-1;
		}
		cout<<zd-zx+1<<endl;
	}
	return 0;
}
