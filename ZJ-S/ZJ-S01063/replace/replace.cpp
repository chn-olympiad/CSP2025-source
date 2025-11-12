#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200010],s2[200010],t1,t2,tt1[5000100],tt2[5000100];
void solve(){
	int m=t1.size();
	int l=0,r=m-1;
	for(int i=0;i<m;i++){
		if(t1[i]!=t2[i]){
			r=i;
		}
	}
	for(int i=m-1;i>=0;i--){
		if(t1[i]!=t2[i]){
			l=i;
		}
	}
	for(int i=1;i<=n;i++){
		int x=t1.find(s1[i]);
		int y=t2.find(s2[i]);
		if(x==-1||x!=y){
			continue;
		}
		int z=s1[i].size();
		y=x+z-1;
		if(l>=x&&r<=y){
			ans++;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;ans=0;
		solve();
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

