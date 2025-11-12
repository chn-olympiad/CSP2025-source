#include<iostream>
#include<string>
using namespace std;
string s[10005][3];
int n,q; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int sum=0;
		for(int i=0;i<=s1.size()-1;i++){
			for(int k=1;k<=n;k++){
				bool bb=0;
				for(int j=0;j<=s[k][1].size()-1;j++)if(s[k][1][j]!=s1[j+i])bb=1;
				if(s[k][1].size()<=s1.size()-i&&bb==0){
					string s3=s1;
					for(int j=0;j<=s[k][1].size()-1;j++)s3[i+j]=s[k][2][j];
					if(s3==s2)sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
