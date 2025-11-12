#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
string s[N],s2[N];
int n,q;
vector<int>v[30];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
		v[s[i][0]-'a'].push_back(i);
//		cout<<s[i][0]-'a'<<'\n'; 
	}
	while(q--){
		string qu,a,w,ls;
		string ts;
		int ans=0;
		cin>>qu>>a;

		if(qu.size()!=a.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i]==qu){
				if(s2[i]==a){
					ans++;
				}
			}
		}
		for(int sw=0;sw<qu.size();sw++){
			
			if(qu[sw]!=a[sw]){
				char cha=qu[sw];
				int ch=cha-'a';
//				if(v[ch].size()==0){
//					cout<<sw<<'\n';
//					ans=1;
//					break;
//				}
				for(int i=0;i<v[ch].size();i++){
					ls=w;
					int id=v[ch][i];
					for(int j=0;j<s[id].size();j++){
						if(qu[sw+j]==s[id][j]){
							ls+=s2[id][j];
						}
						
					}
					for(int j=s[id].size()+sw;j<qu.size();j++){
						ls+=qu[j];
					}
//					cout<<ls<<" "<<a<<'\n';
					bool pd;
					if(ls==a){
//						cout<<1;
						ans++;
					}
				}
			}
			else{
				w+=qu[sw];
			}
			
		}
		cout<<ans<<'\n';
		
	}
	
	
	return 0;
	}
