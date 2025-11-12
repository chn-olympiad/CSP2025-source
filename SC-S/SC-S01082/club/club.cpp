#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int x=0,y=0,z=0;
struct _{
	int a;
	int b;
	int c;
}q[100101];

int p12[100101],p13[100101],p21[100101],p23[100101],p31[100101],p32[100101];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int o=1;o<=t;o++){
		int ans=0;
		x=0;
		y=0;
		z=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q[i].a>>q[i].b>>q[i].c;
			int mmm=max(q[i].a,max(q[i].b,q[i].c));
			ans+=mmm;
			if(q[i].a==mmm){
				x++;
				p12[i]=mmm-q[i].b;
				p13[i]=mmm-q[i].c;
				if(p12[i]>p13[i]) p12[i]=999999;
				else p13[i]=999999;
				p21[i]=999999;
				p23[i]=999999;
				p31[i]=999999;
				p32[i]=999999;
			}
			else if(q[i].b==mmm){
				y++;
				p12[i]=999999;
				p13[i]=999999;
				p21[i]=mmm-q[i].a;
				p23[i]=mmm-q[i].c;
				if(p21[i]>p23[i]) p21[i]=999999;
				else p23[i]=999999;
				p31[i]=999999;
				p32[i]=999999;
			}
			else if(q[i].c==mmm){
				z++;
				p12[i]=999999;
				p13[i]=999999;
				p21[i]=999999;
				p23[i]=999999;
				p31[i]=mmm-q[i].a;
				p32[i]=mmm-q[i].b;
				if(p31[i]>p32[i]) p31[i]=999999;
				else p32[i]=999999;
			}
		}
		sort(p12+1,p12+n+1);
		sort(p13+1,p13+n+1);
		sort(p21+1,p21+n+1);
		sort(p23+1,p23+n+1);
		sort(p31+1,p31+n+1);
		sort(p32+1,p32+n+1);
		
//		cout<<x<<' '<<y<<' '<<z<<'\n';
//		cout<<ans<<' ';
		
		if(x>n/2){
			int l=1,r=1;
			for(int k=1;k<=x-(n/2);k++){
				
//				int opop=min(p12[l],p13[r]);
//				cout<<opop<<' ';
				
				if(p12[l]<=p13[r]){
					ans-=p12[l];
					l++;
				}
				else{
					ans-=p13[r];
					r++;
				}
//				cout<<ans<<' ';
			}
		}
		else if(y>n/2){
			int l=1,r=1;
			for(int k=1;k<=y-(n/2);k++){
				if(p21[l]<=p23[r]){
					ans-=p21[l];
					l++;
				}
				else{
					ans-=p23[r];
					r++;
				}
			}
		}
		else if(z>n/2){
			int l=1,r=1;
			for(int k=1;k<=z-(n/2);k++){
				if(p31[l]<=p32[r]){
					ans-=p31[l];
					l++;
				}
				else{
					ans-=p32[r];
					r++;
				}
			}
		}
		
//		cout<<'\n';
		
		cout<<ans<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}