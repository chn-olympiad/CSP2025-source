#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string>mp1;
unordered_map<string,bool>mp2;
unordered_map<string,bool>mp3;
string g(string s){
	if(mp3[s]==true)return "";
	if(mp2[s]==true){
		mp3[s]=true;
		return mp1[s];
	}
	return s;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	string t1,t2;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2;
		mp1[t1]=t2;
		mp2[t1]=true;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		if(mp1[t1]==t2)ans++;
		for(int i=0;(size_t)i<t1.length()-1;i++){
			if(g(t1.substr(0,i+1))==t2.substr(0,i+1)&&g(t1.substr(i+1,t1.length()))==t2.substr(i+1,t2.length()))ans++;
		}
		mp3.clear();
		for(int i=0;(size_t)i<t1.length()-2;i++){
			for(int j=i+1;(size_t)j<t1.length()-1;j++){
				if(g(t1.substr(0,i+1))==t2.substr(0,i+1)&&g(t1.substr(i+1,j-i))==t2.substr(i+1,j-i)&&g(t1.substr(j+1,t1.length()))==t2.substr(j+1,t2.length()))ans++;
			}
		}
		mp3.clear();
		cout<<ans<<endl;
	}
	return 0;
}
