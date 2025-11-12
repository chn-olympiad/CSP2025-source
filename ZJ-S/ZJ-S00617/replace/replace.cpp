#include<bits/stdc++.h>
using namespace std;
int n,q,t,bs1[200010],bs2[200010],bt1,bt2;
string s1[200010],s2[200010],t1,t2,s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b')bs1[i]=j;
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b')bs2[i]=j;
		}
	}
	for(int i=0;i<t1.size();i++){
		if(t1[i]=='b')bt1=i;
	}
	for(int i=0;i<t2.size();i++){
		if(t2[i]=='b')bt2=i;
	}
	for(int i=1;i<=n;i++){
		if(bt1>=bs1[i]){
			if((bt2-bt1)==(bs2[i]-bs1[i])){
				t++;
			}
		}
	}
	cout<<t;
	return 0;
}
