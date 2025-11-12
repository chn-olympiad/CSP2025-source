#include<bits/stdc++.h>
using namespace std;
#define maxn 214514
string s1[maxn],s2[maxn];
int lb1[maxn],lb2[maxn];
string t1,t2;
int n,q;
int main(){
	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b')lb1[i]=j;
			if(s2[i][j]=='b')lb2[i]=j;
		}
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int len=t1.size();
		int b1,b2;
		for(int i=0;i<len;i++){
			if(t1[i]=='b')b1=i;
			if(t2[i]=='b')b2=i;
		}
		for(int i=1;i<=n;i++){
			if(lb1[i]<=b1&&s1[i].size()-lb1[i]<=t1.size()-b1&&b1-b2==lb1[i]-lb2[i]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
