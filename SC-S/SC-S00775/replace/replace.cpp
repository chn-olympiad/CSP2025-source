#include<bits/stdc++.h>
using namespace std;
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*f;
}
const int MAXN=5e6+10;
const int mod=998244353;

int n,q,pi[MAXN];
map<pair<string,string>,vector<pair<string,string> > > t;

void kmp(string s){
	int N=s.length()-1;
	for(int i=1;i<=N;i++) pi[i]=0;
	for(int i=2,j=0;i<=N;i++){
		while(j&&s[i]!=s[j+1]) j=pi[j];
		if(s[i]==s[j+1]) j++;
		pi[i]=j;
	}
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace3.in","r",stdin);
//	freopen("replace3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2,s;
		cin>>s1>>s2;
		s=' '+s1+'#'+s2;
//		cout<<s<<endl;
		kmp(s);
//		for(int i=1;i<s.length();i++) cout<<pi[i]<<' ';
//		cout<<endl;
		int maxpre=0;
		for(int i=1;i<s.length();i++) if(pi[i]==i-s1.length()-1) maxpre=max(maxpre,pi[i]);
//		cout<<maxpre<<endl;
		for(int l=1,r=s.length()-1;l<r;l++,r--) swap(s[l],s[r]);
//		cout<<s<<endl;
		kmp(s);
//		for(int i=1;i<s.length();i++) cout<<pi[i]<<' ';
//		cout<<endl;
		int maxsuf=0;
		for(int i=1;i<s.length();i++) if(pi[i]==i-s1.length()-1) maxsuf=max(maxsuf,pi[i]);
//		cout<<maxsuf<<endl;
		int len=s1.length()-maxpre-maxsuf;
		string S1=s1.substr(maxpre,len),S2=s2.substr(maxpre,len);
		t[{S1,S2}].push_back({s1.substr(0,maxpre),s1.substr(maxpre+len,maxsuf)});
//		cout<<s1<<' '<<s2<<endl;
	}
	for(int i=1;i<=q;i++){
		string s1,s2,s;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<'\n';
			continue;
		}
		s=' '+s1+'#'+s2;
//		cout<<s<<endl;
		kmp(s);
//		for(int i=1;i<s.length();i++) cout<<pi[i]<<' ';
//		cout<<endl;
		int maxpre=0;
		for(int i=1;i<s.length();i++) if(pi[i]==i-s1.length()-1) maxpre=max(maxpre,pi[i]);
//		cout<<maxpre<<endl;
		for(int l=1,r=s.length()-1;l<r;l++,r--) swap(s[l],s[r]);
//		cout<<s<<endl;
		kmp(s);
//		for(int i=1;i<s.length();i++) cout<<pi[i]<<' ';
//		cout<<endl;
		int maxsuf=0;
		for(int i=1;i<s.length();i++) if(pi[i]==i-s1.length()-1) maxsuf=max(maxsuf,pi[i]);
//		cout<<maxsuf<<endl;
		int len=s1.length()-maxpre-maxsuf;
		string S1=s1.substr(maxpre,len),S2=s2.substr(maxpre,len);
//		cout<<s1<<' '<<s2<<endl;
		if(t.find({S1,S2})!=t.end()){
			int ans=0;
			for(auto i:t[{S1,S2}]){
				bool flag=true;
				string a1=i.first,a2=i.second;
				if(a1.length()>maxpre||a2.length()>maxsuf) continue;
				for(int p1=maxpre-1,p2=a1.length()-1;p2!=-1;p1--,p2--){
					if(s1[p1]!=a1[p2]){
						flag=false;
						break;
					}
				}
				if(!flag) break;
				for(int p1=maxpre+len,p2=0;p2!=a2.length();p1++,p2++){
					if(s1[p1]!=a2[p2]){
						flag=false;
						break;
					}
				}
				ans+=flag;
			}
			cout<<ans+1<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
}
