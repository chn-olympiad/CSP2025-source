#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int n,m,p;
}a[N],b[N],inst[N];
int ma[N],ci[N],zu[N];
int s1[N],s2[N],s3[N];
int ss1,ss2,ss3;
int n=0,cnt=0,m1=0,m2=0,m3=0;
void init(){
	ss1=0;ss2=0;ss3=0;
	memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	memset(ma,0,sizeof(ma));
	memset(ci,0,sizeof(ci));
	memset(zu,0,sizeof(zu));
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		init();
		n=0,cnt=0,m1=0,m2=0,m3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].n>>a[i].m>>a[i].p;
		}
		m1=n/2;m2=n/2;m3=n/2;
		for(int i=1;i<=n;i++){
			if(a[i].n>a[i].m&&a[i].n>a[i].p){
				ma[i]=a[i].n;
				if(m1!=0){
					inst[i].n=1;
					s1[++ss1]=ma[i];
					m1--;
				}
				if(a[i].m>a[i].p){
					ci[i]=a[i].m;
					zu[i]=a[i].p;
				}
				else{
					ci[i]=a[i].p;
					zu[i]=a[i].m;
				}
			}
			if(a[i].m>a[i].n&&a[i].m>a[i].p){
				ma[i]=a[i].m;
				if(m2!=0){
					inst[i].m=1;
					s2[++ss2]=ma[i];
					m2--;
				}
				if(a[i].n>a[i].p){
					ci[i]=a[i].n;
					zu[i]=a[i].p;
				}
				else{
					ci[i]=a[i].p;
					zu[i]=a[i].n;
				}
			}
			if(a[i].p>a[i].m&&a[i].n<a[i].p){
				ma[i]=a[i].p;
				if(m3!=0){
					inst[i].p=1;
					s3[++ss3]=ma[i];
					m3--;
				}
				if(a[i].m>a[i].n){
					ci[i]=a[i].m;
					zu[i]=a[i].n;
				}
				else{
					ci[i]=a[i].n;
					zu[i]=a[i].m;
				}
			}
		}
		for(int i=n/2;i<=n;i++){
			if(m1==0){
				for(int j=1;j<=ss1;j++){
					if(s1[j]<a[i].n&&inst[i].n!=1){
						s1[j]=a[i].n;
					}
					
				}
			}
			if(m2==0){
				for(int j=1;j<=ss2;j++){
					if(s2[j]<a[i].m&&inst[i].m!=1){
						s2[j]=a[i].m;
					}
				}

			}
			if(m3==0){
				for(int j=1;j<=ss3;j++){
					if(s3[j]<a[i].p&&inst[i].p!=1){
						s3[j]=a[i].p;
					}
					
				}
			}
		}
		for(int i=1;i<=ss1;i++){
			cnt+=s1[i];
		}
		for(int i=1;i<=ss2;i++){
			cnt+=s2[i];
		}
		for(int i=1;i<=ss3;i++){
			cnt+=s3[i];
		}
		cout<<cnt<<endl;
	}
	/*
	3
	4
	4 2 1
	3 2 4
	5 3 4
	3 5 1
	4
	0 1 0
	0 1 0
	0 2 0
	0 2 0
	2
	10 9 8
	4 0 0
	*/
	return 0;
} 
