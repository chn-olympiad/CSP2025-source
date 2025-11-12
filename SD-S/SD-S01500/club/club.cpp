#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll in(){
	ll x=1,k=0;
	char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')x=-x;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		k=k*10+s-'0';
		s=getchar();
	}
	return k*x;
}
ll t,n;
struct ww{
	ll a,b,c,d,e,f;
}a[100100];
struct abc{
	ll d,e,f,wz;
};

ll cd1,cd2,cd3;
bool cmp1(abc x,abc y){
	return min(x.d,x.e)<min(y.d,y.e);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		vector<abc>jl1,jl2,jl3;
		cd1=cd2=cd3=0;
		n=in();
		for(int i=1;i<=n;i++){
			a[i].a=in(),a[i].b=in(),a[i].c=in();
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				a[i].d=a[i].a-a[i].b;
				a[i].e=a[i].a-a[i].c;
				jl1.push_back({a[i].d,a[i].e,0,i} );
			}
			else{
				if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
					a[i].d=a[i].b-a[i].a;
					a[i].e=a[i].b-a[i].c;
					jl2.push_back({a[i].d,a[i].e,0,i});
				}
				else{
					a[i].d=a[i].c-a[i].a;
					a[i].e=a[i].c-a[i].b;
					jl3.push_back({a[i].d,a[i].e,0,i});
				}
			}
		}
		if(jl1.size()>n/2){
			sort(jl1.begin(),jl1.end(),cmp1);
			for(int i=0;i<jl1.size()-(n/2);i++){
				if(jl1[i].e>jl1[i].d){
					jl2.push_back({0,0,0,jl1[i].wz});
				}
				else{
					jl3.push_back({0,0,0,jl1[i].wz});
				}
				cd1++;
			}
		}
		else{
			if(jl2.size()>n/2){
				sort(jl2.begin(),jl2.end(),cmp1);
				for(int i=0;i<jl2.size()-(n/2);i++){
					if(jl2[i].e>jl2[i].d){
						jl1.push_back({0,0,0,jl2[i].wz});
					}
					else{
						jl3.push_back({0,0,0,jl2[i].wz});
					}
					
					cd2++;
				}
			}
			else{
				if(jl3.size()>n/2){
					sort(jl3.begin(),jl3.end(),cmp1);
					for(int i=0;i<jl3.size()-(n/2);i++){
						if(jl3[i].e>jl3[i].d){
							jl1.push_back({0,0,0,jl3[i].wz});
						}
						else{
							jl2.push_back({0,0,0,jl3[i].wz});
						}
						cd3++;
					}
				}
			}
		}
		ll ans=0;
		for(int i=cd1;i<jl1.size();i++){
			ans+=a[jl1[i].wz].a;
		}
//		cout<<ans<<"\n";
		for(int i=cd2;i<jl2.size();i++){
			ans+=a[jl2[i].wz].b;
		}
//		cout<<ans<<"\n";
		for(int i=cd3;i<jl3.size();i++){
			ans+=a[jl3[i].wz].c;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*1
4
1 3 2
5 3 1
4 7 7
5 9 9*/
//Ren5Jie4Di4Ling5%

