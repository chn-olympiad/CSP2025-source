#include<bits/stdc++.h>
using namespace std;
int T;
int n,ans;
int cha[100002],chb[100002],chc[100002];
int ca,cb,cc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0,ca=0,cb=0,cc=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c){
				ans+=a;
				++ca;
				if(b>=c){
					cha[ca]=a-b;
				}else{
					cha[ca]=a-c;
				}
			}else if(b>=a&&b>=c){
				ans+=b;
				++cb;
				if(a>=c){
					chb[cb]=b-a;
				}else{
					chb[cb]=b-c;
				}
			}else{
				ans+=c;
				++cc;
				if(a>=b){
					chc[cc]=c-a;
				}else{
					chc[cc]=c-b;
				}
			}
		}
//		printf("%d %d %d %d\n",ans,ca,cb,cc);
		if(ca*2>n){
			int l=0;
			sort(cha+1,cha+1+ca);
			while(ca*2>n){
				ans-=cha[++l];
				--ca;
			}
		}else if(cb*2>n){
			int l=0;
			sort(chb+1,chb+1+cb);
			while(cb*2>n){
				ans-=chb[++l];
				--cb;
			}
		}else if(cc*2>n){
			int l=0;
			sort(chc+1,chc+1+cc);
			while(cc*2>n){
				ans-=chc[++l];
				--cc;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}