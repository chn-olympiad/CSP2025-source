#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}s[100010];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,f=0,cnt=0,f2=0;
		cin>>n;
		int p=n/2;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0||s[i].c!=0){
				f=1;
			}
			if(s[i].c!=0){
				f2=1;
			}
		}
		if(f==0){
			sort(s+1,s+1+n,cmp);
			 for(int i=1;i<=p;i++){
			 	cnt+=s[i].a;
			 }
			 cout<<cnt<<endl;
		}
		else if(f2==0){
			sort(s+1,s+1+n,cmp);
			 for(int i=1;i<=p;i++){
			 	cnt+=s[i].a;
			 }
			 sort(s+1,s+1+n,cmp2);
			 for(int i=1;i<=p;i++){
			 	cnt+=s[i].b;
			 }
			 cout<<cnt<<endl;
		}else{
			for(int j=1;j<=n;j++){
				int mx=max(max(s[j].a,s[j].b),s[j].c);
				cnt+=mx;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

