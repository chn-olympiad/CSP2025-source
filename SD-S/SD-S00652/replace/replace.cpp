#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=2e5+5;
string s[N][2];
int n,Q;
long long ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(Q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		t1="0"+t1;t2="0"+t2;
		int dl=len+1,dr=0;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i])
				dl=min(dl,i),dr=max(dr,i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j+s[i][0].size()-1<=len;j++){
				if((j>dl)||(s[i][0].size()-1+j<dr))continue;
				bool ok=0;
				for(int p=0;p<s[i][0].size();p++){
					if(s[i][1][p]!=t2[j+p]){
						ok=1;
						break;
					}
					if(t1[j+p]!=s[i][0][p]){
						ok=1;
						break;
					}
				}
				if(ok)continue;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
