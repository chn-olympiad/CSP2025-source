#include<bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
}t[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i].s1>>t[i].s2;
	}
	while(q--){
		string a1,a2;
		cin>>a1>>a2;
		int answer=0;
		for(int i=1;i<=n;i++){
			for(int l=0;l+t[i].s1.length()<a1.length();l++){
				string cmp=a1.substr(l,l+t[i].s1.length());
				if(cmp==t[i].s1){
					string ans;
					if(l!=0){
						ans=a1.substr(0,l-1)+t[i].s1;
					}else{
						ans=t[i].s1;
					}
					if(l+t[i].s1.length()!=a1.length()-1){
						ans+=a1.substr(l+t[i].s1.length(),a1.length()-1);
					}
					if(ans==a2){
						answer++;
					}					
				}

			}
		}	
		cout<<answer<<endl;
	}
	return 0;
}
