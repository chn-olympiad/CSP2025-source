#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const long long N=10086;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;cin>>n>>q;
	map<string,string> mp;
	for(long long i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		mp[s1]=s2;
	}
	long long ans=0;
	for(long long i=1;i<=q;i++){
		string s1,s2;cin>>s1>>s2;
		long long len=s1.size();
		long long sb1=0,sb2=0;
		for(long long i=0;i<len;i++){
			if(s1[i]=='b')sb1=i;
			if(s2[i]=='b')sb2=i;
		}
		for(long long i=0;i<=sb1;i++){
			for(long long j=sb1;j<len;j++){
				string ts1,ts2;
				long long pos=0;
				for(long long k=i;k<=j;k++){
					ts1[pos]=s1[k];
					ts2[pos++]=s2[k];
				}
				if(mp[ts1]==ts2){
					for(long long l=0;l<j-i+1;l++){
						cout<<ts1[l];
					}cout<<"\n";
					ans++; 
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

