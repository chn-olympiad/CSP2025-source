#include<bits/stdc++.h>
using namespace std;
int n,m,T,as;
bool b1=1,b2=1,b3=1;
int k[3][10000];
void seach(int id,int al,int bl,int cl,int aes){
	if(id==n)as=max(as,aes);
	if(al+1<=n/2)seach(id+1,al+1,bl,cl,aes+k[0][id]);
	if(bl+1<=n/2)seach(id+1,al,bl+1,cl,aes+k[1][id]);
	if(cl+1<=n/2)seach(id+1,al,bl,cl+1,aes+k[2][id]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			k[0][i]=a;
			k[1][i]=b;
			k[2][i]=c;
			if(a!=0)b1=0;
			if(b!=0)b2=0;
			if(c!=0)b3=0;
			as+=max(a,max(b,c));
		}
		if(((b1&&b2)||(b2&&b3)||(b3&&b1))&&(!b1||!b2||!b3)){
			int ya;
			if(!b1)ya=0;
			else if(!b2)ya=1;
			else ya=2;
			sort(k[ya],k[ya]+n);
			int ans=0;
			for(int i=n-1;i>=n/2;i--){
				ans+=k[ya][i];
			}
			cout<<ans;
		}else if(n<15){
			as=0;
			seach(0,0,0,0,0);
			cout<<as;
		}else{
			cout<<as;
		}
		cout<<endl;
	}
	return 0;
}