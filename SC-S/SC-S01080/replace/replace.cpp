#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1[100050],s2[100005],e,w;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>e>>w;
		long long sum=0;
		for(int i=0;i<e.size();i++){
			for(int j=1;j<e.size()-i+1;j++){
				string tt=e.substr(i,j);
				for(int op=1;op<=n;op++){
					if(tt==s1[op]){
						string ui=e;
						ui.replace(i,j,s2[op]);
						if(ui==w){
							sum++;
						}
						
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
