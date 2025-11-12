#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
template <typename T> void getmin(T &a,T b){
	if(b<a) a=b;
	return;
}
template <typename T> void getmax(T &a,T b){
	if(b>a) a=b;
	return;
}
int n,T;
int m;
int t[5000005][27];
int fail[5000005];
int sum[5000005];
int R[200005];
void insert(string s,int rt){
	int p=rt;
	for(int i=0;i<s.size();++i){
		int x;
		if(s[i]=='*') x=0;
		else x=s[i]-'a'+1;
		if(!t[p][x]) t[p][x]=++m;
		p=t[p][x];
	}
	++sum[p];
//	cout<<"insert:"<<s<<" "<<rt<<" "<<p<<" "<<sum[p]<<endl;
	return;
}
queue <int> q;
void build(int rt){
	while(!q.empty()) q.pop();
	fail[rt]=0;
	for(int i=0;i<=26;++i){
		if(t[rt][i]){
			q.push(t[rt][i]);
			fail[t[rt][i]]=rt;
		}
		else t[rt][i]=rt;
	}
	while(!q.empty()){
		int p=q.front();
//		cout<<"build:"<<p<<endl;
		q.pop();
		sum[p]+=sum[fail[p]];
		for(int i=0;i<=26;++i){
			if(t[p][i]){
				fail[t[p][i]]=t[fail[p]][i];
				q.push(t[p][i]);
			}
			else{
				t[p][i]=t[fail[p]][i];
			}
		}
	}
	return;
}
int query(string s,int rt){
//	cout<<"query:"<<s<<" "<<rt<<endl;
	int p=rt,res=0;
	for(int i=0;i<s.size();++i){
		int x;
		if(s[i]=='*') x=0;
		else x=s[i]-'a'+1;
		p=t[p][x];
		res+=sum[p];
//		cout<<p<<" ";
	}
//	cout<<res<<endl;
	return res;
}
//const ll MOD=20071027,P=131;
//unordered_map <ll,int> mp;
map <string,int> mp;
int cnt;
string s1,s2;
int ans;
int main(){
//	system("fc replace4.out replace4.ans");return 0;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;++i){
		cin>>s1>>s2;
		int l=0,r=0;
		for(int i=0;i<s1.size();++i){
			if(s1[i]!=s2[i]){
				l=i-1;
				break;
			}
		}
		for(int i=(int)s1.size()-1;i>=0;--i){
			if(s1[i]!=s2[i]){
				r=i+1;
				break;
			}
		}
//		ll ha=0;
//		for(int i=l+1;i<=r-1;++i){
//			ha=(ha*P+s1[i])%MOD;
//			ha=(ha*P+s2[i])%MOD;
//		}
//		if(mp[ha]==0){
//			mp[ha]=++cnt;
//			R[cnt]=++m;
//		}
//		int id=mp[ha];
		string str="";
		for(int i=l+1;i<=r-1;++i){
			str+=s1[i];
			str+=s2[i];
		}
		if(mp[str]==0){
			mp[str]=++cnt;
			R[cnt]=++m;
		}
		int id=mp[str];
		str="";
		for(int i=0;i<=l;++i) str+=s1[i];
		str+="*";
		for(int i=r;i<s1.size();++i) str+=s1[i];
		insert(str,R[id]);
//		cout<<i<<":"<<ha<<" "<<id<<":"<<str<<endl;
	}
	for(int i=1;i<=cnt;++i){
		build(R[i]);
//		cout<<"R:"<<i<<":"<<R[i]<<endl;
	}
	for(int i=1;i<=m;++i){
//		cout<<"sum:"<<i<<":"<<sum[i]<<" "<<fail[i]<<endl;
//		for(int j=0;j<=26;++j){
//			if(t[i][j]==0) continue;
//			cout<<i<<" "<<j<<" ";
//			if(j==0) cout<<"* ";
//			else cout<<char(j+'a'-1)<<" ";
//			cout<<t[i][j]<<endl;
//		}
	}
//	T=100;
	while(T--){
		cin>>s1>>s2;
		int l=0,r=0;
		for(int i=0;i<s1.size();++i){
			if(s1[i]!=s2[i]){
				l=i-1;
				break;
			}
		}
		for(int i=(int)s1.size()-1;i>=0;--i){
			if(s1[i]!=s2[i]){
				r=i+1;
				break;
			}
		}
//		ll ha=0;
//		for(int i=l+1;i<=r-1;++i){
//			ha=(ha*P+s1[i])%MOD;
//			ha=(ha*P+s2[i])%MOD;
//		}
//		int id=mp[ha];
		string str="";
		for(int i=l+1;i<=r-1;++i){
			str+=s1[i];
			str+=s2[i];
		}
		int id=mp[str];
		str="";
		for(int i=0;i<=l;++i) str+=s1[i];
		str+="*";
		for(int i=r;i<s1.size();++i) str+=s1[i];
//		cout<<T<<":"<<ha<<" "<<id<<" "<<str<<endl;
		if(id==0) ans=0;
		else ans=query(str,R[id]);
		cout<<ans<<endl;
	}
	
	return 0;
}
/*
*
b*
b*c
e*c
ab*cd



*/