#include<bits/stdc++.h>
using namespace std;

string s1[200010],s2[200010];
int n,q;

void cal1(string l,string r){
	int cnt=0;
	for(int i=1;i<=n;i++){
		int f=0,pos;
		for(int j=0;j+s1[i].size()-1<l.size();j++){
			string s=l.substr(j,s1[i].size());
			if(s==s1[i]){
				f=1;
				pos=j;
				break;
			}
		}
		if(!f) continue;
		string x=l.substr(0,pos),z=l.substr(pos+s1[i].size());
		string y=x+s2[i]+z;
		if(y==r) cnt++;
	}
	cout<<cnt<<endl;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string l,r;
		cin>>l>>r;
		if(n<=100 || q==1){
			cal1(l,r);
		} 
	}
	return 0;
}
