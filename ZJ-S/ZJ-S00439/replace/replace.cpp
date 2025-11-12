#include<bits/stdc++.h>
using namespace std;
const int xl=5e6+5,xn=2e5+5,xt=xl+xn;int s,d,a1[xn],b1[xn],a[xl],b[xl],a2[xn],b2[xn],a_[xl],
b_[xl],to[xt][27],c[xl],si,w[xt],m[xn],q[xn],f,l1[xn],l2[xn],_l1[xn],_l2[xn],m1[xn],m2[xn],
o1,o2,fa[xt],af[xt],wi[xt],k[xt],i,l3[xn],l4[xn],is,V[xn*3],ky[xn*12],an[xn];char ch;
struct op{
	int x,y;
	op(const int&aa=0,const int&bb=0):x(aa),y(bb){}
	bool operator<(const op&aa)const{return x<aa.x;}
}u1[xn],u2[xn];
struct po{
	int x,y,z;
	po(const int&aa=0,const int&bb=0,const int&cc=0):x(aa),y(bb),z(cc){}
	bool operator<(const po&aa)const{return x<aa.x||x==aa.x&&z<aa.z;}
}st[xn*3];
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
void dfs(int x){
	k[x]=++i,wi[x]=1;for(int g=0;g<26;g++)if(to[x][g])dfs(to[x][g]),wi[x]+=wi[to[x][g]];
}
int fi(int x){
	int r=1,u=is,mid;while(r<u){mid=r+u>>1;if(V[mid]<x)r=mid+1;else u=mid;}return r;
}
void gai(int x,int y,int z,int o,int i,int p){
	if(o<=x&&y<=i){ky[z]+=p;return;}int mid=x+y>>1;if(o<=mid)gai(x,mid,z<<1,o,i,p);
	if(i>mid)gai(mid+1,y,z<<1|1,o,i,p);
}
int cha(int x,int y,int z,int o){
	if(x==y)return ky[z];int mid=x+y>>1;if(o<=mid)return cha(x,mid,z<<1,o)+ky[z];
	return cha(mid+1,y,z<<1|1,o)+ky[z];
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(s),read(d);
	for(int g=1;g<=s;g++){
		ch=getchar();while(ch<'a'||ch>'z')ch=getchar();int k1=a1[g-1],k2=b1[g-1];
		while(ch>='a'&&ch<='z')a[++k1]=ch-'a',ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z')b[++k2]=ch-'a',ch=getchar();
		a1[g]=k1,b1[g]=k2;
	}
	for(int g=1;g<=d;g++){
		ch=getchar();while(ch<'a'||ch>'z')ch=getchar();int k1=a2[g-1],k2=b2[g-1];
		while(ch>='a'&&ch<='z')a_[++k1]=ch-'a',ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z')b_[++k2]=ch-'a',ch=getchar();
		a2[g]=k1,b2[g]=k2;
	}
	for(int g=1;g<=s;g++){
		int i1=0,i2=a1[g]-a1[g-1];while(i1<i2&&a[a1[g-1]+i1+1]==b[b1[g-1]+i1+1])i1++;
		while(i1<i2&&a[a1[g-1]+i2]==b[b1[g-1]+i2])i2--;if(i1==i2)continue;int k2=0;
		for(int h=i1+1;h<=i2;h++)c[++k2]=a[a1[g-1]+h];c[++k2]=26;
		for(int h=i1+1;h<=i2;h++)c[++k2]=b[b1[g-1]+h];int kk=0;
		for(int h=1;h<=k2;h++){
			if(!to[kk][c[h]])to[kk][c[h]]=++si,fa[si]=kk,af[si]=c[h];kk=to[kk][c[h]];
		}
		if(!w[kk])w[kk]=++f;m[g]=w[kk];l1[g]=i1,l2[g]=i2;
	}
	for(int g=1;g<=d;g++)if(a2[g]-a2[g-1]==b2[g]-b2[g-1]){
		int i1=0,i2=a2[g]-a2[g-1];while(i1<i2&&a_[a2[g-1]+i1+1]==b_[b2[g-1]+i1+1])i1++;
		while(i1<i2&&a_[a2[g-1]+i2]==b_[b2[g-1]+i2])i2--;int k2=0;
		for(int h=i1+1;h<=i2;h++)c[++k2]=a_[a2[g-1]+h];c[++k2]=26;
		for(int h=i1+1;h<=i2;h++)c[++k2]=b_[b2[g-1]+h];int kk=0;bool t=1;
		for(int h=1;h<=k2&&t;h++)if(!to[kk][c[h]])t=0;else kk=to[kk][c[h]];if(t)q[g]=w[kk];
		_l1[g]=i1,_l2[g]=i2;
	}
	for(int g=1;g<=s;g++)u1[g]=op(m[g],g);for(int g=1;g<=d;g++)u2[g]=op(q[g],g);
	sort(u1+1,u1+1+s),sort(u2+1,u2+1+d);
	int k1=1,k2=1;while(k1<=s&&!u1[k1].x)k1++;while(k2<=d&&!u2[k2].x)k2++;
	for(int v=1;v<=f;v++){
		o1=o2=0;while(k1<=s&&u1[k1].x==v)m1[++o1]=u1[k1].y,k1++;
		while(k2<=d&&u2[k2].x==v)m2[++o2]=u2[k2].y,k2++;
		for(int g=1;g<=si;g++)to[fa[g]][af[g]]=0;si=0;
		for(int g=1;g<=o1;g++){
			int kk=0;
			for(int h=l1[m1[g]];h;h--){
				int t=a[a1[m1[g]-1]+h];if(!to[kk][t])to[kk][t]=++si,fa[si]=kk,af[si]=t;
				kk=to[kk][t];
			}
			l1[m1[g]]=kk;
		}
		for(int g=1;g<=o2;g++){
			int kk=0;
			for(int h=_l1[m2[g]];h;h--){
				int t=a_[a2[m2[g]-1]+h];if(!to[kk][t])to[kk][t]=++si,fa[si]=kk,af[si]=t;
				kk=to[kk][t];
			}
			_l1[m2[g]]=kk;
		}
		i=0,dfs(0);
		for(int g=1;g<=o1;g++)l3[m1[g]]=k[l1[m1[g]]]+wi[l1[m1[g]]]-1,l1[m1[g]]=k[l1[m1[g]]];
		for(int g=1;g<=o2;g++)_l1[m2[g]]=k[_l1[m2[g]]];
		for(int g=1;g<=si;g++)to[fa[g]][af[g]]=0;si=0;
		for(int g=1;g<=o1;g++){
			int kk=0;
			for(int h=l2[m1[g]]+1;h<=a1[m1[g]]-a1[m1[g]-1];h++){
				int t=a[a1[m1[g]-1]+h];if(!to[kk][t])to[kk][t]=++si,fa[si]=kk,af[si]=t;
				kk=to[kk][t];
			}
			l2[m1[g]]=kk;
		}
		for(int g=1;g<=o2;g++){
			int kk=0;
			for(int h=_l2[m2[g]]+1;h<=a2[m2[g]]-a2[m2[g]-1];h++){
				int t=a_[a2[m2[g]-1]+h];if(!to[kk][t])to[kk][t]=++si,fa[si]=kk,af[si]=t;
				kk=to[kk][t];
			}
			_l2[m2[g]]=kk;
		}
		i=0,dfs(0);
		for(int g=1;g<=o1;g++)l4[m1[g]]=k[l2[m1[g]]]+wi[l2[m1[g]]]-1,l2[m1[g]]=k[l2[m1[g]]];
		for(int g=1;g<=o2;g++)_l2[m2[g]]=k[_l2[m2[g]]];
		is=0;for(int g=1;g<=o1;g++)V[++is]=l1[m1[g]],V[++is]=l3[m1[g]];
		for(int g=1;g<=o2;g++)V[++is]=_l1[m2[g]];sort(V+1,V+1+is);int kl=0;
		for(int g=1;g<=is;g++)if(V[g]!=V[g-1])V[++kl]=V[g];is=kl;
		for(int g=1;g<=o1;g++)l1[m1[g]]=fi(l1[m1[g]]),l3[m1[g]]=fi(l3[m1[g]]);
		for(int g=1;g<=o2;g++)_l1[m2[g]]=fi(_l1[m2[g]]);
		int kz=0;
		for(int g=1;g<=o1;g++)st[++kz]=po(l2[m1[g]],m1[g],0),
			st[++kz]=po(l4[m1[g]]+1,m1[g],1);
		for(int g=1;g<=o2;g++)st[++kz]=po(_l2[m2[g]],m2[g],2);sort(st+1,st+1+kz);
		for(int g=1;g<=kz;g++)if(!st[g].z)gai(1,is,1,l1[st[g].y],l3[st[g].y],1);
			else if(st[g].z==1)gai(1,is,1,l1[st[g].y],l3[st[g].y],-1);
				else an[st[g].y]=cha(1,is,1,_l1[st[g].y]);
	}
	for(int g=1;g<=d;g++)cout<<an[g]<<'\n';
	return 0;
}
