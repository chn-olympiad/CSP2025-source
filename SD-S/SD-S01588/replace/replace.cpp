#include<bits/stdc++.h>
using namespace std;
#define int long long
int lst[1000005];
int lst1[1000005];
string s1[2000005];
string s2[2000005];
int f[1000005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i1=1;i1<=n;i1++){
			int j=-1; 
			for(int i=0;i<s1[i1].length();i++){
				lst[i]=-1;
				f[i]=0;
			}
			for(int i=1;i<s1[i].length();i++){
				while(s1[i1][j+1]!=s1[i1][i] and j!=-1){
					j=lst[j];
				}
				if(s1[i1][j+1]==s1[i1][i]){
					j++;
					lst[i]=j;
				}
			}
			j=-1;
			for(int i=0;i<s2[i1].length();i++){
				lst1[i]=-1;
				f[i]=0;
			}
			for(int i=1;i<s2[i1].length();i++){
				while(s2[i1][j+1]!=s2[i1][i] and j!=-1){
					j=lst1[j];
				}
				if(s2[i1][j+1]==s2[i1][i]){
					j++;
					lst1[i]=j;
				}
			}
			j=-1;
			vector<int>k1;
			vector<int>k2;
			for(int i=0;i<t1.length();i++){
				while(s1[i1][j+1]!=t1[i] and j!=-1){
					j=lst[j];
				}
				if(s1[i1][j+1]==t1[i]){
					j++;
					if(j==s1[i1].length()-1){
						k1.push_back(i-j);
					}
				}
			}
			j=-1;
			for(int i=0;i<t2.length();i++){
				while(s2[i1][j+1]!=t2[i] and j!=-1){
					j=lst1[j];
				}
				if(s2[i1][j+1]==t2[i]){
					j++;
					if(j==s2[i1].length()-1){
						k2.push_back(i-j);
					}
				}
			}
			for(int i=0;i<k1.size();i++){
				f[k1[i]]++;
			}
			for(int i=0;i<k2.size();i++){
				if(f[k2[i]]){
					string l=t1;
					for(int k=k2[i];k<=k2[i]+s1[i1].length()-1;k++){
						l[k]=s2[i1][k-k2[i]];
					}
					if(l==t2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

