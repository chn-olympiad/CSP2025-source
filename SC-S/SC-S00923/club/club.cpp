#include<bits/stdc++.h>
using namespace std;
long long t,n,a1,a2,a3,ans;
struct stu{
	long long a,b,c,e;
	char d;
};
stu a[100005];
bool cmp(stu a,stu b){
	return a.d>b.d;
}
bool cmp2(stu a,stu b){
	return a.e<b.e;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		a1=0;
		a2=0;
		a3=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>a[i].b&&a[i].a>a[i].c){
				a[i].d='a';
				if(a[i].b>a[i].c){
					a[i].e=a[i].a-a[i].b;
				}else{
					a[i].e=a[i].a-a[i].c;
				}
			}else if(a[i].b>a[i].a&&a[i].b>a[i].c){
				a[i].d='b';
				if(a[i].a>a[i].c){
					a[i].e=a[i].b-a[i].a;
				}else{
					a[i].e=a[i].b-a[i].c;
				}
			}else{
				a[i].d='c';
				if(a[i].a>a[i].b){
					a[i].e=a[i].c-a[i].a;
				}else{
					a[i].e=a[i].c-a[i].b;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].d=='a'){
				ans+=a[i].a;
				a1++;
			}else if(a[i].d=='b'){
				ans+=a[i].b;
				a2++; 
			}else{
				ans+=a[i].c;
				a3++;
			}
		}
		if(a1<=n/2&&a2<=n/2&&a3<=n/2){
			cout<<ans<<"\n";
			continue;
		}else{
			long long aa=max(a1,max(a2,a3));
			sort(a+1,a+1+n,cmp2);
			for(int i=1;aa>n/2&&i<=n;i++){
				aa--;
				ans-=a[i].e;
			}
			cout<<ans<<"\n";
		}
	}
	
	
	
	return 0;
} 