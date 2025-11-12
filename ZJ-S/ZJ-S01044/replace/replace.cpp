#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	string s,s1;
	int ls;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].s1;
		a[i].ls=a[i].s.size();
	}
	while(m--){
		string str,str1,ste="";
		cin>>str>>str1;
		int lstr=str.size(),ans=0;;
		for(int i=0;i<lstr;i++){
			for(int j=1;j<=n;j++){
				if(a[j].s[0]==str[i] and lstr-i+1>a[j].ls){
					int ok=1;
					for(int k=1;k<a[j].ls;k++){
						if(a[j].s[k]!=str[i+k]){
							ok=0;
							break;
						}
					}
					string sum=ste+a[j].s1;
					for(int k=a[j].ls+i;k<lstr;k++) sum+=str[k];
					if(ok and sum==str1) ans++;
				}
			}
			ste+=str[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
