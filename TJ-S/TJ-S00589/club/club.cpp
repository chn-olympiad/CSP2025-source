#include<bits/stdc++.h>
using namespace std;
struct ab{
	int a,b,c;
}aa[100005];
long long n,now;
long long ans(int a1,int b1,int c1,int at){
	if(at>n){
		return 0;
	}
 	long long ls=0;
	if(a1<n/2){
		ls=max(ls,ans(a1+1,b1,c1,at+1)+aa[at].a);
	}
	if(b1<n/2){
		ls=max(ls,ans(a1,b1+1,c1,at+1)+aa[at].b);
	}
	if(c1<n/2){
		ls=max(ls,ans(a1,b1,c1+1,at+1)+aa[at].c);
	}
	return ls;
}
bool cmp(ab xx,ab yy){
	return xx.c>yy.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>now;
	bool flag=0;
	while(now--){
		cin>>n;
		flag=0;
		for(int i=1;i<=n;i++){
			cin>>aa[i].a>>aa[i].b>>aa[i].c;
			if(aa[i].b!=0||aa[i].c!=0) flag=1;
		}
		if(flag==0){
			sort(aa+1,aa+n+1,cmp);
			long long ask=0;
			for(int i=1;i<=n/2;i++) ask+=aa[i].a; 
		}
		cout<<ans(0,0,0,1)<<endl;
	}
	return 0;
}
