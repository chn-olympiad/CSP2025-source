#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct stu{
	int a1,a2,a3,h;
}a[N];
bool cmp1(stu a1,stu a2){
	return a1.a1>a2.a1;
}
bool cmp2(stu a1,stu a2){
	return a1.a2>a2.a2;
}
bool cmp3(stu a1,stu a2){
	return a1.a3>a2.a3;
}
int T,n,sum,ma,k1,k2,k3;
bool kkk=true,KKK=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(--T>=0){
		sum=0;
		memset(a,0,sizeof(a));
		k1=k2=k3=ma=0;
		kkk=KKK=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(!((a[i].a2==0)&&(a[i].a3==0))) kkk=false;
			if(a[i].a3!=0) KKK=false;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++){
			sum+=a[i].a1;
			a[i].h=1;
			k1++;
		}
		if(kkk){
			cout<<sum;
			continue;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n/2;i++){
			if(a[i].h==1){
				sum-=a[i].a1;
				sum+=max(a[i].a1,a[i].a2);
				if(a[i].a2>a[i].a1){
					a[i].h=2;
					k1--;
					k2++;
				}
			}else{
				sum+=a[i].a2;
				a[i].h=2;
				k2++;
			}
		}
		if(!KKK){
			sort(a+1,a+n+1,cmp3);
			for(int i=1;i<=n/2;i++){
				if(a[i].h==1){
					sum-=a[i].a1;
					sum+=max(a[i].a1,a[i].a3);
					if(a[i].a3>a[i].a1){
						a[i].h=3;
						k1--;
						k3++;
					}
				}else if(a[i].h==2){
					sum-=a[i].a2;
					sum+=max(a[i].a2,a[i].a3);
					if(a[i].a3>a[i].a2){
						a[i].h=3;
						k2--;
						k3++;
					}
				}else{
					sum+=a[i].a3;
					a[i].h=3;
					k3++;
				}
			}
		}
		for(int i=n/2+1;i<=n;i++){
			if(a[i].h==0){
				if(k1<n/2){
					ma=max(ma,a[i].a1);
				}
				if(k2<n/2){
					ma=max(ma,a[i].a2);
				}
				if(k3<n/2){
					ma=max(ma,a[i].a3);
				}
				if(a[i].a1>a[i].a2){
					if(a[i].a1>a[i].a3){
						k1++;
					}
					if(a[i].a1<a[i].a3){
						k3++;
					} 
				}else if(a[i].a1<a[i].a2){
					if(a[i].a2>a[i].a3){
						k2++;
					}
					if(a[i].a2<a[i].a3){
						k3++;
					} 
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
