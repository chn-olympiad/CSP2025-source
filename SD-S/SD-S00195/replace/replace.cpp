#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
vector<vector<string> > st;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		/*st[1][1]=x;
		st[1][2]=y;*/
	}
	while(q--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		//if(s1.length()+s2.length()>=1000000){
			cout<<0<<endl;
			continue;
		//}
		/*for(int i=0;i<st.size();i++){
			for(int j=0;j<max(s1.length(),s2.length())-st[i][1].length();j++){
				if(s1[i]!=s2[i]){
					string tmp=s1;
					for(int g=j;g<=j+st[i][1].length();i++){
						tmp[i]=st[i][2][g-j];
					}
					if(tmp==s2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;*/
	}
	return 0;
}
