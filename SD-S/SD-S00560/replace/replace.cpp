#include<bits/stdc++.h>

using namespace std;

#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long


const int N=2e5+10;//×¢ÒâÐÞ¸Ä
const int mod=998244353;
const int base=91;
string s[N][5];
int n,q;



int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	fst
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s1.size()-s[i][1].size()+1;j++){
			//	cout<<i<<' '<<j<<' '<<s1.substr(j,s[i][1].size())<<endl;
				if(s1.substr(j,s[i][1].size())==s[i][1]){
				//	cout<<i<<' '<<j<<endl;
					int f=0;
					for(int k=0;k<s1.size();k++){
						if(k<j){
							if(s1[k]!=s2[k]) f=1;
						}
						else if(k>=j&&k<=j+s[i][1].size()-1){
							if(s[i][2][k-j]!=s2[k]) f=1;
						}else{
							if(s1[k]!=s2[k]) f=1;
						}
						if(f) break;
					}
					if(!f) {
						res++;
						//cout<<i<<endl;
					}
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

