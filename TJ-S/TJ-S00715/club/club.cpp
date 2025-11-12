#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5+5;
int t,n; 

struct node{
	int a1,a2,a3;
};
node a[MAX];

int ans;

int solve1(){
	int res=0;
	int m1=max(a[1].a1,a[1].a2);
	m1=max(m1,a[1].a3);
	int m2=max(a[2].a1,a[2].a2);
	m2=max(m2,a[2].a3);
	if(m1==a[1].a1&&m2==a[2].a1){
		int ma=max(a[1].a3,a[1].a2);
		int mb=max(a[2].a3,a[2].a2);
		int m=max(m1+mb,m2+ma);
		res+=m;
	}else if(m1==a[1].a2&&m2==a[2].a2){
		int ma=max(a[1].a3,a[1].a1);
		int mb=max(a[2].a3,a[2].a1);
		int m=max(m1+mb,m2+ma);
		res+=m;
	}else if(m1==a[1].a3&&m2==a[2].a3){
		int ma=max(a[1].a1,a[1].a2);
		int mb=max(a[2].a1,a[2].a2);
		int m=max(m1+mb,m2+ma);
		res+=m;
	}
	
	return res;
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n==2) cout<<solve1()<<endl;
		else cout<10000;
		//else if(n==4) cout<<solve2()<<endl;
	}
	return 0;
}
