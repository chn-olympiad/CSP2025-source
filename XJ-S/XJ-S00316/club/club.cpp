#include<bits/stdc++.h>
using namespace std;
long long t,n,num1,num2;
long long ans1[100005],ans2[100005];
long long cnt1,cnt2,vis[100005];
long long bbq,sum,sum1,sum2;
long long sum11,sum22,sum3,sum4;
struct node{
	long long l1,l2,l3;
	long long ch12;
}a[100005];
int ll(long long a){
	if(a>0){
		return a;
	}
	return (a*-1);
}
bool f1(){
	for(long long i=1;i<=n;i++){
		if(vis[i]==2){
			continue;
		}
		if(i!=n&&a[i].ch12<a[i+1].ch12){
			return 1;
		}
	}
	return 0;
}
bool f2(){
	for(long long i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		if(i!=n&&a[i].ch12<a[i+1].ch12){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long k=1;k<=t;k++){
		cnt1=0;
		cnt2=0;
		sum1=0;
		sum11=0;
		sum2=0;
		sum22=0;
		sum3=0;
		sum4=0;
		bbq=0;
		sum=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].l1>>a[i].l2>>a[i].l3;
			long long q=a[i].l1-a[i].l2;
			a[i].ch12=ll(q);
			if(a[i].l1>a[i].l2){
				vis[i]=1;
				cnt1++;
				ans1[cnt1]=i;
			}else{
				vis[i]=2;
				cnt2++;
				ans2[cnt2]=i;
			}
		}	
		if(cnt1>n/2){
			while(f1()){
				for(long long i=1;i<n;i++){
					if(a[i].ch12<a[i+1].ch12){
						node z=a[i];
						a[i]=a[i+1];
						a[i+1]=z;
					}
				}
			}
			for(long long i=1;i<=n;i++){
				if(bbq==(cnt1-n)/2){
					break;
				}
				if(vis[i]==2){
					continue;
				}
				vis[i]=2;
				bbq++;
			}
		}else{
			if(cnt2>n/2){
				while(f2()){
					for(long long i=1;i<n;i++){
						if(a[i].ch12<a[i+1].ch12){
							node z=a[i];
							a[i]=a[i+1];
							a[i+1]=z;
						}
					}
				}
				for(long long i=1;i<=n;i++){
					if(bbq==(cnt2-n)/2){
						break;
					}
					if(vis[i]==1){
						continue;
					}
					vis[i]=1;
					bbq++;
				}
			}
		}
		for(long long i=1;i<=n/2;i++){
			sum1+=a[i].l1;
			sum11+=a[i].l2;
		}
		for(long long i=n/2+1;i<=n;i++){
			sum2+=a[i].l1;
			sum22+=a[i].l2;
		}
		sum3=sum1+sum22;
		sum4=sum11+sum2;
		sum=max(sum3,sum4);
		cout<<sum<<endl; 
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
