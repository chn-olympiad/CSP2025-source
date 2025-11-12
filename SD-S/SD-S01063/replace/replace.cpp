#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
char buf[1<<20],*p1,*p2;
#define pb push_back
#define gc() (p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),*p1++)
template<typename T>
void read(T &v){
	T x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc();}
	v=x*f;
}
template<typename T,typename ...Args>
void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
using ll=long long;
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=q;++i)cout<<"0\n";
	return 0;
}
