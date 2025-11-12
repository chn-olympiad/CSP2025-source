#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
#define Multitest Int T;cin>>T;while(T--)
typedef long long Int;

Int n,x,y,z,as[100005],bs[100005],cs[100005],ans;

int main(){
	IOS;OpenFile(club);
	
	Multitest{
		cin>>n;
		x=y=z=ans=0;
		for(Int i=1;i<=n;i++){
			Int a,b,c;
			cin>>a>>b>>c;
			ans+=max({a,b,c});
			if(max({a,b,c})==a)as[++x]=max(b,c)-a;
			else if(max({a,b,c})==b)bs[++y]=max(a,c)-b;
			else cs[++z]=max(a,b)-c;
		}
		sort(as+1,as+x+1);
		sort(bs+1,bs+y+1);
		sort(cs+1,cs+z+1);
		while(x>n/2)ans+=as[x--];
		while(y>n/2)ans+=bs[y--];
		while(z>n/2)ans+=cs[z--];
		cout<<ans<<endl;
	}
	
	return 0;
}
