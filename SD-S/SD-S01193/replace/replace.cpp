#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,q,s,e,l[N][4];
vector <string> s1,s2;
string str1,str2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;i<s1[i].length();j++){
			if(s1[j]!=s2[j]){
				s=j;
				while(j<s1[i].length()){
					if(s1[j]!=s2[j]){
						e=j;
					}
					j++;
				}
				break;
			}
		}
		l[i][0]=s;
		l[i][1]=e;
		l[i][2]=e-s+1;
		l[i][3]=s1[i].length();
	}
	while(q--){
		cin>>str1>>str2;
		if(str1.length()!=str2.length()){
			cout<<0<<endl;
			continue;
		}
		int ls=str1.length(),fl;
		for(int i=0;i<ls;i++){
			if(str1[i]!=str2[i]){
				s=i;
				while(i<ls){
					if(str1[i]!=str2[i]){
						e=i;
					}
					i++;
				}
				break;
			}
		}
		fl=e-s+1;
		int ans=0;
		for(int i=0;i<n;i++){
			bool f=0;
			if(l[i][2]!=fl){
				continue;
			}
			for(int j=0;j<l[i][0];j++){
				if(str1[j+s-l[i][0]]!=s1[j]){
					f=1;
					break;
				}
			}
			if(f){
				continue;
			}
			for(int j=l[i][0];j<=l[i][1];j++){
				if(str1[j+s-l[i][0]]!=s1[j]||str[j+s-l[i][0]]!=s2[j]){
					f=1;
					break;
				}
			}
			if(f){
				continue;
			}
			for(int j=l[i][1]+1;j<l[i][3];j++){
				if(str1[j+s-l[i][0]]!=s1[j]){
					f=1;
					break;
				}
			}
			if(f){
				continue;
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

