#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,q,p[N],pre[N],lst[N];
ll ans,qp[2005];
string s1[N],s2[N],t1,t2,s,ss,kong;
map<pair<int,int>,int> mp; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(n<=100){
		while(q--){
			cin>>t1>>t2;
			ans=0;
			int len=t1.size();
			for(int i=1;i<=n;i++){
				int len1=s1[i].size();
				for(int j=0;j+len1-1<len;j++){
					s=kong;
					ss=t1;
					for(int k=j;k<=j+len1-1;k++){
						s+=t1[k];
						ss[k]=s2[i][k-j];
					}
					if(s==s1[i]&&ss==t2){
						ans++;
					}
				}				
			}
			cout<<ans<<"\n";
		}		
	}
	else {
		for(int i=1;i<=n;i++){
			int p1=0,p2=0;
			for(int j=0;j<s1[i].size();j++){
				if(s1[i][j]=='b'){
					p1=j;
					break;
				}
			}
			for(int j=0;j<s2[i].size();j++){
				if(s2[i][j]=='b'){
					p2=j;
					break;
				}
			}
			p[i]=p1-p2;
			pre[i]=p1;
			lst[i]=s1[i].size()-p2-1;
		}
		while(q--){
			cin>>t1>>t2;
			ans=0;
			int len=t1.size();
			int p1=0,p2=0;
			for(int i=0;i<len;i++){
				if(t1[i]=='b'){
					p1=i;
					break;
				}
			}
			for(int i=0;i<len;i++){
				if(t2[i]=='b'){
					p2=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(p1>=pre[i]&&p[i]==p1-p2&&len-p2-1>=lst[i]){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
