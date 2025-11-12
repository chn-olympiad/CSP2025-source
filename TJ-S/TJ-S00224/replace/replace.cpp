#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200001][3],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>s1>>s2;
		for(int j=1;j<=n;j++){
			string s3=s1;
			unsigned long long ind=s3.find(s[j][1]),ind2=s2.find(s[j][2]);
			while(ind<5000001&&ind2<5000001){
				if(ind==ind2&&s3.substr(0,ind)==s2.substr(0,ind2)&&s3.substr(ind+s[j][1].size(),s1.size()-ind-s[j][1].size()+1)==s2.substr(ind2+s[j][2].size(),s1.size()-ind2-s[j][2].size()+1))ans++;
				s3[ind]=' ';
				ind=s3.find(s[j][1]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
