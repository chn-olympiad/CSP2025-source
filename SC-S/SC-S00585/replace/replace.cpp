#include<bits/stdc++.h>
using namespace std;
string s[200010][2];
int len[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].size();
	}
	
	while(q--){
		int cnt=0;
		string t1,t2,t3;
		cin>>t1>>t2;
		t3=t1;
		int len1=t1.size();
		int len2=t2.size();
		if(len1!=len2){
			cout<<0<<"\n";
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=0;j<len1;j++){
				string temp1=t1.substr(j,len[i]);
				string l=t1.substr(0,j);
				string r;
				if(j+len[i]>len1) r="";
				else r=t1.substr(j+len[i],len1-j-len[i]);
				if(temp1==s[i][0]){
					t1=l+s[i][1]+r;
				}
				
				if(t1==t2){
					cnt++;
				}
				t1=t3;
			}
		}
		
		cout<<cnt<<"\n";
	}
    return 0;
}