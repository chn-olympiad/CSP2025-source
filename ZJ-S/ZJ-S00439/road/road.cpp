#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int xn=1e4+5,xd=1e6+5,xk=15;int s,d,f,o,i,fa[xn+xk],b[xk];bool us[xk];LL ans;
const LL nf=1e18;
struct op{
	int x,y,z;
	op(const int&aa=0,const int&bb=0,const int&cc=0):x(aa),y(bb),z(cc){}
	bool operator<(const op&aa)const{return z<aa.z;}
}a[xd],l[xn*xk];
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
int fi(int x){if(fa[x]==x)return x;return fa[x]=fi(fa[x]);}
void dfs(int x){
	if(x>f){
		LL kk=0;for(int g=1;g<=f;g++)if(us[g])kk+=b[g];for(int g=1;g<=s+f;g++)fa[g]=g;
		for(int g=1;g<=o;g++)if(l[g].y<=s||us[l[g].y-s]){
			int e=fi(l[g].x),r=fi(l[g].y);if(e!=r)fa[e]=r,kk+=l[g].z;
		}
		ans=min(ans,kk);return;
	}
	us[x]=1,dfs(x+1),us[x]=0,dfs(x+1);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(s),read(d),read(f);for(int g=1;g<=d;g++)read(a[g].x),read(a[g].y),read(a[g].z);
	sort(a+1,a+1+d);for(int g=1;g<=s;g++)fa[g]=g;
	for(int g=1;g<=d;g++){int e=fi(a[g].x),r=fi(a[g].y);if(e!=r)fa[e]=r,l[++o]=a[g];}
	for(int g=1;g<=f;g++){read(b[g]);for(int h=1;h<=s;h++)read(i),l[++o]=op(h,g+s,i);}
	sort(l+1,l+1+o),ans=nf,dfs(1),cout<<ans;
	return 0;
}
