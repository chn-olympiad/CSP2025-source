#include<bits/stdc++.h>
using namespace std;
int n,t,v[100010],ans1,ans2,x,y,z,max2,m;
struct student{
	int a1;
	int a2;
	int a3;
	int fir;
	int sec;
	int thi;
	int x1;
	int y2;
	int z1;
}s[100010];
int cmp(student a,student b){
	return a.fir>b.fir;	
}
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		max2=0;
		m=0;
		x=0;
		y=0;
		z=0;
		ans1=0;
		ans2=0;
		for(int j=1;j<=n;j++){
			cin>>s[j].a1>>s[j].a2>>s[j].a3;

			s[j].fir=max(max(s[j].a1,s[j].a2),s[j].a3);
			s[j].thi=min(min(s[j].a1,s[j].a2),s[j].a3);
			if(s[j].a1!=s[j].fir&&s[j].a1!=s[j].thi){
				s[j].sec=s[j].a1;
			}
			if(s[j].a2!=s[j].fir&&s[j].a2!=s[j].thi){
				s[j].sec=s[j].a2;
			}
			if(s[j].a3!=s[j].fir&&s[j].a3!=s[j].thi){
				s[j].sec=s[j].a3;
			}
			if(s[j].fir==s[j].a1){
				x++;
				s[j].x1++;
			}
			if(s[j].fir==s[j].a2){
				y++;
				s[j].y2++;
			}
			if(s[j].fir==s[j].a3){
				z++;
				s[j].z1++;
			}
			ans1+=s[j].fir;
		}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		if(x<=n/2&&y<=n/2&&z<=n/2){
				cout<<ans1<<endl;
				continue;
		}
		
		if(n==2){
			max2=max(s[1].fir,s[2].fir);
			if(s[1].fir=max2){
				ans2=max2+s[2].sec;
			}
			if(s[2].fir=max2){
				ans2=max2+s[1].sec;
			}
			cout<<ans2<<endl;
		}else{
			sort(s+1,s+1+n,cmp);
			for(int j=1;j<=n;j++){
				if((s[j].a2==0&&s[j].a3==0)||(s[j].a1==0&&s[j].a3==0)||(s[j].a1==0&&s[j].a2==0)){
					if(m<n/2){
						ans2+=s[j].fir;
						m++;
					}		
				}
			}
			
			cout<<ans2<<endl;
		}
				
		}
			return 0;
	}
	
