# include<bits/stdc++.h>
# define int long long
using namespace std;
const int N=2e5+5;
int n,q,b1[N],b2[N],a1[N],a2[N];
string s1,s2,t1,t2;
int getb(string s){
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='b') return i+1;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin >> s1 >> s2;
		a1[i]=getb(s1);a2[i]=getb(s2);
		b1[i]=s1.length()-a1[i];
		b2[i]=s2.length()-a2[i];
	}
	while(q--){
		cin >> t1 >> t2;
		if(t1.length()!=t2.length()){
			printf("0\n");
			continue;
		}
		int ans=0;
		int b3=getb(t1);
		int b4=getb(t2);
		for(int i=1;i<=n;i++){
			if(a1[i]<=b3&&(t1.length()-b3)>=b1[i]&&a2[i]<=b4&&(t2.length()-b4)>=b2[i]&&a1[i]-a2[i]==b3-b4) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}