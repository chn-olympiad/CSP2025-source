#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,q,len;
ll le[N],ans;
string s1[N],s2[N];
string t1,t2;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	}
	return f*x;
}
void dfs(ll x){
	if(x>len) return;
	for(ll i=1;i<=n;i++){
		string k1=s1[i],k2="";
		if(x-le[i]+1<0) continue;
		for(ll j=x-le[i]+1;j<=x;j++) k2+=t1[j];
		//cout<<"< "<<k2<<"\n";
		bool flag=1;
		for(ll j=0;j<k1.length();j++){
			if(k1[j]!=k2[j]){
				flag=0;
				break;
			}
		}
		//cout<<"选择串，实际串："<<k1<<" "<<k2<<"\n";
		if(flag==1){
			string t3="";
			for(ll j=0;j<t1.length();j++) t3=t1;
			//cout<<"< "<<t3<<"\n";
			for(ll j=x-le[i]+1;j<=x;j++) t3[j]=s2[i][j-(x-le[i]+1)];
			//cout<<"< 更改串，目标串："<<t3<<" "<<t2<<"\n";
			bool f=1;
			for(ll j=0;j<t3.length();j++){
				if(t3[j]!=t2[j]){
					f=0;
					break;
				}
			}
			if(f){
				ans++;
			}
		}
	}
	dfs(x+1);
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n=read(),q=read();
	for(ll i=1;i<=n;i++) cin>>s1[i]>>s2[i],le[i]=s2[i].length();
	while(q--){
		ans=0;
		cin>>t1>>t2;
		len=t1.length();
		dfs(0);
		cout<<ans<<"\n";
	}
	return 0;
}