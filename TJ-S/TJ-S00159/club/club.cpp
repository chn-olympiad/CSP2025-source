#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,t;
LL a,b,c;
LL x,y,z;
struct node {
	LL a,b,c;
	bool x,y,z;
} m[100001];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(m,0,sizeof(m));
		cin>>n;
		for(LL i=1; i<=n; i++) {
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].x=m[i].y=m[i].z=false;
			if(m[i].a>m[i].b&&m[i].a>m[i].c) {
				a+=m[i].a;
				m[i].x=true;
				x++;
			} else if(m[i].b>m[i].a&&m[i].b>m[i].c) {
				b+=m[i].b;
				m[i].y=true;
				y++;
			} else {
				c+=m[i].c;
				m[i].z=true;
				z++;
			}
		}
		if(x>n/2) {
			for(LL i=1; i<=n; i++) {
				if(m[i].x) {
					if((m[i].b>m[i].c&&y+1<=n/2)||z+1>n/2) {
						y++;
						b+=m[i].b;
						a-=m[i].a;
						x--;
					} else {
						z++;
						c+=m[i].c;
						a-=m[i].a;
						x--;
					}
					if(x<=n/2) {
						break;
					}
				}
			}
		}
		if(y>n/2) {
			for(LL i=1; i<=n; i++) {
				if(m[i].y) {
					if((m[i].a>m[i].c&&x+1<=n/2)||z+1>n/2) {
						x++;
						a+=m[i].a;
						b-=m[i].b;
						y--;
					} else {
						z++;
						c+=m[i].c;
						b-=m[i].b;
						y--;
					}
					if(y<=n/2) {
						break;
					}
				}
			}
		}
		if(z>n/2) {
			for(LL i=1; i<=n; i++) {
				if(m[i].z) {
					if((m[i].b>m[i].a&&y+1<=n/2)||x+1>n/2) {
						y++;
						b+=m[i].b;
						c-=m[i].c;
						z--;
					} else {
						x++;
						a+=m[i].a;
						c-=m[i].c;
						z--;
					}
					if(z<=n/2) {
						break;
					}
				}
			}
		}
		cout<<a+b+c<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
