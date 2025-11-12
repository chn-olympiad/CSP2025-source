#include<bits/stdc++.h>
#define N 200010
using namespace std;
string s1[N],s2[N];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int t=t1.find(s1[i]);
			if(t==-1) continue;
			int l1=t1.length();
			int l2=s1[i].length();
			bool flag=1;
			for(int j=0;j<t;j++){
				if(t1[j]!=t2[j]) flag=0;
			}
			for(int j=t+l2;j<l1;j++){
				if(t1[j]!=t2[j]) flag=0;
			}
			for(int j=t;j<t+l2;j++){
				if(s2[i][j-t]!=t2[j]) flag=0;
			}
			if(flag) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}