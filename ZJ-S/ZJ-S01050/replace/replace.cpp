#include<bits/stdc++.h>
using namespace std;
const long long N=5e6+10;
const long long mod=998244353;
const long long p1=223,p2=271;
map<long long,map<long long,long long>> mp;
map<long long,map<long long,long long>> mp2;
long long n,q,len[N];
char c[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		scanf("%s",c+1);
		scanf("%s",t+1);
		long long l=1,r=strlen(c+1);
		long long st1=0,st2=0,en1=0,en2=0;
		for(long long j=l;j<=r;j++){
			st1=(st1*p1+c[j]-'a'+1)%mod;
			en1=(en1*p1+t[j]-'a'+1)%mod;
		}
		mp[st1][en1]++;
		while(c[l]==t[l])l++;
		while(c[r]==t[r])r--;
		st1=0,st2=0,en1=0,en2=0;
		for(long long j=l;j<=r;j++){
			st1=(st1*p1+c[j]-'a'+1)%mod;
			en1=(en1*p1+t[j]-'a'+1)%mod;
		}
		mp2[st1][en1]++;
	}
	if(n>3000){
		while(q--){
			scanf("%s",c+1);
			scanf("%s",t+1);
			long long l=1,r=strlen(c+1);
			while(c[l]==t[l])l++;
			while(c[r]==t[r])r--;
			long long len1=strlen(c+1);
			long long len2=strlen(t+1);
			if(len1!=len2){
				cout<<0;
				return 0;
			}else{
				long long st1=0,st2=0,en1=0,en2=0,sum=0;
				for(long long k=l;k<=r;k++){
					st1=(st1*p1+c[k]-'a'+1)%mod;
					en1=(en1*p1+t[k]-'a'+1)%mod;
					if(k>=r){
						sum+=mp2[st1][en1];
					}
				}
				cout<<sum<<'\n';
			}
		}
	}else{
		while(q--){
			scanf("%s",c+1);
			scanf("%s",t+1);
			long long l=1,r=strlen(c+1);
			while(c[l]==t[l])l++;
			while(c[r]==t[r])r--;
			long long len1=strlen(c+1);
			long long len2=strlen(t+1);
			if(len1!=len2){
				cout<<0<<'\n';
				continue;
			}
			if(n<=3000&&len1<=2000){
				long long sum=0;
				for(long long j=1;j<=l;j++){
					long long st1=0,st2=0,en1=0,en2=0;
					for(long long k=j;k<=len1;k++){
						st1=(st1*p1+c[k]-'a'+1)%mod;
						en1=(en1*p1+t[k]-'a'+1)%mod;
						if(k>=r){
							sum+=mp[st1][en1];
						}
					}
				}
				printf("%lld\n",sum);
			}
		}
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/