#include<bits/stdc++.h>
using namespace std;
int n,a1,a2,a3,q,res,aa,sum,l;
struct tt{
	int a1,a2,a3,d;
}s[1145141];
struct rr{
	int a,id;
}b[1145141];
bool cmp(tt x,tt y){
	return x.d>y.d;
}
bool cmp1(rr x,rr y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1,&a2,&a3);
			q=min(a1,min(a2,a3));
			res+=q;
			a1-=q;a2-=q;a3-=q;
			if(a1==0){
				s[i].d=abs(a2-a3);
			}
			else if(a2==0){
				s[i].d=abs(a1-a2);
			}
			else{
				s[i].d=abs(a2-a3);
			}
			s[i].a1=a1;
			s[i].a2=a2;
			s[i].a3=a3;
		}
		sort(s+1,s+1+n,cmp);
		int p1,p2,p3;
		p1=p2=p3=n/2;
		for(int i=1;i<=n;i++){
			a1=s[i].a1;a2=s[i].a2;a3=s[i].a3;
			aa=max(a1,max(a2,a3));
			if(a1==aa&&p1>0){
				res+=a1;
				p1--;
				s[i].a1=0;
				sum++;
			}
			else if(a2==aa&&p2>0){
				res+=a2;
				p2--;
				s[i].a2=0;
				sum++;
			}
			else if(a3==aa&&p3>0){
				res+=a3;
				p3--;
				s[i].a3=0;
				sum++;
			}
			else if(a1==aa&&p1<=0){
				s[i].a1=0;
			}
			else if(a2==aa&&p2<=0){
				s[i].a2=0;
			}
			else if(a3==aa&&p3<=0){
				s[i].a3=0;
			}
		}
		for(int i=1;i<=n;i++){
			a1=s[i].a1;a2=s[i].a2;a3=s[i].a3;
			if(a1>0){
				b[++l].a=a1;
				b[l].id=1;
			}
			if(a2>0){
				b[++l].a=a2;
				b[l].id=2;
			}
			if(a3>0){
				b[++l].a=a3;
				b[l].id=3;
			}
		}
		sort(b+1,b+l+1,cmp1);
		for(int i=1;i<=l;i++){
			if(sum==n){
				break;
			}
			if(b[i].id==1&&p1>0){
				res+=b[i].a;
				p1--;
				sum++;
			}
			if(b[i].id==2&&p2>0){
				res+=b[i].a;
				p2--;
				sum++;
			}
			if(b[i].id==3&&p3>0){
				res+=b[i].a;
				p3--;
				sum++;
			}
		}
		cout<<res<<endl;
		sum=l=res=0;
	}
}