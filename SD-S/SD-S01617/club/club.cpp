#include<bits/stdc++.h>
using namespace std;
int t,n,yb,_1,_2,_3,a[100004],pp=0,sum;
/*void jh(int a,int b){
	int c=a;
	a=b;b=c;
	return a,b;
}*/
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;++k){
		cin>>n;
		yb=n/2;
		for(int i=1;i<=n;++i){
			cin>>a[i]>>_1>>_2;
		}
		sum=0;
			int p=1;
			for(;p!=0;){
				p=0;
				for(int i=1;i<=n;++i){
					if(a[i]<a[i+1]){
						int temp=a[i];
						a[i]=a[i+1],a[i+1]=temp;
						p=1;
						for(int j=1;j<=n;++j){
						//	cout<<p<<" ";
						}
					}
				}
				
			}
			//cout<<endl;
			for(int i=1;i<=yb;++i){
				sum+=a[i];//cout<<a[i]<<endl;
			}
			cout<<sum<<endl;
			sum=0;
		}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*2
4
4 0 0
6 0 0
9 0 0
2 0 0
6
8 0 0
4 0 0
9 0 0
0 0 0
1 0 0
3 0 0
怎么骗分都这么难QWQ*/
