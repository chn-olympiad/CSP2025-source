#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,t,anp;
string a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>t;
	for(int i=0;i<n;i++){
		int k,ans=0;
		cin>>k;
		while(k>0){
			ans++;
			k/=2;
		}
		if(ans==0) a[i]='0';
		else{
			if(k%2==1) a[i][n-1]='1';
			while(ans){
				a[i][n-ans]='1';
				ans=0;
				while(k>0){
					ans++;
					k/=2;
				}
			}
		}
	}for(int i=0;i<n-1;i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='1'||a[i+1][j]=='1') a[i+1][j]=='1';
		}
	}
	int ans=0;
	for(int i=a[n-1].size()-1,j=0;i>=0,j<a[n-1].size();i--,j++){
		ans+=(a[n-1][i]-'0')*pow(2,j);
	}
	if(t==ans) anp++;
	cout<<anp;
	return 0;
}
