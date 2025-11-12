#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][3];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--){
		ans=0;
		cin>>t1>>t2;
		string t3,t4,t5="",t6;
		for(int i=0;i<t1.length();i++){
			t3="";t5+=t1[i];
			for(int j=i;j<t1.length();j++){
				t3+=t1[j];
				for(int k=1;k<=n;k++){
					if(t3==s[k][1]){
						t6=t5+s[k][2];
						for(int kk=j+1;kk<t1.length();kk++){
							t6+=t1[kk];
						}
						if(t6==t2){
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";		
	}
	return 0;
}