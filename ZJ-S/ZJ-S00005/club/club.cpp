#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
long long t,n,d[N],sum,e,f,g;
struct node{
	int a,b,c,x;
}m[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0,e=0,f=0,g=0;
		for(int i=1;i<=200000;i++) d[i]=0;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].a>=m[i].b and m[i].a>=m[i].c) m[i].x=1,e++;
			else if(m[i].b>=m[i].a and m[i].b>=m[i].c) m[i].x=2,f++;
			else m[i].x=3,g++;
		}
		for(int i=1;i<=n;i++){
			if(m[i].x==1) sum+=m[i].a;
			else if(m[i].x==2) sum+=m[i].b;
			else sum+=m[i].c;
		}
		if(e<=n/2 and f<=n/2 and g<=n/2) cout<<sum<<endl;
		else if(e>n/2){
			for(int i=1;i<=n;i++){
				m[i].b=m[i].a-m[i].b;
				m[i].c=m[i].a-m[i].c;
				d[i]=min(m[i].b,m[i].c);
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=n/2;i++){
				if(d[i]>=0) sum-=d[i];
			}
			cout<<sum<<endl;
		}else if(f>n/2){
			for(int i=1;i<=n;i++){
				m[i].a=m[i].b-m[i].a;
				m[i].c=m[i].b-m[i].c;
				d[i]=min(m[i].a,m[i].c);
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=n/2;i++){
				if(d[i]>=0) sum-=d[i];
			}
			cout<<sum<<endl;
		}else{
			for(int i=1;i<=n;i++){
				m[i].a=m[i].c-m[i].a;
				m[i].b=m[i].c-m[i].b;
				d[i]=min(m[i].a,m[i].b);
			}
			sort(d+1,d+n+1);
			for(int i=1;i<=n/2;i++){
				if(d[i]>=0) sum-=d[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
