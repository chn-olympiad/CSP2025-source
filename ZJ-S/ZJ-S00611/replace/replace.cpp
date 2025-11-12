#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
		}else{
			int cnt=0;
			for(int i=1;i<=n;i++){
				int id=t1.find(s1[i]);
				if(id==-1) continue;
				string x=t1.substr(0,id),y=s2[i],z=t1.substr(id+s1[i].size());
				string s1=x+y+z;
				if(s1==t2) cnt++;
			}
			cout<<cnt<<endl;//¸Ð¾õÒª·Ï  
		}
	}
	return 0;
}

