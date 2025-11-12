#include<iostream>
#include<algorithm>
using namespace std;
int max1,max2,max3,max4,max5,max6;
int t,n;
void maxn(int a,int b,int c){
	if(a>b&&b>c){max1=a;max2=1;max3=b;max4=2;max5=c;max6=3;}
	else if(b>a&&a>c){max1=b;max2=2;max3=a;max4=1;max5=c;max6=3;}
	else if(a>c&&c>b){max1=a;max2=1;max3=c;max4=3;max5=b;max6=2;}
	else if(c>a&&a>b){max1=c;max2=c;max3=a;max4=1;max5=b;max6=2;}
	else if(b>c&&c>a){max1=b;max2=2;max3=c;max4=3;max5=a;max6=1;}
	else{max1=c;max2=3;max3=b;max4=2;max5=a;max6=1;}
	return;
}
struct r{
	int x,y,z;
};
r a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n-1;i++)for(int j=i+1;j<=n;j++)if(max(a[i].x,max(a[i].y,a[i].z))<max(a[i].x,max(a[i].y,a[i].z)))swap(a[i],a[j]);
		int sumx[4]={0,0,0,0};
		long long sum=0;
		for(int i=1;i<=n;i++){
			maxn(a[i].x,a[i].y,a[i].z); 
			if(sumx[max2]<n/2){sum+=max1;sumx[max2]++;}
			else if(sumx[max4]<n/2){sum+=max3;sumx[max4]++;}
			else {sum+=max5;sumx[max6]++;}
		}
		cout<<sum<<endl;
	}
	return 0;
}
