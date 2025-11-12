#include<bits/stdc++.h>
using namespace std;
int t,n;
struct g {
	int a,b,c;
};
g m[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		int sa=0,sb=0,sc=0,maxa=0,ma=0,mb=0,mc=0;
		int mina=INT_MAX,minb=INT_MAX,minc=INT_MAX;
		int ja=0,jb=0,jc=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c) {
				sa+=m[i].a;
				ma++;
				if(mina>m[i].a) {
					mina=m[i].a;
					ja=i;
				}
				if(ma>n/2) {
					sa-=mina;
					ma--;
					if(m[ja].b>=m[ja].c) {
						mb+=m[ja].b;
						if(minb>m[i].b) {
							minb=m[i].b;
							jb=i;
						}
					}else{
						mc+=m[ja].c;
						if(minc>m[i].c) {
							minc=m[i].c;
							jc=i;
						}
					}
				}
			}
			if(m[i].b>=m[i].a&&m[i].b>=m[i].c) {
				sb+=m[i].b;
				mb++;
				if(minb>m[i].b) {
					minb=m[i].b;
					jb=i;
				}
				if(mb>n/2) {
					sb-=minb;
					mb--;
					if(m[jb].a>=m[jb].c) {
						ma+=m[jb].a;
						if(mina>m[i].a) {
							mina=m[i].a;
							ja=i;
						}
					}else{
						mc+=m[jb].c;
						if(minc>m[i].c) {
							minc=m[i].c;
							jc=i;
						}
					}
				}
			}
			if(m[i].c>=m[i].a&&m[i].c>=m[i].b) {
				sc+=m[i].c;
				mc++;
				if(minc>m[i].c) {
					minc=m[i].c;
					jc=i;
				}
				if(mc>n/2) {
					sc-=minc;
					mc--;
					if(m[jc].a>=m[jc].c) {
						ma+=m[jc].a;
						if(mina>m[i].a) {
							mina=m[i].a;
							ja=i;
						}
					}else{
						mc+=m[jc].c;
						if(minc>m[i].c) {
							minc=m[i].c;
							jc=i;
						}
					}
				}
			}
		}
		cout<<sa+sb+sc<<endl; 
	}
	
	return 0;
}
