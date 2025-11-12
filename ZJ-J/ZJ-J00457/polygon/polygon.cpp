#include<bits/stdc++.h>
using namespace std;
int a[10000],n,k,b[10000];
bool f=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		int sum=0,v=1,l=1;
		for(int i=3;i<n;i++){
			v=1;l=1;
			for(int j=1;j<=i;j++){
				v*=j;
				l*=(n-j+1);
			}
			cout<<v<<" "<<l<<endl;
			sum+=l/v;
		}
		cout<<sum+1;
		return 0;
	}
//	for(int i=3;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			int t=1;
//			while(t<=i){
//				b[t]=a[j+t-1];
//				t++;
//			}
//			sort(b+1,b+t+1);
//			long long num=0;
//			for(int i=1;i<t,i++){
//				sum+=b[i];
//			}
//			if(sum>b[t])k++;
//		}
//	}
	if(n==3){
		sort(a+1,a+4);
		if((a[1]+a[2])>a[3])cout<<1;
		else cout<<0;
	}
	if(n==4){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int x=j+1;x<=n;x++){
			b[1]=a[i];b[2]=a[j];b[3]=a[x];
			long long sum=b[1]+b[2];
			if(sum>b[3])k++;
		}
		sort(a+1,a+5);
		if((a[1]+a[2]+a[3])>a[4])k++;
		cout<<k;
	}
	if(n==5){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int x=j+1;x<=n;x++){
			b[1]=a[i];b[2]=a[j];b[3]=a[x];
			long long sum=b[1]+b[2];
			if(sum>b[3])k++;
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int y=j+1;y<=n;y++)
		for(int x=y+1;x<=n;x++){
			b[1]=a[i];b[2]=a[j];b[3]=a[y];b[4]=a[x];
			long long sum=b[1]+b[2]+b[3];
			if(sum>b[4])k++;
		}
		sort(a+1,a+6);
		if((a[1]+a[2]+a[3]+b[4])>a[5])k++;
		cout<<k;
	}
	//cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}













//sort(b+1,b+t+1);
//long long num=0;
//for(int i=1;i<t,i++){
//	sum+=b[i];
//}
//if(sum>b[t])k++;