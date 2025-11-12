#include<bits/stdc++.h>
using namespace std;
int t,tt;
int n;
struct node{
	int y,e,s;
	int m;
	int num,sum,mum;
}a[100005];
bool cmp(node a,node b){
	if(a.m>=b.m){
		return a.m>b.m;
	}
}
int co[15];
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	tt=t;
	while(tt--){
		int yi=0,er=0,san=0;
		int c=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].y>>a[i].e>>a[i].s;
			if(a[i].y>=a[i].e&&a[i].e>=a[i].s){
				a[i].m=a[i].y;
				a[i].num=1;
				a[i].sum=2;
				a[i].mum=3;
			}
			else if(a[i].y>=a[i].s&&a[i].s>=a[i].e){
				a[i].m=a[i].y;
				a[i].num=1;
				a[i].sum=3;
				a[i].mum=2;
			}
			else if(a[i].e>=a[i].y&&a[i].y>=a[i].s){
				a[i].m=a[i].e;
				a[i].num=2;
				a[i].sum=1;
				a[i].mum=3;
			}
			else if(a[i].e>=a[i].s&&a[i].s>=a[i].y){
				a[i].m=a[i].e;
				a[i].num=2;
				a[i].sum=3;
				a[i].mum=1;
			}
			else if(a[i].s>=a[i].y&&a[i].y>=a[i].e){
				a[i].m=a[i].s;
				a[i].num=3;
				a[i].sum=1;
				a[i].mum=2;
			}
			else if(a[i].s>=a[i].e&&a[i].e>=a[i].y){
				a[i].m=a[i].s;
				a[i].num=3;
				a[i].sum=2;
				a[i].mum=1;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].num==1){
				if(yi<n/2){
					yi++;
					c+=a[i].m;
				}
				else{
					int s=a[i].sum;
					a[i].sum=a[i].mum;
					a[i].num=s;
					if(s==2){
						a[i].m=a[i].e;
					}
					else{
						a[i].m=a[i].s;
					}
					i--;
				}
			}
			else if(a[i].num==2){
				if(er<n/2){
					er++;
					c+=a[i].m;
				}
				else{
					int s=a[i].sum;
					a[i].sum=a[i].mum;
					a[i].num=s;
					if(s==1){
						a[i].m=a[i].y;
					}
					else{
						a[i].m=a[i].s;
					}
					i--;
				}
			}
			else{
				if(san<n/2){
					san++;
					c+=a[i].m;
				}
				else{
					int s=a[i].sum;
					a[i].sum=a[i].mum;
					a[i].num=s;
					if(s==1){
						a[i].m=a[i].y;
					}
					else{
						a[i].m=a[i].e;
					}
					i--;
				}
			}
		}
		co[ans]=c;
		ans++;
	}
	for(int i=0;i<t;i++){
		cout<<co[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
