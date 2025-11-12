#include<bits/stdc++.h>
using namespace std;
struct p{
	int a,b,c;
}pe[100010];
bool cmp1(p x,p y){
	return x.a>y.a;
}
bool cmp2(p x,p y){
	return x.b>y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool isa=true;
		bool isb=true;
		for(int i=1;i<=n;i++){
			cin>>pe[i].a>>pe[i].b>>pe[i].c;
			if(pe[i].b!=0||pe[i].c!=0||pe[i].a==0){
				isa=false;
			}
			if(pe[i].c!=0||pe[i].b==0||pe[i].a==0){
				isb=false;
			}
		}
		if(isa){
			sort(pe+1,pe+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=pe[i].a;
				pe[i].a=0;
			}
			cout<<ans<<endl;
		}
		else if(isb){
			int ans1=0;
			sort(pe+1,pe+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans1+=pe[i].a; 
				pe[i].a=0;
			}
			sort(pe+1,pe+n+1,cmp2);
			int ans2=0;
			int cnt2=0;
			int i=1;
			while(cnt2!=n/2){
				if(pe[i].a!=0){
					ans2+=pe[i].b;
					cnt2++;
				}
				i++;
			}
			cout<<ans1+ans2<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
