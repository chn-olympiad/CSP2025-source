#include<bits/stdc++.h>
using namespace std;

int t,n,maxx,d;
long long ans;

int s[8],c[200500];

struct bbb{
	int x,v;
}a[200500][8];

bool cmp( bbb l,bbb r ){
	return l.v>r.v;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while( t-- ){
		scanf("%d",&n);
		ans=0;
		c[0]=0;
		s[1]=0;
		s[2]=0;
		s[3]=0;
		for( int i=1; i<=n; ++i ){
			scanf("%d %d %d",&a[i][1].v,&a[i][2].v,&a[i][3].v);
			a[i][1].x=1;
			a[i][2].x=2;
			a[i][3].x=3;
			sort( a[i]+1,a[i]+4,cmp );
			ans+=a[i][1].v;
			++s[a[i][1].x];
		}
		if( s[1]>=s[2] and s[1]>=s[3] ){
			maxx=s[1];
			d=1;
		}
		else if( s[2]>=s[1] and s[2]>=s[3] ){
			maxx=s[2];
			d=2;
		}
		else{
			maxx=s[3];
			d=3;
		}
		if( maxx>n/2 ){
			for( int i=1; i<=n; ++i ){
				if( a[i][1].x==d ){
					c[++c[0]]=a[i][1].v-a[i][2].v;
				}
			}
			sort( c+1,c+c[0]+1 );
			for( int i=1; i<=maxx-n/2; ++i ){
				ans-=c[i];
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}