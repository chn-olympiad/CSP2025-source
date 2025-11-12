#include<bits/stdc++.h>
using namespace std;
const int inf=500005;
int n;
int k;
int a[inf];
bool vis[inf];
string a1[inf];
int cnt;
string su(int x){
	int x1[inf]={};
	int t=0;
	while(x>0){
		x1[t]=x%2;
		t++;
		x/=2;
	}
	string s;
	for(int i=t-1;i>=0;i--){
		s+=x1[i]+48;
	}
	return s;
}
string xoor(string x,string y){
	string t;
	for(int i=max(x.size(),y.size())-1;i>=0;i--){
		if(x[i]!=y[i]) t+="1";
		else t+="0";
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=su(a[i]);
	}
	string w=su(k);
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		if(a1[i]==w&&vis[i]==0){
			cnt++;
			vis[i]=1;
		}else{
			if(xoor(a1[i],a1[i+1])==w&&vis[i]==0&&vis[i+1]==0){
				vis[i]=vis[i+1]=1;
				cnt++;
			}else{
				a1[i+1]=xoor(a1[i],a1[i+1]);
			}
		}
	}
	cout<<cnt;
	return 0;
}