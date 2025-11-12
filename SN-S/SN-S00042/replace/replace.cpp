#include<bits/stdc++.h>
using namespace std;
int n,k;
string s[200010];
map<string,string>mp; 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		string s2;
		cin>>s[i]>>s2;
		mp[s[i]]=s2; 
	}
	for(int i=1;i<=k;i++){
		string s1,s3,s4;
		cin>>s1>>s3;
		
		int ans=0;
		int r=s1.size();
		for(int j=1;j<=n;j++){
			s4=s1;
			int g=s[j].size();
			int l=0,f=0;
			//if(j==3)cout<<" "<<f<<" ";
//			cout<<s4.find(s[j])<<" "<<s4<<" "<<s[j]<<"\n";
			if(s4.find(s[j])<r){
				l=s4.find(s[j]);
//				cout<<s4<<s[j];
			}else continue;
			
			for(int h=0;h<r;h++){
				if(h>=l&&h<=l+g-1){
					s4[h]=mp[s[j]][h-l];
					
				}
				if(s4[h]!=s3[h]){
						f=1;
//						cout<<" dd"<<i<<"dd";
						break;
					}
			}
			
			if(f==0){
				ans++;
			}
			
		}cout<<ans<<"\n";
	}
//	string x="xabcx",y="bc";
//	cout<<x.find(y);
	return 0;
} 

