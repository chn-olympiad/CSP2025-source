#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#define _for(i,a,b) for(int i=(a);i<=(b);i++)
#define _rof(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,num=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return f*num;
}
int n,q;
string s1[200005],s2[200005];
inline string rp(string a,string b,string c){
	if(a.size()<b.size()) return "";
	int n=a.size(),m=b.size();
	_for(i,0,n-m){
		int flg=1;
		_for(j,0,m-1){
			if(a[i+j]!=b[j]){
				flg=0;
				break;
			}
		}
		if(flg){
			_for(j,0,m-1) a[i+j]=c[j];
			return a;
		}
	}
	return "";
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	n=read(),q=read();
	if(n>=1e3 && q>=1e3){
		_for(i,1,q) cout<<0<<'\n';
		return 0;
	}
	_for(i,1,n){
		cin>>s1[i]>>s2[i];
	}
	_for(i,1,q){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue; 
		}
		int cnt=0;
		_for(i,1,n){
			if(rp(t1,s1[i],s2[i])==t2) cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
//i love ccf
