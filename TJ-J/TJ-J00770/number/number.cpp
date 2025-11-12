#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <string>

template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}

const int maxn=1e6+5;

namespace Force{
	char s[maxn];
	int c[20];
	void solve(){
		scanf("%s",&s[1]);	
		int n=strlen(&s[1]);

		for(int i=1;i<=n;i++) if('0'<=s[i]&&s[i]<='9') c[s[i]-'0']++;
	
		std::string ans;
		bool has=false;
		for(int i=9;i>=1;i--){
			if(c[i]){
				has=true;
				while(c[i]--) ans+='0'+i;
			}
		} 
		if(!has){
			assert(c[0]);
			puts("0");
		}else{
			while(c[0]--) ans+='0';
			printf("%s\n",ans.c_str());
		}
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	Force::solve();

	return 0;
}