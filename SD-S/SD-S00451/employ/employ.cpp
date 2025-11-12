#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
void r(int&x){//u32
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}return;
}
int n,m;
bool mian[502];
int naixin[502],pailie[502];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	r(n),r(m);char tmp=getchar();
	while(!isdigit(tmp))tmp=getchar();
	for(int i=1;i<=n;++i){
		mian[i]=(tmp-'0');
		tmp=getchar();
	}
	for(int i=1;i<=n;++i){
		pailie[i]=i;
		r(naixin[i]);
	}int ans=0;
	do{
		int tmpans=0,deny=0;
		for(int i=1;i<=n;++i){
			if(!mian[i]){
				++deny;
				continue;
			}else{
				if(deny>=naixin[pailie[i]]){
					++deny;continue;
				}else{
					++tmpans;
					if(tmpans>=m){
						++ans;break;
					}
				}
			}
		}
	}while(next_permutation(pailie+1,pailie+1+n));
	printf("%d\n",ans);
	return 0;
}
