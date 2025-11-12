#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
typedef long long llint;
typedef unsigned long long ullint;

const int MOD=998244353;

int n,m;

char ss[501];
int a[501];
bool vis[501]={};

llint dfs(int s,int given){
	//fprintf(stderr,"T:%d %d\n",s,given);
	if(m+given>n){
		return 0;
	}
	if(s==n){
		return 1;
	}
	llint ans=0;
	for(int i=0;i<n;i+=1){
		if(!vis[i]){
			vis[i]=1;
			//fprintf(stderr,"%d %d %d:%c %d, %d\n",s,given,i,ss[s],a[i],((ss[s]=='0' || given>=a[i])?0:1));
			ans=(ans+dfs(s+1,given+((ss[s]=='0' || given>=a[i])?1:0)))%MOD;
			vis[i]=0;
		}
	}
	return ans;
}

llint fac(int x){
	//fprintf(stderr,"111");
	llint ans=1;
	for(int i=2;i<x;i+=1){
		ans=(ans*x)%MOD;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	cin>>ss;
	for(int i=0;i<n;i+=1){
		cin>>a[i];
	}
	/*
	if(m==1 && ss[0]=='1'){
		cout<<fac(n)<<endl;
		return 0;
	}
	bool flag=1;
	for(int i=0;i<n;i+=1){
		if(ss[i]=='0'){
			if(m==n){
				cout<<"0"<<endl;
				return 0;
			}
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<fac(n)<<endl;
		return 0;
	}
	//fprintf(stderr,"222");
	//*/
	cout<<dfs(0,0)<<endl;
	return 0;
}

