#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct by{
	int k;
	int d;
};
struct cy{
	by a[3];
};
cy s[100050]={};
bool sd[100050]={};
int muh;
void dfs(int n,int y,int q1,int q2,int q3,int l1,int l2,int l3){
	if(y==n){
		muh=max(muh,q1+q2+q3);
		return;
	}
	else{
		for(int i=0;i<n;i++){
			if(sd[i]==false){
				sd[i]=true;
				if(l1+1<=n/2) dfs(n,y+1,q1+s[i].a[0].d,q2,q3,l1+1,l2,l3);
				if(l2+1<=n/2) dfs(n,y+1,q1,q2+s[i].a[1].d,q3,l1,l2+1,l3);
				if(l3+1<=n/2) dfs(n,y+1,q1,q2,q3+s[i].a[2].d,l1,l2,l3+1);
				sd[i]=false;
			}
		}
		return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	int n;
	int b,da[3];
	int l[3]={};
	cin>>t;
	for(int i=0;i<t;i++){
		for(int j=0;j<3;j++){
			l[j]=0;
			da[j]=0;
		}
		cin>>n;
		muh=-1;
		for(int j=0;j<n;j++){
			s[j].a[0].k=0;
			s[j].a[1].k=1;
			s[j].a[2].k=2;
		}
		b=n/2;
		for(int j=0;j<n;j++){
			cin>>s[j].a[0].d>>s[j].a[1].d>>s[j].a[2].d;
			sd[j]=false;
		}
		dfs(n,0,0,0,0,0,0,0);
		cout<<muh<<endl;
	}
	return 0;
}
