#include<bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
string s1[200005],s2[200005],t1[200005],t2[200005],lin,x,io;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int t=1;t<=q;t++){
		ans=0;
		x="";
		for(int i=0;i<int(t1[t].size());i++){
			lin="";
			for(int j=i;j<int(t1[t].size());j++){
				lin+=t1[t][j];
				for(int k=1;k<=n;k++){
					if(lin==s1[k]){
						io=x+s2[k];
						for(int op=j+1;op<int(t1[t].size());op++){
							io+=t1[t][op];
						}
						if(io==t2[t]){
							ans++;
						}
					}
				}
			}
			x+=t1[t][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}