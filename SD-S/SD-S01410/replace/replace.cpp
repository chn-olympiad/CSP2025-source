#include<bits/stdc++.h> 
using namespace std;
int n,q,ans;
string s1[1005],s2[1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		char x,y;
		int w,z;
		for(int i=0;i<t1.size();i++){
			if(t1[i+1]!=t1[i]&&t1[i+2]!=t1[i]){
				x=t1[i];
				w=i;
			}
			if(t2[i+1]!=t2[i]&&t2[i+2]!=t2[i]){
				y=t2[i];
				z=i;
			}
		}
		for(int i=1;i<=n;i++){
			int r=s1[i].find(x);
			if(s1[i][r]==x){
				int t=s2[i].find(y);
				if(s2[i][t]==y){
					if(z-w==t-r) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
