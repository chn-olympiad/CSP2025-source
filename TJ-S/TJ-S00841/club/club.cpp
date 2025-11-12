#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,t,myd;
int s1[5];

struct node{
	int st1,st2,st3;
}st[100005];

struct nodd{
	int xb,my;
};

bool cmp(nodd x,nodd y){
	if (x.my>y.my){
		return x.xb>y.xb; 
	}
	return x.xb<y.xb;
}

void zdmy(int x,int ans){
	
	if (x>n){
		myd=max(myd,ans);
		return ;
	}
	nodd num[5];
	num[1].xb=1;
	num[2].xb=2;
	num[3].xb=3;
	num[1].my=st[x].st1;
	num[2].my=st[x].st2;
	num[3].my=st[x].st3;
	sort(num+1,num+1+3,cmp);
	for (int i=1;i<=3;i++){
		s1[num[i].xb]+=1;
		if (s1[num[i].xb]<=m){
			zdmy(x+1,ans+num[i].my);
		}
		s1[num[i].xb]-=1;
	}
	
}

signed main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for (int T=1;T<=t;T++){
		cin>>n;
		m=n/2;
		for (int i=1;i<=n;i++){
			cin>>st[i].st1>>st[i].st2>>st[i].st3;
		}
		zdmy(1,0);
		cout<<myd<<endl;
		myd=0;
	}
	
	return 0;
}                                                                                 
