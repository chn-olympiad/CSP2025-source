#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull B=131;
const int N=5007;
ull pw[N],hsh1[N],hsh2[N];
inline ull query1(int l,int r){
	return hsh1[r]-hsh1[l-1]*pw[r-l+1];
}
inline ull query2(int l,int r){
	return hsh2[r]-hsh2[l-1]*pw[r-l+1];
}
map<ull,map<ull,int>>mp;
inline int rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*B;
	int n=rd(),q=rd();
	for(int i=1;i<=n;i++){
		string a,b;cin>>a>>b;
		int hs=0,hs2=0;
		for(int i=0;i<int(a.size());i++)hs=hs*B+a[i]-'a'+1145;
		for(int i=0;i<int(a.size());i++)hs2=hs2*B+b[i]-'a'+1145;
		mp[hs][hs2]++;
	}
	while(q--){
		int res=0;
		string s,t;cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<"\n";
			continue;
		}
		int len=s.size();
		for(int i=1;i<=len;i++)hsh1[i]=hsh1[i-1]*B+s[i-1]-'a'+1145;
		for(int i=1;i<=len;i++)hsh2[i]=hsh2[i-1]*B+t[i-1]-'a'+1145;
		for(int l=0;l<len;l++){
			if(l==0||query1(1,l)==query2(1,l)){
				for(int Len=1;Len<=len;Len++){
					int r=l+Len-1;
					if(r==n-1||query1(r+1,len)==query2(r+1,len)){
						int tmp1=query1(l+1,r+1);
						int tmp2=query2(l+1,r+1);
						if(mp.count(tmp1)){
						    if(mp[tmp1].count(tmp2))res+=mp[tmp1][tmp2];
					    }  
					}
				}
		    }
		}
		cout<<res<<"\n";
	}
}

