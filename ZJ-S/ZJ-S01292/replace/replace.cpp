#include<bits/stdc++.h>
using namespace std;
int n,q,AC;
string s1[200005],s2[200005],q1,q2;
bool flag=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
		int l1=q1.size();
		if(q1.size()!=q2.size()){
			cout<<0;
			continue;
		}
		AC=0;
		for(int j=1;j<=n;j++){
			int l2=s1[j].size();
			for(int k=0;k<=l1-l2;k++){
				flag=1;
				for(int p=0;p<l1;p++){
					if(k<=p&&p<=k+l2-1){
						if(q1[p]!=s1[j][p-k]||q2[p]!=s2[j][p-k]){
							flag=0;
							break;
						}
					}
					else if(q1[p]!=q2[p]){
						flag=0;
						break;
					}
				}
				if(flag) AC++;
			}
		}
		cout<<AC<<"\n";
	}
	return 0;
}
