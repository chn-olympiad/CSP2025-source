#include<bits/stdc++.h>
using namespace std;
int t;
long n,o,a[5];
struct node{
	int a1,a2,a3;
	int a4=max(a1,max(a2,a3));
	node(int x,int y,int z){
		a1=x;a2=y;a3=z;
		a4=max(a1,max(a2,a3));
	}
	bool operator>(const node e)const{
		return a4<e.a4;
	}
};
priority_queue<node,vector<node>,greater<node>> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		o=0;
		a[1]=0;a[2]=0;a[3]=0;
		while(!q.empty()){
			q.pop();
		}
		cin>>n;
		for(int j=1;j<=n;j++){
			int x,y,z;
			cin>>x>>y>>z;
			q.push(node(x,y,z));
		}
		bool s[4]={1,1,1,1};
        while(!q.empty()){
			int r=0,ri=0;
			if(s[1]) r=max(r,q.top().a1);
			if(s[2]) r=max(r,q.top().a2);
			if(s[3]) r=max(r,q.top().a3);
			if(q.top().a1==r){ri=1;}
			if(q.top().a2==r){ri=2;}
			if(q.top().a3==r){ri=3;}
			a[ri]++;
			q.pop();
			o+=r;
			if(a[1]>=(n/2))s[1]=0;
			if(a[2]>=(n/2))s[2]=0;
			if(a[3]>=(n/2))s[3]=0;
		}
		cout<<o<<endl;
	}
	return 0;
}