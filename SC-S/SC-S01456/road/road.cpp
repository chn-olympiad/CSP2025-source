#include<bits/stdc++.h>
using namespace std;

int n,m,k,x,y,z,cnt;
long long ans;

int head[15000],c[20][15000],s[20],f[1500];
bool is[15000];

struct bbb{
	int l,r,v,last;
}a[3000000];

void read( int &xx ){
	xx=0;
	char ch=getchar();
	while( ch<'0' or ch>'9' ) ch=getchar() ;
	while( ch>='0' and ch<='9' ){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
}

bool cmp( bbb xx,bbb yy ){
	return xx.v<yy.v;
}

int find( int xx ){
	if( f[xx]==xx ) return xx;
	return f[xx]=find( f[xx] );
}

void klu(){
	for( int i=1; i<=n; ++i ){
		f[i]=i;
	}
	for( int i=1; i<=k; ++i ){
		if( !s[i] ){
			for( int j=1; j<=n; ++j ){
				is[j]=0;
			}
			for( int j=head[i]; j; j=a[j].last ){
				a[j].v=c[i][a[j].r];
				is[a[j].r]=1;
			}
			for( int j=1; j<=n; ++j ){
				if( !is[j] ){
					a[++cnt].l=i;
					a[cnt].r=j;
					a[cnt].v=c[i][j];
					a[cnt].last=head[i];
					head[i]=cnt;
					
					a[++cnt].l=j;
					a[cnt].r=i;
					a[cnt].v=c[i][j];
					a[cnt].last=head[j];
					head[j]=cnt;
				}
			}
		}
	}
	sort( a+1,a+cnt+1,cmp );
	int xx,yy,cn=0;
	for( int i=1; i<=cnt; ++i ){
		xx=a[i].l;
		yy=a[i].r;
		if( find(xx)!=find(yy) ){
			ans+=a[i].v;
			f[find(yy)]=find(xx);
			if( ++cn>=n-1 ) break;
		}
	}
	cout<<ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for( int i=1; i<=m; ++i ){
		read(x);
		read(y);
		read(z);
		a[++cnt].l=x;
		a[cnt].r=y;
		a[cnt].v=z;
		a[cnt].last=head[x];
		head[x]=cnt;
					
		a[++cnt].l=y;
		a[cnt].r=x;
		a[cnt].v=z;
		a[cnt].last=head[y];
		head[y]=cnt;
	}
	for( int i=1; i<=k; ++i ){
		read(s[i]);
		for( int j=1; j<=n; ++j ){
			read(c[i][j]);
		}
	}
	klu();
	fclose(stdin);
	fclose(stdout);
	return 0;
}