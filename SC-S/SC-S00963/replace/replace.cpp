#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
int n,q,cnt=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string mid1,mid2;
		cin>>mid1>>mid2;
		mp[mid1]=mid2;
	}
	for(int i=1;i<=q;i++){
		cnt=0;
		string mid1,mid2;
		cin>>mid1>>mid2;
		for(auto out:mp){
			if((int)mid1.find(out.first)!=-1){
				if((int)mid2.find(out.second)!=-1){
					string r="",l="";
					for(int j=0;j<(int)mid1.find(out.first);j++){
						r+=mid1[j];
					}
					for(int j=(int)mid1.find(out.first)+out.first.length();j<(int)mid1.length();j++){
						l+=mid1[j];
					}
					string g=r+out.second+l;
					if(g==mid2)cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}