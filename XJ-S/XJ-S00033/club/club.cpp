#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a1;
	long long b;
	long long c;
};
node a[100001];
int z[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","w",stdout);
	int k;
	cin>>k;
	int a2=0,b2=0,c2=0;
	long long n;
	while(k>=0){
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].a1>>a[i].b>>a[i].c;
			
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			z[i]=0;
			if(z[i]<=a[i].a1){
				z[i]=0;
				if(a2<=n/2){
					z[i]+=a[i].a1;
					a2++;
				}else if(a[i].b>a[i].c){
					if(b2<=n/2){
						z[i]+=a[i].b;
						b2++;
					}else{
						z[i]+=a[i].c;
						c2++;
					}
				}
				if(z[i]<=a[i].b){
					z[i]=0;
				if(b2<=n/2){
					z[i]+=a[i].b;
					b2++;
				}else if(a[i].a1>a[i].c){
					if(a2<=n/2){
						z[i]+=a[i].a1;
						a2++;
					}else{
						z[i]+=a[i].c;
						c2++;
					}
				}
				}else{
					if(z[i]<=a[i].c){
					z[i]=0;
				if(c2<=n/2){
					z[i]+=a[i].c;
					c2++;
				}else if(a[i].a1>a[i].b){
					if(a2<=n/2){
						z[i]+=a[i].a1;
						a2++;
					}else{
						z[i]+=a[i].b;
						b2++;
					}
				}
					z[i]+=a[i].c;
					}
				}
			
				}

			}
					for(int j=0;j<n;j++){
					cnt+=z[j];
				}
				cout<<cnt<<endl;
			k--;
		}
		
		return 0;
	} 
