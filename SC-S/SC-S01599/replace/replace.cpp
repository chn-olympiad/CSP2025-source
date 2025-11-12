#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-'){
			f=-f;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
string s1[200001];
string s2[200001];
struct sj{
	string x,y,z;
	int bh,bh2;
};
sj s[200001];
sj z[200001];
map<int,int>zds[5000001];
map<int,int>zds2[5000001];
vector<int>nx[5000001];
pair<int,int>qj[5000001];
pair<int,int>zc[200005];
int sz[200005];
sj px1[200001];
int px2[200001];
bool ff1(const int a,const int b){
	return px1[a].y<px1[b].y;
}
bool ff2(const int a,const int b){
	return px1[a].z<px1[b].z;
}
int cf[200005];
int dy[200005];
int da[200005];
int cx1(string a){
	int d=0;
	for(int v=0;v<a.size();++v){
		if(zds[d][a[v]]==0){
			return -1;
		}
		d=zds[d][a[v]];
	}
	return d;
}
int cx2(string a){
	int d=0;
	for(int v=0;v<a.size();++v){
		if(zds2[d][a[v]]==0){
			return -1;
		}
		d=zds2[d][a[v]];
	}
	return d;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b,c,d,e,l,r;
	char ch;
	a=read();
	b=read();
	for(int v=1;v<=a;++v){
		s1[v].clear();
		s2[v].clear();
		ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z'){
			s1[v]+=ch;
			ch=getchar();
		}
		ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z'){
			s2[v]+=ch;
			ch=getchar();
		}
		if(s1[v]==s2[v]){
			continue;
		}
		l=0;
		r=s1[v].size()-1;
		while(s1[v][l]==s2[v][l]){
			++l;
		}
		while(s1[v][r]==s2[v][r]){
			--r;
		}
		for(int var=l-1;var>=0;--var){
			s[v].x+=s1[v][var];
		}
		for(int var=r+1;var<s1[v].size();++var){
			s[v].z+=s1[v][var];
		}
		for(int var=l;var<=r;++var){
			s[v].y+=s1[v][var];
			s[v].y+=s2[v][var];
		}
	}
	for(int v=1;v<=a;++v){
		px1[v]=s[v];
		px2[v]=v;
	}
	sort(px2+1,px2+a+1,ff1);
	for(int v=1;v<=a;++v){
		s[v]=px1[px2[v]];
	}
	for(int v=1;v<=b;++v){
		s1[v].clear();
		s2[v].clear();
		ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z'){
			s1[v]+=ch;
			ch=getchar();
		}
		ch=getchar();
		while(ch<'a'||ch>'z')ch=getchar();
		while(ch>='a'&&ch<='z'){
			s2[v]+=ch;
			ch=getchar();
		}
		z[v].bh2=v;
		l=0;
		r=s1[v].size()-1;
		while(s1[v][l]==s2[v][l]){
			++l;
		}
		while(s1[v][r]==s2[v][r]){
			--r;
		}
		for(int var=l-1;var>=0;--var){
			z[v].x+=s1[v][var];
		}
		for(int var=r+1;var<s1[v].size();++var){
			z[v].z+=s1[v][var];
		}
		for(int var=l;var<=r;++var){
			z[v].y+=s1[v][var];
			z[v].y+=s2[v][var];
		}
	}
	for(int v=1;v<=b;++v){
		px1[v]=z[v];
		px2[v]=v;
	}
	sort(px2+1,px2+b+1,ff2);
	for(int v=1;v<=b;++v){
		z[v]=px1[px2[v]];
	}
	qj[0]={1,b};
	c=0;
	for(int v=1;v<=b;++v){
		z[v].bh=v;
		d=0;
		for(int var=0;var<z[v].z.size();++var){
			if(zds[d][z[v].z[var]]==0){
				zds[d][z[v].z[var]]=++c;
				qj[c].first=v;
			}
			d=zds[d][z[v].z[var]];
			qj[d].second=v;
		}
	}
	for(int v=1;v<=b;++v){
		px1[v]=z[v];
		px2[v]=v;
	}
	sort(px2+1,px2+b+1,ff1);
	for(int v=1;v<=b;++v){
		z[v]=px1[px2[v]];
	}
	l=1;
	r=1;
	for(int v=1,v1;v<=b;v=v1){
		v1=v; 
		while(v1<=b&&z[v1].y==z[v].y){
			++v1;
		}
		c=0;
		for(int var=v;var<v1;++var){
			d=0;
			nx[d].push_back(var);
			for(int va=0;va<z[var].x.size();++va){
				if(zds2[d][z[var].x[va]]==0){
					zds2[d][z[var].x[va]]=++c;
				}
				d=zds2[d][z[var].x[va]];
				nx[d].push_back(var);
			}
		}
		while(l<=a&&s[l].y<z[v].y)++l;
		r=-1;
		while(l<=a&&s[l].y==z[v].y){
			d=cx2(s[l].x);
			if(d!=r){
				if(r>-1){
					for(int v=1;v<=nx[r].size();++v){
						cf[v]=cf[v]+cf[v-1];
						da[dy[v]]+=cf[v];
					}
				}
				if(d>-1){
					for(int v=1;v<=nx[d].size();++v){
						cf[v]=0;
						zc[v]={z[nx[d][v-1]].bh,z[nx[d][v-1]].bh2};
					}
					sort(zc+1,zc+nx[d].size()+1);
					for(int v=1;v<=nx[d].size();++v){
						sz[v]=zc[v].first;
						dy[v]=zc[v].second;
					}
					sz[nx[d].size()+1]=1145141919;
				}
				r=d;
			}
			if(r>-1){
				d=cx1(s[l].z);
				if(d>-1){
					e=lower_bound(sz+1,sz+nx[r].size()+2,qj[d].first)-sz;
					++cf[e];
					e=upper_bound(sz+1,sz+nx[r].size()+2,qj[d].second)-sz;
					--cf[e];
				}
			}
			++l;
		}
		if(r>-1){
			for(int v=1;v<=nx[r].size();++v){
				cf[v]=cf[v]+cf[v-1];
				da[dy[v]]+=cf[v];
			}
		}
		for(int v=0;v<=c;++v){
			zds2[v].clear();
			nx[v].clear();
		}
	}
	for(int v=1;v<=b;++v){
		cout<<da[v]<<'\n';
	}
	return 0;
} 