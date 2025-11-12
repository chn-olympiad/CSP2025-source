#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n,q;
string s1[200010];
string s2[200010];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++){
		int cnt=0;
		cin>>t1>>t2;
		for(int j=1;j<=n;j++){
			if(t1.find(s1[j])!=string::npos){
				t1.replace(t1.find(s1[j]),s1[j].size(),s2[j]);
				if(t1==t2)cnt++;
				t1.replace(t1.find(s2[j]),s2[j].size(),s1[j]);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
