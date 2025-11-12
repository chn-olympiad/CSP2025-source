#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
int ans=0;
bool s[600],f[600];
int c[600],p[600];
void dfs(int x,int y){
	f[x]=true;
	p[y-1]=x;
	if(y==n){
		int cnt0=0;
		int cnt1=0;
		for(int i=0;i<n;i++){
			if(!s[i]||cnt0>=c[p[i]]){
				cnt0++;
			}
			else{
				cnt1++;
			}
		}
		if(cnt1>=m){
			ans++;
			if(ans>=998244353){
				ans-=998244353;
			}	
		}
		f[x]=false;
		return;
	}
	for(int i=0;i<n;i++){
		if(!f[i]){
			dfs(i,y+1);
		}
	}
	f[x]=false;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char ch;
	for(int i=0;i<n;i++){
		cin>>ch;
		if(ch=='0'){
			s[i]=false;
		}
		else{
			s[i]=true;
		}
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}