#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+50;
const long long M=233;
const long long mod=1e12;
long long n,q,ans,d[N],e[N],w[N];
string ss,zz;
bool FL;
vector<long long>g[N];
vector<string>s,z;
void f(long long x){
	long long l=0,r=s[x].size()-1,k,sum=1;
	while(s[x][l]==z[x][l])
	l++;
	while(s[x][r]==z[x][r])
	r--;
	d[x]=r-l+1;
	g[d[x]].push_back(x);
	k=0;
	for(int i=l;i<=r;i++){
		k+=(s[x][i]-'a')*sum;
		k%=mod;
		sum*=M;
		sum%=mod;
	}
	e[x]=k;
	k=0;
	sum=1;
	for(int i=l;i<=r;i++){
		k+=(z[x][i]-'a')*sum;
		k%=mod;
		sum*=M;
		sum%=mod;
	}
	w[x]=k;
}
void solve1(){
	long long l=0,r=ss.size()-1,k=0,kk=0,sum=1;
	while(ss[l]==zz[l])
	l++;
	while(ss[r]==zz[r])
	r--;
	for(int i=l;i<=r;i++){
		k+=(ss[i]-'a')*sum;
		kk+=(zz[i]-'a')*sum;
		k%=mod;
		kk%=mod;
		sum*=M;
		sum%=mod;
	}
	bool fl=0;
	ans=0;
	int i;
	for(int u=0;u<g[r-l+1].size();u++){
		i=g[r-l+1][u];
//	for(int i=0;i<n;i++){
		if(e[i]!=k||w[i]!=kk)
		continue;
		for(int j=0;j<ss.size()-s[i].size()+1&&j<=l;j++){
			if(s[i][0]==ss[j]){
				fl=0;
				for(int h=0;h<s[i].size();h++){
					if(s[i][h]!=ss[j+h]){
						fl=1;
						break;
					}
					if(z[i][h]!=zz[j+h]){
						fl=1;
						break;
					}
				}
				if(fl==0){
					if(j+s[i].size()-1>=r)
					ans++;
				}
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>ss>>zz;
		if(ss==zz){
			i--;
			n--;
			continue;
		}
		s.push_back(ss);
		z.push_back(zz);
		f(i-1);
	}
	for(int i=1;i<=q;i++){
		cin>>ss>>zz;
		if(ss.size()!=zz.size()){
			printf("%lld\n",0ll);
			continue;
		}
		solve1();
	}
}
