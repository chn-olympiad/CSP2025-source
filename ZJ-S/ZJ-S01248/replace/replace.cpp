#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200010],s2[200010],q1,q2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>q1>>q2;
		long long s=0;
		if(q1.size()!=q2.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s1[i].size()>q1.size())continue;
			for(int j=0;j<=q1.size()-s1[i].size();j++){
				bool f=0;
				for(int k=0;k<s1[i].size();k++)if(q1[j+k]!=s1[i][k]){
					f=1;
					break;
				} 
				if(f==1)continue;
				for(int k=0;k<q1.size();k++){
					if(k<j||k>=j+s1[i].size()){
						if(q1[k]!=q2[k]){
							f=1;
							break;
						}
					}
					else if(s2[i][k-j]!=q2[k]){
						f=1;
						break;
					}
				}
				if(f==0)s++;
			}
		}
		cout<<s<<endl;
	}
}
