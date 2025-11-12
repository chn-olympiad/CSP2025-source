#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
string t1,t2;
string k1,k2;
map<string,string> mp;
map<pair<string,string>,int> mp2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
		for(int j=0;j<s1.size();j++){
			if(s1[j]==s2[j]){
				s1.erase(j,1);
				s2.erase(j,1);
				j--;
			}
		}
		mp2[{s1,s2}]++;
	}
	while(m--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int nn=t1.size();
		int cnt=0;
		if(nn<=2000){	
			for(int i=0;i<nn;i++){
				string k;
				for(int j=1;j<=nn-i;j++){
					k+=t1[i+j-1];
					if(mp.count(k)){
						string s=mp[k];
						int ans=0;
						string x=t1;
						for(int c=i;c<=i+j-1;c++){
							x[c]=s[ans];
							ans++;
						}
						if(x==t2)cnt++;
					}
				}
			}
			cout<<cnt<<"\n";
			continue;			
		}
		int b1=0,b2=0;
		for(int i=0;i<nn;i++){
			if(t1[i]=='b')b1++;
			if(t2[i]=='b')b2++;
		}
		if(b1==1 && b2==1){
			int bzt1=0,bzt2=0;
			for(int i=0;i<nn;i++){
				if(t1[i]=='b')bzt1=i;
				if(t2[i]=='b')bzt2=i;
				if(bzt1!=0 && bzt2!=0)break;
			}
			for(auto x:mp){
				string u=x.first;
				string v=x.second;
				int bz1=0,bz2=0;
				for(int i=0;i<u.size();i++){
					if(u[i]=='b')bz1=i;
					if(v[i]=='b')bz2=i;
					if(bz1!=0 && bz2!=0)break;
				}
				if(bz1<=bzt1 && bz2-bz1==bzt2-bzt1)cnt++;
			}
			cout<<cnt<<"\n";
			continue;
		}
		else{
			bool flag=true;
			bool fg=true;
			k1="";
			k2="";
			for(int i=0;i<nn;i++){
				if(t1[i]!=t2[i]){
					if(flag==false && t1[i-1]==t2[i-1]){
						fg=false;
						break;
					}
					flag=false;
					k1+=t1[i];
					k2+=t2[i];
				}
			}
			if(fg==false){
				cout<<0<<"\n";
				continue;
			}
			cout<<mp2[{k1,k2}]<<"\n";		
		}
	}
	return 0;
}