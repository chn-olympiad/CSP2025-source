#include<bits/stdc++.h>
using namespace std;
string a[100010];
string b[100010];
int dp1[10000010];
int dp2[10000010];
bool kmp(string s1,string s2,int n){
	dp1[0]=0;
	dp2[0]=0;
	for(int i=1;i<s1.size();i++){
		int p=i-1;
		while(dp1[p]!=0 && (s1[i]!=s1[dp1[p]] || dp1[p]>p-dp1[p])){
		    p=dp1[p]-1;
	    }
	    if(s1[i]==s1[dp1[p]]){
	        dp1[i]=dp1[p]+1;
	    }else{
		    dp1[i]=0;
	    }
	}
	int cnt=0;
	for(int i=1;i<s2.size();i++){
		int p=i-1;
		while(dp2[p]!=0 && (s2[i]!=s2[dp2[p]] || dp2[p]>p-dp2[p])){
		    p=dp2[p]-1;
	    }
	    if(s2[i]==s2[dp2[p]]){
	        dp2[i]=dp2[p]+1;
	    }else{
		    dp2[i]=0;
	    }
	    if((dp1[i]==n || dp2[i]==n) && dp1[i]!=dp2[i]){
	    	return false;
		}
		if(dp1[i]==n){
			cnt++;
		}
	}
	return cnt==1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(k--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
		}else{
			int sum=0;
			for(int i=1;i<=n;i++){
				string sp1=a[i]+'#'+s1;
				string sp2=b[i]+'#'+s2;
				if(kmp(sp1,sp2,a[i].size())){
					sum++;
				}
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}
