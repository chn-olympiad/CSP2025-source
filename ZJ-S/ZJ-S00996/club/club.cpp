#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt1,cnt2,cnt3,ans;
struct stu{
	long long a,b,c,d,e,f;
}r[1000010];
void cle(stu s){
	s.a=0;s.b=0;s.c=0;s.d=0;s.e=0;s.f=0;
}
bool cmp(stu x,stu y){
	if(x.f!=y.f) return x.f>y.f;
	else return max(max(x.a,x.b),x.c)>max(max(y.a,y.b),y.c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt1=0;cnt2=0;cnt3=0;ans=0;
		for(int i=1;i<=n;i++){cle(r[i]);}
		for(int i=1;i<=n;i++){
		cin>>r[i].a>>r[i].b>>r[i].c;
		int k=max(max(r[i].a,r[i].b),r[i].c);
		if(k==r[i].a){
			r[i].e=1;r[i].f=min(r[i].a-r[i].b,r[i].a-r[i].c);r[i].d=r[i].c>r[i].b?3:2;
		}
		else if(k==r[i].b){
			r[i].e=2;r[i].f=min(r[i].b-r[i].c,r[i].b-r[i].a);r[i].d=r[i].c>r[i].a?3:1;
		}
		else{
			r[i].e=3;r[i].f=min(r[i].c-r[i].b,r[i].c-r[i].a);r[i].d=r[i].a>r[i].b?1:2;
		}
//		cout<<r[i].d<<" "<<r[i].e<<" "<<r[i].f<<endl;
		}
		sort(r+1,r+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(r[i].e==1){
				if(cnt1<n/2){ans+=r[i].a;cnt1++;
				}
				else if(r[i].d==2){
					ans+=r[i].b;cnt2++;
				}else{
					ans+=r[i].c;cnt3++;
				}
			}
			else if(r[i].e==2){
				if(cnt2<n/2){ans+=r[i].b;cnt2++;
				}
				else if(r[i].d==1){
					ans+=r[i].a;cnt1++;
				}else{
					ans+=r[i].c;cnt3++;
				}
			}
			else{
				if(cnt3<n/2){ans+=r[i].c;cnt3++;
				}
				else if(r[i].d==2){
					ans+=r[i].b;cnt2++;
				}else{
					ans+=r[i].a;cnt1++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
