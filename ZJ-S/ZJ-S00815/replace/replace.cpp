#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[1010],s2[1010],t1,t2;
int a[210];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		long long ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			cnt=0;
			int k=0;
			for(int j=0;j<t1.size();j++){
				bool flag=1;
				for(int k=0;k<s1[i].size();k++){
					if(t1[j+k]!=s1[i][k]){
						flag=0;
						break;
					}
				}
				if(flag) a[++cnt]=j;
			}
			for(int j=1;j<=cnt;j++){			
				string tt=t1;
				for(int k=a[j];k<=a[j]+s1[i].size()-1;k++){
					tt[k]=s2[i][k-a[j]];
				}
				if(tt==t2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
