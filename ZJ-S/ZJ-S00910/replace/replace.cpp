#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
#define dFor(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
#define MAXN 200005
#define MAXM 5000005
#define endl '\n'
#define P 31
int n,q;
long long Pow[MAXM];
string s1[MAXN],s2[MAXN];
long long ha[MAXM],hb[MAXM];
unordered_map<long long,map<long long,int>> mp;
unordered_map<int,vector<pair<int,int>>> D;
int sum[MAXM];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	Pow[0]=1;
	For(i,1,5000000){
		Pow[i]=Pow[i-1]*P;
	}
	cin>>n>>q;
	bool flagB=1;
	For(i,1,n){
		cin>>s1[i]>>s2[i];
		int m=s1[i].size(),pos1=-1,pos2=-1;
		s1[i]='#'+s1[i];s2[i]='#'+s2[i];
		long long h1=0,h2=0;
		For(j,1,m){
			h1=h1*P+s1[i][j]-'a'+1;
			if(s1[i][j]=='b'){
				if(pos1==-1){
					pos1=j;
				}else{
					flagB=0;
				}
			}
			if(s1[i][j]!='a'&&s1[i][j]!='b'){
				flagB=0;
			}
		}
		For(j,1,m){
			h2=h2*P+s2[i][j]-'a'+1;
			if(s2[i][j]=='b'){
				if(pos2==-1){
					pos2=j;
				}else{
					flagB=0;
				}
			}
			if(s2[i][j]!='a'&&s2[i][j]!='b'){
				flagB=0;
			}
		}
		if(flagB){
			D[pos2-pos1].push_back(make_pair(pos1,m-pos2));
		}
		mp[h1][h2]++;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int len=a.size();
		a='#'+a;b='#'+b;
		if(flagB){
			int pos1=-1,pos2=-1;
			For(i,1,len){
				if(a[i]=='b'){
					pos1=i;
				}
				if(b[i]=='b'){
					pos2=i;
				}
			}
			int dis=pos2-pos1,d1=pos1,d2=len-pos2;
			if(D.find(dis)==D.end()){
				cout<<0<<endl;
				continue;
			}
			int ans=0;
			for(auto p:D[dis]){
				if(p.first<=d1&&p.second<=d2){
					ans++;
				}
			}
			cout<<ans<<endl;
		}else{
			int l=len+1,r=-1;
			For(i,1,len){
				if(a[i]!=b[i]){
					l=min(l,i);
					r=max(r,i);
				}
			}
			For(i,1,len){
				ha[i]=ha[i-1]*P+a[i]-'a'+1;
				hb[i]=hb[i-1]*P+b[i]-'a'+1;
			}
			long long ans=0;
			For(i,1,l){
				For(j,r,len){
					long long ta=ha[j]-ha[i-1]*Pow[j-i+1];
					long long tb=hb[j]-hb[i-1]*Pow[j-i+1];
					if(mp.find(ta)!=mp.end()){
						if(mp[ta].find(tb)!=mp[ta].end()){
							ans+=mp[ta][tb];
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
