#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(m--){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=0;i<a.size();i++){
			for(int j=i;j<a.size();j++){
				string tmp;
				for(int k=i;k<=j;k++){
					tmp+=a[k];
				}
				for(int k=1;k<=n;k++){
					if(tmp==s1[k]){
						tmp=s2[k];
					}
				}
				string nw;
				for(int k=0;k<i;k++){
					nw+=a[k];
				}
				nw+=tmp;
				for(int k=j+1;k<a.size();k++){
					nw+=a[k];
				}
				if(nw==b){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a