//20pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define ls rt*2;
#define rs rt*2+1;
const int K1=99920081113;
const int K2=99920081104;
const int M=5e6+10;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
int len[N],l;
int ans;
unsigned int h1[M][3],h2[M][3];
unsigned int H1[M][3],H2[M][3];
string t1,t2;
unsigned int base1[M],base2[M];
void init(){
	base1[0]=1;
	base2[0]=1;
	for(int i=1;i<=M-10;i++){
		base1[i]=base1[i-1]*K1;
		base2[i]=base2[i-1]*K2;
	} 
	return;
}
void Hash1(string s1,string s2){
	s1=' '+s1;
	s2=' '+s2;
	for(int i=1;i<s1.size();i++){
		h1[i][1]=h1[i-1][1]*K1+(s1[i]-'a');
		h1[i][2]=h1[i-1][2]*K2+(s1[i]-'a');
		h2[i][1]=h2[i-1][1]*K1+(s2[i]-'a');
		h2[i][2]=h2[i-1][2]*K2+(s2[i]-'a');
	}
	return;
}
void Hash2(string s1,string s2){
	s1=' '+s1;
	s2=' '+s2;
	for(int i=1;i<s1.size();i++){
		H1[i][1]=H1[i-1][1]*K1+(s1[i]-'a');
		H1[i][2]=H1[i-1][2]*K2+(s1[i]-'a');
		H2[i][1]=H2[i-1][1]*K1+(s2[i]-'a');
		H2[i][2]=H2[i-1][2]*K2+(s2[i]-'a');
	}
	return;
}
int checkl(int i,int l){
	if(H1[len[i]][1]!=h1[len[i]][1]||H1[len[i]][2]!=h1[len[i]][2]){
		return 0;
	}
	if(H2[len[i]][1]!=h2[len[i]][1]||H2[len[i]][2]!=h2[len[i]][2]){
		return 0;
	}
	if(H1[l][1]-H1[len[i]][1]*base1[l-len[i]]!=H2[l][1]-H2[len[i]][1]*base1[l-len[i]]||H1[l][2]-H1[len[i]][2]*base2[l-len[i]]!=H2[l][2]-H2[len[i]][2]*base2[l-len[i]]){
		return 0;
	}
	return 1;
}
int checkr(int i,int l){
	if(H1[l][1]-H1[l-len[i]][1]*base1[len[i]]!=h1[len[i]][1]||H1[l][2]-H1[l-len[i]][2]*base2[len[i]]!=h1[len[i]][2]){
		return 0;
	}
	if(H2[l][1]-H2[l-len[i]][1]*base1[len[i]]!=h2[len[i]][1]||H2[l][2]-H2[l-len[i]][2]*base2[len[i]]!=h2[len[i]][2]){
		return 0;
	}
	if(H1[l-len[i]][1]!=H2[l-len[i]][1]||H1[l-len[i]][2]!=H2[l-len[i]][2]){
		return 0;
	}
	return 1;
}
bool check(int i,int l,int r,int L){
	if(H1[L][1]-H1[r][1]*base1[L-r]!=H2[L][1]-H2[r][1]*base1[L-r]||H1[L][2]-H1[r][2]*base2[L-r]!=H2[L][2]-H2[r][2]*base2[L-r]){
		return 0;
	}
	if(H1[l-1][1]!=H2[l-1][1]||H1[l-1][2]!=H2[l-1][2]){
		return 0;
	}
	if(H1[r][1]-H1[l-1][1]*base1[r-l+1]!=h1[len[i]][1]||H1[r][2]-H1[l-1][2]*base2[r-l+1]!=h1[len[i]][2]){ 
		return 0;
	}
	if(H2[r][1]-H2[l-1][1]*base1[r-l+1]!=h2[len[i]][1]||H2[r][2]-H2[l-1][2]*base2[r-l+1]!=h2[len[i]][2]){
		return 0;
	}
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len[i]=s1[i].size();
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		l=t1.size();
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		Hash2(t1,t2);
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=n;i++){
			Hash1(s1[i],s2[i]);
			for(int j=1;j<=l;j++){
				if(j+len[i]-1>l){
					continue;
				}
				if(j==1){
					ans+=checkl(i,l);
					continue;
				}
				if(j+len[i]==t1.size()){
					ans+=checkr(i,l);
					continue;
				}
				ans+=check(i,j,j+len[i]-1,l);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a	
*/
