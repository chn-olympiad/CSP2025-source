#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+2,mod=998244353;
int n,q;
long long ans;
string s[max_n][2],t[max_n][2];
bool check(int l,int r,int ii,int kk){
	for(int i=l;i<=r;i++){
		if(s[ii][1][i]!=t[kk][1][i]){
			return false;
		}
	}
	string s="";
	for(int i=0;i<l;i++){
		s+=s[ii][1][i];
	}
	for(int i=l;i<=r;i++){
		s+=t[kk][2][i];
	}
	for(int i=r+1;i<n;i++){
		s+=s[ii][1][i];
	}
	if(s==s[ii][2]){
		return true;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][1]>>t[i][2];
		int tn=t[i][1].size(),tn_=t[i][2].size();
		if(tn!=tn_){
			puts("0");
			continue;
		}
		for(int k=1;k<=n;k++){
			int tmpn=s[k][1].size();
			for(int i=0;i<tn-tmpn+1;i++){
				if(check(i,i+tmpn-1,i,k)){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
