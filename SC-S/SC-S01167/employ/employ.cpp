#include<bits/stdc++.h>
using namespace std;

const int M=998244353;
int n,m,c[505],a[505],xa,su,r[505],ane;

void f(int x,int y,int z){//录取人数 天数 退的个数 
	if(y>n){
		if(x>=m)ane=(ane+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(r[i])continue;
		r[i]=1;
		bool wa=0;
		if(a[y]&&z<c[i])wa=1;
		f(x+wa,y+1,z+(!wa));
		r[i]=0;
	} 
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char l;
	for(int i=1;i<=n;i++){
		scanf("%c",&l);
		a[i]=l-'0';
		if(!a[i])xa=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(!c[i])su++;
	}
//	int zy=rand();
//	if(zy<10000)
	f(0,1,0);
	cout<<ane;
//	if(!xa){
//	if(n-su<m){
//		cout<<0<<endl;
//		return 0;
//	}
//		int ans=0,qq=1;
//		for(int i=2;i<=n-su;i++){
//			qq=(qq*i)%M;
//		}
//		cout<<qq<<endl;
//	}
	return 0;
}
//感觉没戏了，有点想退