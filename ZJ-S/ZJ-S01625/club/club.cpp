#include<bits/stdc++.h>
using namespace std;
long long T,n,a,b,c,ans;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		cin>>n;
		a=b=c=ans=0;
		vector<int>v1,v2,v3;
		for(int i=1,x,y,z; i<=n; i++){
			cin>>x>>y>>z;
			if(x>=y&&x>=z)a++,ans+=x,v1.push_back(x-max(y,z));
			else if(y>=x&&y>=z)b++,ans+=y,v2.push_back(y-max(x,z));
			else c++,ans+=z,v3.push_back(z-max(x,y));
		}
		if(a<=n/2&&b<=n/2&&c<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		if(a>n/2){
			sort(v1.begin(),v1.end());
			for(int i=a;i>n/2;i--)ans-=v1[a-i];
		}
		if(b>n/2){
			sort(v2.begin(),v2.end());
			for(int i=b;i>n/2;i--)ans-=v2[b-i];
		}
		if(c>n/2){
			sort(v3.begin(),v3.end());
			for(int i=c;i>n/2;i--)ans-=v3[c-i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
我觉得我没救了，估分100+64+25+8=197pts。不知道能不能拿S1=(别跟我说200 1=我直接被卡)。
I -> CSP-J
CSP-S -> me
NOIP -> me
ICPC -> me
WC -> me
NOI -> me
IOI -> me
CCF -> me
那一天的挂分挂分起来，那一天的AFO AFO起来
CCF以挂分痛吻我，我却报之以歌
If I can up mi huo sth. big show,please close pig luogu:slzxzhengguo123(I think my English is very nice!!!)
*/