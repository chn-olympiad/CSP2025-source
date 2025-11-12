#include<bits/stdc++.h>
using namespace std;
long long mod1=998244353;
long long mod2=1000000007;
map<pair<long long,long long>,pair<long long,long long>> ma; 
pair<long long,long long> hsh(string &s){
	long long a=0,b=0;
	for(long long i=0;i<s.size();i++){
		a=(a*233+s[i])%mod1;
		b=(b*233+s[i])%mod2;
	}
	return {a,b};
}
long long n,m,cnt,s1_1[100000],s1_2[100000],s2_1[100000],s2_2[100000],s3[100000],s4[100000];
pair<long long,long long> s1(long long l,long long r){
	long long a,b;
	if(l==0){
		return {s1_1[r],s1_2[r]};
	}
	a=(s1_1[r]-s1_1[l-1]*s3[r-l+1]%mod1+mod1)%mod1;
	b=(s1_2[r]-s1_2[l-1]*s4[r-l+1]%mod2+mod2)%mod2;
	return {a,b};
}
pair<long long,long long> s2(long long l,long long r){
	long long a,b;
	if(l==0){
		return {s2_1[r],s2_2[r]};
	}
	a=(s2_1[r]-s2_1[l-1]*s3[r-l+1]%mod1+mod1)%mod1;
	b=(s2_2[r]-s2_2[l-1]*s4[r-l+1]%mod2+mod2)%mod2;
	return {a,b};
}
struct S{
	long long a,b;
}z[1000000];
map<long long,vector<S>> mma;
long long x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	string a,b;
	bool fla=0;
	for(long long i=0;i<n;i++){
		cin>>a>>b;
		for(long long j=0;j<a.size();j++){
			if(a[j]=='b')z[i].a=j;
			if(b[j]=='b')z[i].b=j;
		}
		mma[z[i].a-z[i].b].push_back({z[i].a,a.size()-z[i].b});
		for(long long j=0;j<a.size();j++){
			if(a[j]!='a'&&a[j]!='b')fla=1;
			if(b[j]!='a'&&b[j]!='b')fla=1;
		}
		ma[hsh(a)]=hsh(b);
	}
	for(long long o=0;o<m;o++){
		cin>>a>>b;
		cnt=0;
		if(!fla){
			for(long long i=0;i<a.size();i++){
				if(a[i]=='b')x=i;
				if(b[i]=='b')y=i;
			}
			for(auto i:mma[x-y]){
				if(i.a<=x&&i.b<=a.size()-y)cnt++;
			}
			cout<<cnt<<"\n";
			continue;
		}
		s1_1[0]=s1_2[0]=a[0];
		s2_1[0]=s2_2[0]=b[0];
		s3[0]=s4[0]=1;
		for(long long i=1;i<a.size();i++){
			s1_1[i]=(s1_1[i-1]*233+a[i])%mod1;
			s1_2[i]=(s1_2[i-1]*233+a[i])%mod2;
			s2_1[i]=(s2_1[i-1]*233+b[i])%mod1;
			s2_2[i]=(s2_2[i-1]*233+b[i])%mod2;
			s3[i]=(s3[i-1]*233)%mod1;
			s4[i]=(s4[i-1]*233)%mod2;
		}
		cnt=0;
		for(long long i=0;i<a.size();i++){
			for(long long j=i;j<a.size();j++){
				if(ma[s1(i,j)]==s2(i,j)&&s1(0,i-1)==s2(0,i-1)&&s1(j+1,a.size()-1)==s2(j+1,a.size()-1)){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
