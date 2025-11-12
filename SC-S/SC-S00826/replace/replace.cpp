#include<bits/stdc++.h>
using namespace std;
int n,q,mx;
struct ac{
	string s1,s2;
}a[1000001];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s1.size()<a[i].s1.size()) continue;
			for(int j=0;j<s1.size()-a[i].s1.size()+1;j++){
				string s3=s1.substr(j,a[i].s1.size());
				if(s3==a[i].s1){
					string s4=s1.substr(0,j)/**/+a[i].s2+s1.substr(j+a[i].s1.size(),s1.size()-j-a[i].s1.size()+1);
					if(s4==s2) mx++;
				}
			}
		}
		cout<<mx<<"\n";
		mx=0;
	}
}