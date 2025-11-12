#include<bits/stdc++.h>
using namespace std;
string s1[100010],s2[100010];
string t1,t2,b1,b2;
long long n,q,s[100010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		long long s11=0,s22=0;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				s11=j;
			}
			if(s2[i][j]=='b'){
				s22=j;
			}
		}
		s[i]=s11-s22;
	}
	
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		long long t11=0,t22=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b'){
				t11=j;
			}
			if(t2[j]=='b'){
				t22=j;
			}
			if(t11!=0&&t22!=0){
				break;
			}
		}
		long long sum=0;
		for(int j=1;j<=n;j++){
			if(s[j]==t11-t22){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 
