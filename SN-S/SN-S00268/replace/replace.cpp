//考号:SN-S00268  姓名:强小轩  学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
int n,q;
string s1[1005],s2[1005];
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
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		int siz=(int)t1.size();
		int siz_=(int)t2.size();
		if(siz!=siz_){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int sizz=(int)s1[i].size();
			for(int l=0;l+sizz-1<siz;l++){
				int flag=1;
				for(int j=l;j<=l+sizz-1;j++){
					if(s1[i][j-l]!=t1[j]||s2[i][j-l]!=t2[j]){
						flag=0;
					}
				}
				for(int j=0;j<l;j++){
					if(t1[j]!=t2[j])flag=0;
				}
				for(int j=l+sizz;j<siz;j++){
					if(t1[j]!=t2[j])flag=0;
				}
				if(flag){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

































