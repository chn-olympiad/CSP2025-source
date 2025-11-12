#include<bits/stdc++.h>
using namespace std;
struct member{
	int v;
	int id;
	int a,b,c;
}s[100005];
int n,t;
int aa[3];
bool cmp(member a,member b){
	return a.v<b.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,flag1=0,flag2=0,flag3=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a==0&&s[i].b==0) flag1++;
			if(s[i].a==0&&s[i].c==0) flag2++;
			if(s[i].b==0&&s[i].c==0) flag3++;
			int ma=max(max(s[i].a,s[i].b),s[i].c);
			if(ma==s[i].a){
				s[i].id=1;
				s[i].v=ma;
			}else if(ma==s[i].b){
				s[i].id=2;
				s[i].v=ma;
			}else{
				s[i].id=3;
				s[i].v=ma;
			}
		}
		long long ans=0;
		sort(s+1,s+n+1,cmp);
		if(flag1==n||flag2==n||flag3==n){
			for(int i=n;i>n/2;i--){
				ans+=s[i].v; 
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			int a1=s[1].a+s[2].b,a2=s[1].a+s[2].c,a3=s[1].b+s[2].c,a4=s[1].b+s[2].a,a5=s[1].c+s[2].a,a6=s[1].c+s[2].b;
			cout<<max(max(max(a1,a2),max(a4,a3)),max(a5,a6))<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(s[i].id==1){
				if(cnt1<n/2){
					cnt1++;
					ans+=s[i].v;
				}else{
					if(s[i].b>s[i].c&&cnt2<n/2){
						cnt2++;
						ans+=s[i].b;	
					}else{
						cnt3++;
						ans+=s[i].c; 
					}			
				}
			}else if(s[i].id==2){
				if(cnt2<n/2){
					cnt2++;
					ans+=s[i].v;
				}else{
					if(s[i].a>s[i].c&&cnt1<n/2){
						cnt1++;
						ans+=s[i].a;
					}else{
						cnt3++;
						ans+=s[i].c; 
					}		
				}
			}else{
				if(cnt3<n/2){
					cnt3++;
					ans+=s[i].v;
				}else{
					if(s[i].a>s[i].b&&cnt1<n/2){
						cnt1++;
						ans+=s[i].a;	
					}else{
						cnt2++;
						ans+=s[i].b; 
					}			
				}
			} 
		}
		cout<<ans<<endl;
	}
	return 0;
}