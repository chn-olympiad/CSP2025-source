#include<bits/stdc++.h>
using namespace std;
struct u{
	int a,b,c;
}w[100000];
bool cmp(u rt, u ru){
	if(rt.a==ru.a){
		if(rt.b==ru.b){
			return rt.c<ru.c;
		}
		return rt.b<ru.b;
	}
	return rt.a<ru.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,i,j,k,l,r,n,ns,s,a1,b1,c1;
	int t1,p,q;
	cin>>t;
	for(i=1;i<=t;i++){
		s=0;
		a1=0,b1=0,c1=0;
		cin>>n;
		ns=n/2;
		for(j=1;j<=n;j++){
			cin>>w[j].a>>w[j].b>>w[j].c;
			if(w[j].b==0) q++;
			if(w[j].c==0) p++;
			
			
		}
		sort(w+1,w+1+n,cmp);
		if(q==n) for(j=ns+1;j<=n;j++){
			s+=w[j].a;
		}
	
		cout<<s<<"\n";
	}
	return 0;
}