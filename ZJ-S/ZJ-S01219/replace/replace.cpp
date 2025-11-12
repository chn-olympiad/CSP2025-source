#include<bits/stdc++.h>
using namespace std;
int n,t;
string s1[500005],s2[500005];
struct node{
	int first,second,aa,zz;
};
node q[500005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("reolace.out","w",stdout);
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		int l1=0,r1=0,l2=0,r2=0;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				l1=j;r1=s1[i].size()-j-1;
			}
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
			l2=j;
			r2=s2[i].size()-j-1; 
		}
		}
		q[i].first=l1-l2,q[i].second=r1-r2;
		q[i].aa=l1,q[i].zz=r1;
	}
	int t;
	cin>>t;
	while(t--){
		int ans=0;
		string s3,s4;
		cin>>s3>>s4;
		int l1=0,r1=0,l2=0,r2=0;
		for(int i=0;i<s3.size();i++){
			if(s3[i]=='b'){
				l1=i;r1=s3.size()-i-1;
			}
		}
		for(int i=0;i<s4.size();i++){
			if(s4[i]=='b'){
			l2=i;
			r2=s4.size()-i-1; 
		}
		}
		for(int i=0;i<n;i++){
			if(l1-l2==q[i].first&&r1-r2==q[i].second&&l1>=q[i].aa&&r1>=q[i].zz)ans++;

		}
					cout<<ans<<endl;
	}
	
	return 0;
}
