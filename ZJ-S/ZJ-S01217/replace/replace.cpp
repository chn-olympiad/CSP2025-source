#include<bits/stdc++.h>
using namespace std;
string s1,s2,a,b;
map<string,map<string,int> >f;
int n,q,l,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		a="";
		b="";
		for(int j=l;j<=r;j++){
			a+=s1[j];
			b+=s2[j];
		}
		f[a][b]++;
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		a="";
		b="";
		for(int j=l;j<=r;j++){
			a+=s1[j];
			b+=s2[j];
		}
		cout<<f[a][b]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 1
aaaaaabaa
baaaaaaaa
babababaaaaaab
babababbaaaaaa
babababaaaaaabababab
babababbaaaaaaababab
aaaaaabbbbbbbabababaaaaaabababab
aaaaaabbbbbbbabababbaaaaaaababab
aaaaaabbbbbbbabababaaaaaababababbbbbbb
aaaaaabbbbbbbabababbaaaaaaabababbbbbbb
*/
