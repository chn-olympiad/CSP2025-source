#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
struct node {
	string str1,str2;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].str1>>a[i].str2;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string str1,str2;
		cin>>str1>>str2;
		if(str1.size()!=str2.size()){
			cout<<0<<"\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			int pos=0;
			while(str1.find(a[j].str1,pos)!=string::npos){
				pos=str1.find(a[j].str1,pos);
				string newstr;
				for(int k=0;k<str1.size();k++){
					if(k>=pos&&k<=pos+a[j].str1.size()-1) newstr+=a[j].str2[k-pos];
					else newstr+=str1[k];
				}
				pos++;
				if(newstr==str2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
