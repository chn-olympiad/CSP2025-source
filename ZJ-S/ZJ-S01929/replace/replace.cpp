#include<iostream>
#include<cstring>
#define MAXN 200005
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return ;
}
int n,Q;
std::string a[MAXN],b[MAXN];
std::string c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::cin>>n>>Q;
	for(int i=1;i<=n;i++)std::cin>>a[i]>>b[i];
	while(Q--){
		std::cin>>c>>d;
		if(c.size()!=d.size()){
			puts("0");
			continue;
		}int len=c.size();
		bool e=true;
		int cmp=0;
		int st,ed;
		for(int i=0;i<len;i++){
			if(e&&c[i]!=d[i]){
				st=i;
				e=false;
			}
			if(c[i]==d[i]&&!e){
				ed=i-1;
				e=true;
				cmp++;
			}
		}
		if(cmp!=1){
			puts("0");
			continue;
		}std::string sc="",sd="";
		for(int i=st;i<=ed;i++)sc+=c[i],sd+=d[i];
		
		
		int ans=0;
		for(int i=1;i<=n;i++){
			int fsc=a[i].find(sc),fsd=b[i].find(sd);
			if(fsc!=-1&&fsd!=-1&&fsc==fsd&&a[i].size()==b[i].size()){
				bool ef=true;
				for(int p=fsc-1,q=st-1;p>=0;p--,q--){
					if(q<0){
						ef=false;
						break;
					}
					if(a[i][p]!=c[q]||b[i][p]!=c[q]){
						ef=false;
						break;
					}
				}
				if(!ef)continue;
				for(int p=fsc+sc.size(),q=ed+1;p<a[i].size();p++,q++){
					if(q>=c.size()){
						ef=false;
						break;
					}
					if(a[i][p]!=c[q]||b[i][p]!=c[q]){
						ef=false;
						break;
					}
				}if(!ef)continue;
				ans++;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
