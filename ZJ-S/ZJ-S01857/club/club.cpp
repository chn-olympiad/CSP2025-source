#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c,d,e,f;
}m[N];
int pq1(node x,node y){
	return x.d>y.d;
}
int pq2(node x,node y){
	return x.d<y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int T,sum=0;
	cin>>T;
	while(T--){
		int n,sun=0,a1=0,b1=0,c1=0;
		cin>>n;
		sum=n/2;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].d=max(m[i].a,max(m[i].b,m[i].c));
			m[i].f=min(m[i].a,min(m[i].b,m[i].c));
			m[i].e=(m[i].a+m[i].b+m[i].c)-(m[i].d+m[i].f);
		}
		sort(m+1,m+n+1,pq1);
		bool bj=0;
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;){
			bj=0;
			if(m[i].a==m[i].d){
				a1++;
				s1++;
				if(a1<=sum){
					sun+=m[i].d;
					bj=1;
				}
			}
			else if(m[i].b==m[i].d){
				b1++;
				if(b1<=sum){
					sun+=m[i].d;
					bj=1;
				}
			}
			else if(m[i].c==m[i].d){
				c1++;
				if(c1<=sum){
					sun+=m[i].d;
					bj=1;
				}
			}
			if(s1==2 or s2==2 or s3==2){
				m[i].d=m[i].f;
			}
			else if(bj==0){
				m[i].d=m[i].e;
			}
			if(bj==1){
				i++;
				s1=0;
				s2=0;
				s3=0;
			}
		}
		for(int i=1;i<=n;i++){
			m[i].d=max(m[i].a,max(m[i].b,m[i].c));
			m[i].f=min(m[i].a,min(m[i].b,m[i].c));
			m[i].e=(m[i].a+m[i].b+m[i].c)-(m[i].d+m[i].f);
		}
		bj=0;
		sort(m+1,m+n+1,pq2);
		s1=0,s2=0,s3=0,bj=0;
		a1=0,b1=0,c1=0;
		int sun1=0;
		for(int i=1;i<=n;){
			bj=0;
			if(m[i].a==m[i].d){
				a1++;
				s1++;
				if(a1<=sum){
					sun1+=m[i].d;
					bj=1;
				}
			}
			else if(m[i].b==m[i].d){
				b1++;
				s2++;
				if(b1<=sum){
					sun1+=m[i].d;
					bj=1;
				}
			}
			else if(m[i].c==m[i].d){
				c1++;
				s3++;
				if(c1<=sum){
					sun1+=m[i].d;
					bj=1;
				}
			}
			if(s1==2 or s2==2 or s3==2){
				m[i].d=m[i].f;
			}
			else if(bj==0){
				m[i].d=m[i].e;
			}
			if(bj==1){
				i++;
				s1=0;
				s2=0;
				s3=0;
			}
		}
		cout<<max(sun,sun1)<<endl;
	}
	return 0;
}
