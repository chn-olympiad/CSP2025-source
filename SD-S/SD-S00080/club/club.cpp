#include<bits/stdc++.h>
using namespace std;
int t,n;
struct jj{
	int x,y,z,mm,i1,i2;
}a[200001];
bool cmp(jj w,jj v){
	return w.mm>v.mm;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if(a[i].y>=a[i].z){
					a[i].mm=a[i].x-a[i].y;
					a[i].i1=1;
					a[i].i2=2;
				}else{
					a[i].mm=a[i].x-a[i].z;
					a[i].i1=1;
					a[i].i2=3;}
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if(a[i].z>=a[i].x){
					a[i].mm=a[i].y-a[i].z;
					a[i].i1=2;
					a[i].i2=3;
				}else{
					a[i].mm=a[i].y-a[i].x;
					a[i].i1=2;
					a[i].i2=1;}
			}else{
				if(a[i].y>=a[i].x){
					a[i].mm=a[i].z-a[i].y;
					a[i].i1=3;
					a[i].i2=2;
				}else{
					a[i].mm=a[i].z-a[i].x;
					a[i].i1=3;
					a[i].i2=1;}
			}
		}
		sort(a+1,a+n+1,cmp);
		int b[4]={0,0,0,0};
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(a[i].i1==1){
				if(b[1]==n/2){
					if(a[i].i2==2){
						sum+=a[i].y;
						b[2]++;
					}else{
						sum+=a[i].z;
						b[3]++;}
				}else{
					sum+=a[i].x;
					b[1]++;}
			}
			if(a[i].i1==2){
				if(b[2]==n/2){
					if(a[i].i2==3){
						sum+=a[i].z;
						b[3]++;
					}else{
						sum+=a[i].x;
						b[1]++;}
				}else{
					sum+=a[i].y;
					b[2]++;}
			}
			if(a[i].i1==3){
				if(b[3]==n/2){
					if(a[i].i2==2){
						sum+=a[i].y;
						b[2]++;
					}else{
						sum+=a[i].x;
						b[1]++;}
				}else{
					sum+=a[i].z;
					b[3]++;}
			}
		}
		cout<<sum<<endl;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
