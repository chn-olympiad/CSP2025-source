#include<bits/stdc++.h>
using namespace std;
int n,q;
string s_1[200005],s_2[200005],t_1[200005],t_2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s_1[i]>>s_2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t_1[i]>>t_2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(t_1[i].find(s_1[j])!=-1){
				int lena=t_1[i].find(s_1[j]);
				int lenb=s_1[j].size();
				string t=t_1[i];
				string s=s_2[j];
				int cnt=0;
				for(int k=lena;k<=lena+lenb-1;k++){
					t[k]=s[cnt];
					cnt++;
				}
				if(t==t_2[i]) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
