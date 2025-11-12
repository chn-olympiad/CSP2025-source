#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=1e18;
unsigned long long p[5000005];
int hs(unsigned long long x){
	unsigned long long mul=0;
	while(x>0){
		mul=mul*128+x%10+48;
		mul%=1000000;
		x/=10;
	}
	return (int)(mul);
}
struct px{
	unsigned long long a,b;
	int bg,ed;
	int len;
};
vector<px>h[1000005]; 
unsigned long long h1[1000005],h2[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
	for(int i=1;i<5000005;i++)p[i]=p[i-1]*27;
	int n,q;
	cin>>n>>q;
	string a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		unsigned long long a1=0,b1=0,a2=0,b2=0;
		int bg=0,ed=a.size()-1; 
		for(;bg<a.size();bg++)if(a[bg]!=b[bg])break;
		for(;ed>=bg-1;ed--)if(a[ed]!=b[ed])break;
		for(int j=bg;j<=ed;j++){
			a1=a1*27+a[j]-'a'+1;
			b1=b1*27+b[j]-'a'+1;
		}
		for(int j=0;j<a.size();j++){
			a2=a2*27+a[j]-'a'+1;
			b2=b2*27+b[j]-'a'+1;
		}
		h[hs(a1*998244353+b1)].push_back({a2,b2,bg,ed,(int)(a.size())});
//		cout<<i<<' '<<a2<<' '<<b2<<' '<<a1<<' '<<b1<<' '<<a1*998244353+b1<<' '<<hs(a1*998244353+b1)<<'\n';
	}
	while(q--){
//		cout<<'!'; 
		cin>>a>>b;
		unsigned long long a1=0,b1=0,a2=0,b2=0;
		int bg=0,ed=a.size()-1; 
		for(;bg<a.size();bg++)if(a[bg]!=b[bg])break;
		for(;ed>=bg-1;ed--)if(a[ed]!=b[ed])break;
		for(int j=bg;j<=ed;j++){
			a1=a1*27+a[j]-'a'+1;
			b1=b1*27+b[j]-'a'+1;
		}
		for(int j=0;j<a.size();j++){
			h1[j]=(j==0?0:h1[j-1])*27+a[j]-'a'+1;
			h2[j]=(j==0?0:h2[j-1])*27+b[j]-'a'+1;
		}
		unsigned long long ans=0,tmp=hs(a1*998244353+b1);
//		if(q>27300)cout<<27578-q<<' '<<a1<<' '<<b1<<' '<<tmp<<'\n';
		for(int i=0;i<h[tmp].size();i++){
			for(int j=h[tmp][i].len-1;j<a.size();j++){
				unsigned long long tmpa=0,tmpb=0;
				if(j-h[tmp][i].len<0){
					tmpa=h1[j];
					tmpb=h2[j];
				}
				else{
					tmpa=h1[j]-h1[j-h[tmp][i].len]*p[h[tmp][i].len];
					tmpb=h2[j]-h2[j-h[tmp][i].len]*p[h[tmp][i].len];
				}
				if(tmpa==h[tmp][i].a&&tmpb==h[tmp][i].b){
					ans+=(ed-bg==h[tmp][i].ed-h[tmp][i].bg);
					break;
				}
//				if(27578-q==101)cout<<27578-q+1<<' '<<i<<' '<<j<<' '<<tmpa<<' '<<tmpb<<' '<<h[tmp][i].a<<' '<<h[tmp][i].b<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
