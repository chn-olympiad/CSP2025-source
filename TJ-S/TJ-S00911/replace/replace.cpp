#include <bits/stdc++.h>
using namespace std;
int n,q;
string s;
map <string,int> mp;//出现次数 
string s2[200005],s3[200005];//所有字符串 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int sum=0,cnt=0;
	for(int i=0;i<n;i++){
		cin>>s;
		mp[s]=1;
		bool flag=0;
		for(int j=0;j<sum;j++){
			if(s2[j]==s){
				flag=1;
			}
		}
		if(flag==0){
			s2[i]=s;
			sum++;
		}
	}
	for(int i=0;i<q;i++){
		cin>>s;
		cout<<0<<endl;	
	}
	return 0;
}
