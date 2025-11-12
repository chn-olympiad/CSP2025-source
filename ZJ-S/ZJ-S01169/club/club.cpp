#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n=0,used[N+10],usenum,
      ai,bi,ci,havea,haveb,havec
      ,ans,hav[N+10],hbv[N+10],hcv[N+10],
      aa[N+10],bb[N+10],cc[N+10];
struct poin {
	int v,id;
} a[N+10],b[N+10],c[N+10];
bool cmp(poin x,poin y) {
	return x.v>y.v;
}
poin pub() {
	poin qq;
	qq.v=qq.id=-1;
	if(used[b[bi].id])return qq;
	if(haveb<n/2) {
		hbv[haveb++]=b[bi].id;
		//	cout<<"pub"<<b[bi].id<<"\n";
		ans+=b[bi].v;
		//	cout<<"ans="<<ans<<"\n";
		usenum++;
		used[b[bi].id]=1;
	} else {
		int bbig=min(abs(aa[b[bi].id]-bb[b[bi].id]),abs(bb[b[bi].id]-cc[b[bi].id])),
		    bbk=b[bi].id;
		int howd=bbig==abs(aa[b[bi].id]-bb[b[bi].id])?2:1;
		for(int i=0; i<haveb; i++) {
			int p=aa[hbv[i]],q=bb[hbv[i]],k=cc[hbv[i]];
			if(abs(p-q)<bbig)bbk=i,bbig=abs(p-q),howd=2;
			if(abs(k-q)<bbig)bbk=i,bbig=abs(k-q),howd=1;
		}
		if(bbk!=b[bi].id) {
			if(bbig<b[bi].v) {
				int u=b[bbk].id;
				used[u]=0;
				ans-=b[bbk].v;
//				cout<<"BBig="<<bbig<<"---"<<b[bi].v;
//				cout<<"pubout"<<b[bbk].id<<"\n";
//				cout<<"ans="<<ans<<"\n";
				usenum--;
				b[bbk]=b[haveb--];
				pub();
				qq.v=u;
				qq.id=howd;
			}

		}
	}
	bi++;
	return qq;
}
poin puc() {
	poin qq;
	qq.v=qq.id=-1;
	if(used[c[ci].id])return qq;
	if(havec<n/2) {
		hcv[havec++]=c[ci].id;
		//	cout<<"puc"<<c[ci].id<<"\n";
		ans+=c[ci].v;
		//	cout<<"ans="<<ans<<"\n";
		usenum++;
		used[c[ci].id]=1;
	} else {
		int bbig=min(abs(aa[c[ci].id]-cc[c[ci].id]),abs(bb[c[ci].id]-cc[c[ci].id])),
		    bbk=c[ci].id;
		int howd=bbig==abs(aa[c[ci].id]-cc[c[ci].id])?2:0;
		for(int i=0; i<havec; i++) {
			int p=aa[hcv[i]],q=bb[hcv[i]],k=cc[hcv[i]];
			if(abs(p-k)<bbig)bbk=i,bbig=abs(p-k),howd=2;
			if(abs(k-q)<bbig)bbk=i,bbig=abs(k-q),howd=0;
		}
		if(bbk!=c[ci].id) {
			if(bbig<c[ci].v) {
				int u=c[bbk].id;
				used[u]=0;
				ans-=c[bbk].v;
				//		cout<<"pucout"<<c[bbk].id<<"\n";
				//	cout<<"ans="<<ans<<"\n";
				usenum--;
				c[bbk]=c[havec--];
				puc();
				qq.v=u;
				qq.id=howd;
			}

		}
	}
	ci++;
	return qq;
}
poin pua() {
	poin qq;
	qq.v=qq.id=-1;
	if(used[a[ai].id]==1)return qq;
	if(havea<n/2) {
		hav[havea++]=a[ai].id;
		//	cout<<"pua"<<a[ai].id<<"\n";
		ans+=a[ai].v;
//		cout<<"ans="<<ans<<"\n";
		usenum++;
		used[a[ai].id]=1;
	} else {
		int bbig=min(abs(aa[a[ai].id]-bb[a[ai].id]),abs(aa[a[ai].id]-cc[a[ai].id])),
		    bbk=a[ai].id;
		int howd=bbig==abs(aa[a[ai].id]-bb[a[ai].id])?0:1;
		for(int i=0; i<havea; i++) {
			int p=aa[hav[i]],q=bb[hav[i]],k=cc[hav[i]];
			if(abs(p-q)<bbig)bbk=i,bbig=abs(p-q),howd=0;
			if(abs(p-k)<bbig)bbk=i,bbig=abs(p-k),howd=1;
		}
		if(bbk!=a[ai].id) {
			if(bbig<a[ai].v) {
				int u=a[bbk].id;
				used[u]=0;
				ans-=a[bbk].v;
//				cout<<"puaout"<<a[bbk].id<<"\n";
//				cout<<"ans="<<ans<<"\n";
				usenum--;
				a[bbk]=a[havea--];
				pua();
				qq.v=u;
				qq.id=howd;
			}

		}
	}
	ai++;
	return qq;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>a[i].v>>b[i].v>>c[i].v;
			aa[i]=a[i].v;
			bb[i]=b[i].v;
			cc[i]=c[i].v;
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		while(usenum<n) {
			while(ai<n&&used[a[ai].id])ai++;
			while(bi<n&&used[b[bi].id])bi++;
			while(ci<n&&used[c[ci].id])ci++;
			int x=a[ai].v,y=b[bi].v,z=c[ci].v;
			if(x==y) {
				if(x>=z) {
					poin gat=pua();
					if(gat.v!=-1) {
						if(gat.id==0) {
							bi=gat.v;
							pub();
						} else {
							ci=gat.v;
							puc();
						}
					}

					gat=pub();
					if(gat.v!=-1) {
						if(gat.id==2) {
							ai=gat.v;
							pua();
						} else {
							ci=gat.v;
							puc();
						}
					}
				}
				if(x==z||x<z) {
					poin gat=puc();
					if(gat.v!=-1) {
						if(gat.id==0) {
							bi=gat.v;
							pub();
						} else {
							ai=gat.v;
							pua();
						}
					}
				}
			} else if(x==z) {
				if(x>=y) {
					poin gat=pua();
					if(gat.v!=-1) {
						if(gat.id==0) {
							bi=gat.v;
							pub();
						} else {
							ci=gat.v;
							puc();
						}
					}
					gat=puc();
					if(gat.v!=-1) {
						if(gat.id==0) {
							bi=gat.v;
							pub();
						} else {
							ai=gat.v;
							pua();
						}
					}
				} else {
					poin gat=pub();
					if(gat.v!=-1) {
						if(gat.id==2) {
							ai=gat.v;
							pua();
						} else {
							ci=gat.v;
							puc();
						}
					}
				}
			} else if(y==z) {
				if(x<y) {
					poin gat=pub();
					if(gat.v!=-1) {
						if(gat.id==2) {
							ai=gat.v;
							pua();
						} else {
							ci=gat.v;
							puc();
						}
					}
					gat=puc();
					if(gat.v!=-1) {
						if(gat.id==0) {
							bi=gat.v;
							pub();
						} else {
							ai=gat.v;
							pua();
						}
					}
				} else {
					poin gat=pua();
					if(gat.v!=-1) {
						if(gat.id==0) {
							bi=gat.v;
							pub();
						} else {
							ci=gat.v;
							puc();
						}
					}
				}
			} else if(x>y&&x>z) {
				poin gat=pua();
				if(gat.v!=-1) {
					if(gat.id==0) {
						bi=gat.v;
						pub();
					} else {
						ci=gat.v;
						puc();
					}
				}
			} else if(y>z&&y>x) {
				poin gat=pub();
				if(gat.v!=-1) {
					if(gat.id==2) {
						ai=gat.v;
						pua();
					} else {
						ci=gat.v;
						puc();
					}
				}
			} else {
				poin gat=puc();
				if(gat.v!=-1) {
					if(gat.id==0) {
						bi=gat.v;
						pub();
					} else {
						ai=gat.v;
						pua();
					}
				}
			}
		}
		cout<<ans<<"\n";
		for(int i=0; i<n; i++) {
			a[i].v=b[i].v=c[i].v=aa[i]=bb[i]=cc[i]=used[i]=0;
			a[i].id=b[i].id=c[i].id=i;
		}
		ans=usenum=ai=bi=ci=havea=haveb=havec=0;
	}
	return 0;
}
