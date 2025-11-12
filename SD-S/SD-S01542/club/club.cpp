#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct node{
	int a,b,c,mxx,id,id2,mxx2;
}s[maxn];
bool cmp(node x,node y){
	return x.mxx>y.mxx;
}
int f[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>s[i].a>>s[i].b>>s[i].c;
    		int mx=max(s[i].a,s[i].b);
    		s[i].mxx=max(mx,s[i].c);
    		if(s[i].mxx==s[i].a){
    			if(s[i].b>=s[i].c){
    				s[i].mxx2=s[i].b;
    				s[i].id2=2;
				}else{
					s[i].mxx2=s[i].c;
    				s[i].id2=3;
				}
				s[i].id=1;
			}
    		if(s[i].mxx==s[i].b){
    			if(s[i].a>=s[i].c){
    				s[i].mxx2=s[i].a;
    				s[i].id2=1;
				}else{
					s[i].mxx2=s[i].c;
    				s[i].id2=3;
				}
				s[i].id=2;
			}
    		if(s[i].mxx==s[i].c){
    			if(s[i].b>=s[i].a){
    				s[i].mxx2=s[i].b;
    				s[i].id2=2;
				}else{
					s[i].mxx2=s[i].a;
    				s[i].id2=1;
				}
				s[i].id=3;
			}
		}
		sort(s+1,s+n+1,cmp);
		int k1,k2;
		for(int i=1;i<=n;i++){
			f[s[i].id]++;
			if(f[s[i].id]==n/2){
				k1=s[i].mxx2;
				k2=s[i].mxx;
				break;
			}
		}
	    ll ans=0;
	    f[1]=f[2]=f[3]=0;
	    int flag=0;
		for(int i=1;i<=n;i++){
			if(f[s[i].id]<n/2){
				ans+=s[i].mxx;
				f[s[i].id]++;
			}else{
				if(flag==0){
					if(s[i].mxx+k1>=k2+s[i].mxx2){
						ans-=k2;
						ans+=s[i].mxx+k1;
					    flag=1;
				    }
				}else{
					ans+=s[i].mxx2;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//Ren5Jie4Di4Ling5%

