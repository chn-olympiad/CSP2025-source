#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define fi first
#define se second
#define pii pair<int,int>
const int N=1e5+5,mod=1e9+7;
int read(){
	int w=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*w;
}
struct stu{
	int a,b,c,cha,ma;
}s[N];
int t,n,ma[N],ans,va,vb,vc;
bool cmp(stu x,stu y){
	return x.cha>y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		va=vb=vc=ans=0;
		for(int i=1;i<=n;i++){
			s[i].a=read(),s[i].b=read(),s[i].c=read();
			s[i].ma=max(s[i].a,max(s[i].c,s[i].b));
			s[i].cha=max(s[i].a,max(s[i].c,s[i].b))-min(min(max(s[i].a,s[i].c),max(s[i].b,s[i].c)),max(s[i].a,s[i].b));
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(s[i].ma==s[i].a){
				ans+=s[i].ma;
				va++;
				if(va>n/2)ans-=s[i].cha;
			}
			else if(s[i].ma==s[i].b){
				ans+=s[i].ma;
				vb++;
				if(vb>n/2)ans-=s[i].cha;
			}
			else if(s[i].ma==s[i].c){
				ans+=s[i].ma;
				vc++;
				if(vc>n/2)ans-=s[i].cha;
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}


