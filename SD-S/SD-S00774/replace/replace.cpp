#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int re(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
string t1,t2;
inline int fd(string s,string t,int p){
	string ss="";
	for(int i=p;i<s.length();i++)ss+=s[i];
	if(ss.find(t)>=ss.length())return -1;
	return ss.find(t)+p;
}
inline string rp(string s,string t,int p){
	for(int i=0;i<t.length();i++)s[p+i]=t[i];
	return s;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=re(),q=re();
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];		
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			int p=0,k=fd(t1,s1[j],p);
			while(k!=-1){
				if(rp(t1,s2[j],k)==t2){
					ans++;
					break; 
				}
				p=k+s1[j].length();
				k=fd(t1,s1[j],p);
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}

