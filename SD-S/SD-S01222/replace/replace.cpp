#include<bits/stdc++.h>
using namespace std;
const long long base1=131,base2=233,mod1=100205023,mod2=993244853;
string s1[200010],s2[200010];
long long a1[200010],a2[200010],b1[200010],b2[200010],ba1[200010],ba2[200010],ib1[200010],ib2[200010];
typedef long long LL;
LL ksm(LL a,LL b,LL p){
	if(a==1)return 1;
	LL res=1;
	for(;b;a=a*a%p,b>>=1){
		if(b&1)res=res*a%p;
	}
	return res;
}
LL has1(string t){
	LL res=0;
	for(int j=0;j<t.size();j++)res=res*base1+t[j]%mod1;
	return res;
}
LL has2(string t){
	LL res=0;
	for(int j=0;j<t.size();j++)res=res*base2+t[j]%mod2;
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	ba1[0]=ba2[0]=ib1[0]=ba1[0]=1;
	for(int i=1;i<=200000;i++)ba1[i]=ba1[i-1]*base1%mod1,ba2[i]=ba2[i-1]*base2%mod2;
	ib1[200000]=ksm(ba1[200000],mod1-2,mod1);
	ib2[200000]=ksm(ba2[200000],mod2-2,mod2);
	for(int i=199999;i>=0;i--)ba1[i]=ba1[i+1]*base1%mod1,ba2[i]=ba2[i+1]*base2%mod2;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++)a1[i]=a1[i]*base1+s1[i][j]%mod1;
		for(int j=0;j<s1[i].size();j++)b1[i]=b1[i]*base2+s1[i][j]%mod2;
		for(int j=0;j<s1[i].size();j++)a2[i]=a2[i]*base1+s2[i][j]%mod1;
		for(int j=0;j<s1[i].size();j++)b2[i]=b2[i]*base2+s2[i][j]%mod2;
	}
	long long ans=0;
	while(q--){
		string t1,t2,t3;
		cin>>t3>>t2;
		t1=t3;
		if(t1.size()!=t2.size()){
			puts("0");
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=s1[i].size()-1;j<t1.size();j++){
				t1=t3;
				if(t1.substr(j-s1[i].size()+1,s1[i].size())==s1[i]&&t1.replace(j-s1[i].size()+1,s1[i].size(),s2[i])==t2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

