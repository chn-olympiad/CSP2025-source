#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
inline int read();
int fac[5000005];
int inv[5000005];
std::string sp[200005][2];
std::string s[200005][2];
std::string t[200005][2];
std::string tp[200005][2];
char temp[200005];
std::vector<int>vec;
std::map<int,int>vec2[200005];
void readstring(std::string &a){
	scanf("%s",temp+1);
	a=std::string(temp+1);
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read();
	int q=read();
	if(q==1){
		for(int i=1;i<=n;i++){
			readstring(sp[i][0]);
			readstring(sp[i][1]);
		}
		for(int i=1;i<=q;i++){
			readstring(tp[i][0]);
			readstring(tp[i][1]);
		}
		int lss=0,stt=0;
		for(int i=1;i<=q;i++){
			int st=tp[i][0].size();
			for(int j=0;j<tp[i][0].size();j++){
				if(tp[i][0][j]!=tp[i][1][j]){
					st=j;
					break;
				}
			}
			int ls=-1;
			for(int j=tp[i][0].size()-1;j>=0;j--){
				if(tp[i][0][j]!=tp[i][1][j]){
					ls=j;
					break;
				}
			}
			ls++;
			ls=std::max(ls,st);
			t[i][0]=std::string(tp[i][0],st,ls-st);
			t[i][1]=std::string(tp[i][1],st,ls-st);
			stt=st;
			lss=ls;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int st=sp[i][0].size();
			for(int j=0;j<sp[i][0].size();j++){
				if(sp[i][0][j]!=sp[i][1][j]){
					st=j;
					break;
				}
			}
			int ls=-1;
			int cnt=0;
			for(int j=sp[i][0].size()-1;j>=0;j--){
				if(sp[i][0][j]!=sp[i][1][j]){
					ls=j;
					cnt++;
					break;
				}
			}
			ls++;
			ls=std::max(ls,st);
			s[i][0]=std::string(sp[i][0],st,ls-st);
			s[i][1]=std::string(sp[i][1],st,ls-st);
			int curl=lss-st-2;
			int curl2=0;
			for(int j=0;j<st;j++){
				if(sp[i][0][curl2]!=tp[1][0][curl]){
					break;
					goto end;
				}
				curl2++;
				curl++;
				ans++;
				end:{}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}