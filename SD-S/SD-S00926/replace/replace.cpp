#include<bits/stdc++.h>
#define ull unsigned long long
#define debug cout<<"debug"<<endl;
#define endl '\n'
#define debug_endl cout<<endl;
//#define i128 __int128
//#define MOD (1000000007)
//#define eps (1e-6)
using namespace std;
int base1=131;
int base2=1331;
ull p1[1010],p2[1010];
int n,q,len[1010][2];
ull hash1[1010][2],hash2[1010][2];
string s,t,tmp;
int check(int idx,int p){
	ull h11=0,h12=0,h21=0,h22=0;
	for(int i=0;i<len[idx][0];++i){
		h11=base1*h11+(s[i]-'a'+1);
		h12=base2*h12+(s[i]-'a'+1);
		h21=base1*h21+(t[i]-'a'+1);
		h22=base2*h22+(t[i]-'a'+1);
	}
	int l=len[idx][0];
	for(int i=l;i<s.size();++i){
		if(h11==hash1[idx][0]&&h12==hash2[idx][0]&&h21==hash1[idx][1]&&h22==hash2[idx][1]&&i-1>=p){
			return 1;
		}
		h11=(h11-p1[l-1]*(s[i-l]-'a'+1))*base1+(s[i]-'a'+1);
		h12=(h12-p2[l-1]*(s[i-l]-'a'+1))*base2+(s[i]-'a'+1);
		h21=(h21-p1[l-1]*(t[i-l]-'a'+1))*base1+(t[i]-'a'+1);
		h22=(h22-p2[l-1]*(t[i-l]-'a'+1))*base2+(t[i]-'a'+1);
	}
	if(h11==hash1[idx][0]&&h12==hash2[idx][0]&&h21==hash1[idx][1]&&h22==hash2[idx][1]&&s.size()-1>=p){
		return 1;
	}
	return 0;
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	p1[0]=p2[0]=1;
	for(int i=1;i<=1000;++i){
		p1[i]=p1[i-1]*base1;
		p2[i]=p2[i-1]*base2;
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j){
			cin>>tmp;
			len[i][j]=tmp.size();
			for(int k=0;k<tmp.size();++k){
				hash1[i][j]=base1*hash1[i][j]+(tmp[k]-'a'+1);
				hash2[i][j]=base2*hash2[i][j]+(tmp[k]-'a'+1);
			}
		}
	}
	for(int i=1;i<=q;++i){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		bool r=true;
		int lst=-1,l=-1;
		for(int j=0;j<s.size();++j){
			if(s[j]!=t[j]){
				if(l==-1){
					l=j;
				}
				if(lst!=-1&&j!=lst+1){
					r=false;
					break;
				}
				lst=j;
			}
		}
		if(!r){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;++j){
			if(len[j][0]>=lst-l+1){
				ans+=check(j,lst);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

