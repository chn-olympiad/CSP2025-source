#include<bits/stdc++.h>
using namespace std;
int t,n,ans,c1,c2,c3,an[3][2];
struct Ed{
	int a1,a2,a3,mn,mx,mxi;
}a[100005];
bool cmp(Ed a, Ed b){
	if(a.mx<b.mx)return 1;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int ts=0;ts<t;ts++){
		cin>>n;
		ans=0;
		c1=0;
		c2=0;
		c3=0;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].mn=min(a[i].a1,min(a[i].a2,a[i].a3));
			a[i].a1=a[i].a1-a[i].mn;
			a[i].a2=a[i].a2-a[i].mn;
			a[i].a3=a[i].a3-a[i].mn;
			a[i].mx=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].mx==a[i].a1)a[i].mxi=1;
			else if(a[i].mx==a[i].a2)a[i].mxi=2;
			else a[i].mxi=3;
			ans+=a[i].mn; 
		} 
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			if(a[i].mxi==1){
				if(c1<n/2){
					ans+=a[i].mx; 
					c1++;
				}
				else{
					if(a[i].a2>a[i].a3&&c2<n/2){
						ans+=a[i].a2; 
						c2++;
					}
					else{
						ans+=a[i].a3; 
						c3++;
					}
				}
			}
			else if(a[i].mxi==2){
				if(c2<n/2){
					ans+=a[i].mx; 
					c2++;
				}
				else{
					if(a[i].a1>a[i].a3&&c1<n/2){
						ans+=a[i].a1; 
						c1++;
					}
					else{
						ans+=a[i].a3; 
						c3++;
					}
				}
			}
			else{
				if(c3<n/2){
					ans+=a[i].mx; 
					c3++;
				}
				else{
					if(a[i].a1>a[i].a2&&c1<n/2){
						ans+=a[i].a1; 
						c1++;
					}
					else{
						ans+=a[i].a2; 
						c2++;
					}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}