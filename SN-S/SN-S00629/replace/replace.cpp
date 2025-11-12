#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unordered_map<string,int> mp;
int n,q;
bool A;
bool B;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;B=true;
	mp[""]=true;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='a'||s[i][0][j]=='b'){}
			else B=false;
		}
		for(int j=0;j<s[i][1].size();j++){
			if(s[i][1][j]=='a'||s[i][1][j]=='b'){}
			else B=false;
		}
		mp[s[i][0]+s[i][1]]++;
	}
	if(q==1)A=true;
	while(q--){
		string x,y;cin>>x>>y;
		int m=x.size(),r;
		for(int i=m;i>=0;i--){
			if(i!=m&&x[i]!=y[i])break;
			r=i;
		}
		int cnt=0;
		for(int l=-1;l<m;l++){
			if(l!=-1&&x[l]!=y[l])break;
			string a,b;
			for(int i=l+1;i<r;i++){
				a+=x[i];b+=y[i];
			}
			cnt+=mp[a+b];
			for(int i=max(l+1,r-1)+1;i<m;i++){
				if(i==r-1)continue;
				a+=x[i],b+=y[i];
				cnt+=mp[a+b];
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
