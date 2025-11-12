#include<bits/stdc++.h>
using namespace std;
struct node{
	int o,p,q,m1,m2,m3,p1,p2,p3;
}a[200010];
int cmp(node a,node b){
	return a.o>b.o;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].o>>a[i].p>>a[i].q;
			a[i].m1=max(a[i].o,max(a[i].p,a[i].q));
			if(a[i].m1==a[i].o){
				a[i].p1=1;
			}
			else if(a[i].m1==a[i].p){
				a[i].p1=2;
			}
			else if(a[i].m1==a[i].q){
				a[i].p1=3;
			}
			if(a[i].o>a[i].p&&a[i].o<a[i].q||a[i].o>a[i].q&&a[i].o<a[i].p){
				a[i].m2=a[i].o;
				a[i].p2=1;
			}
			else if(a[i].p>a[i].o&&a[i].p<a[i].q||a[i].p>a[i].q&&a[i].p<a[i].o){
				a[i].m2=a[i].p;
				a[i].p2=2;
			}
			else if(a[i].q>a[i].o&&a[i].q<a[i].p||a[i].q>a[i].p&&a[i].q<a[i].o){
				a[i].m2=a[i].q;
				a[i].p2=3;
			}
			a[i].m3=min(a[i].o,min(a[i].p,a[i].q));
			if(a[i].m3==a[i].o){
				a[i].p3=1;
			}
			else if(a[i].m3==a[i].p){
				a[i].p3=2;
			}
			else if(a[i].m3==a[i].q){
				a[i].p3=3;
			}
		}
		int c1=0;
		int c2=0;
		int c3=0;
		for(int i=1;i<=n;i++){
			if(a[i].p1==1){
				c1++;
			}
			else if(a[i].p1==2){
				c2++;
			}
			else{
				c3++;
			}
		}
		if(c2==0&&c3==0){
			sort(a+1,a+n+1,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].o;
			}
			cout<<sum<<endl;
			continue;
		}
		else if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			long long sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i].m1;
			}
			cout<<sum<<endl;
			continue;
		}
		else{
			long long sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i].m1;
			}
			if(c1>n/2){
				while(c1>n/2){
					int r; 
					int t;
					long long mina=20010;
					for(int i=1;i<=n;i++){
						if(a[i].p1==1&&a[i].m1-a[i].m2<mina){
							mina=a[i].m1-a[i].m2;
							t=a[i].p2;
							r=i;
						}
					}
					if(t==2){
						a[r].p1=2;
						c2++;
					}
					else if(t==3){
						a[r].p1=3;
						c3++;
					}
					sum-=mina;
					c1--;
				}
				cout<<sum<<endl;
				continue;
			}
			else if(c2>n/2){
				while(c2>n/2){
					int r; 
					int t;
					long long mina=20010;
					for(int i=1;i<=n;i++){
						if(a[i].p1==2&&a[i].m1-a[i].m2<mina){
							mina=a[i].m1-a[i].m2;
							t=a[i].p2;
							r=i;
						}
					}
					if(t==1){
						a[r].p1=1;
						c1++;
					}
					else if(t==3){
						a[r].p1=3;
						c3++;
					}
					sum-=mina;
					c2--;
				}
				cout<<sum<<endl;
				continue;
			}
			else if(c3>n/2){
				while(c3>n/2){
					int r; 
					int t;
					long long mina=20010;
					for(int i=1;i<=n;i++){
						if(a[i].p1==3&&a[i].m1-a[i].m2<mina){
							mina=a[i].m1-a[i].m2;
							t=a[i].p2;
							r=i;
						}
					}
					if(t==1){
						a[r].p1=1;
						c1++;
					}
					else if(t==2){
						a[r].p1=2;
						c2++;
					}
					sum-=mina;
					c3--;
				}
				cout<<sum<<endl;
				continue;
			}
		}
	}
	return 0;
} 
