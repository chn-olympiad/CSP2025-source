#include<bits/stdc++.h>
using namespace std;
struct sd{
	int a1,a2,a3,flag,m;
}a[100005];
int t,n,flag1,flag2,cnt,flag[5],flagd[5][5];
int cmp(sd x,sd y){
	return x.m>y.m;
}
int cmp1(sd x,sd y){
	return x.a1<y.a1;
}
int cmp2(sd x,sd y){
	return x.a2<y.a2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0){
				flag1=1;
			}
			if(a[i].a3!=0){
				flag2=1;
			}
		}
		if(flag1==0&&flag2==0){
			sort(a+1,a+1+n,cmp1);
			for(int i=n;i>n/2;i--){
				cnt+=a[i].a1;
			}
			cout<<cnt<<"\n";
		}else if(flag2==0){
			for(int i=1;i<=n;i++){
				if(a[i].a1>a[i].a2){
					cnt+=a[i].a2;
					a[i].a1-=a[i].a2;
					a[i].a2=0;
				}else{
					cnt+=a[i].a1;
					a[i].a2-=a[i].a1;
					a[i].a1=0;
				}
			}
			sort(a+1,a+1+n,cmp1);
			for(int i=n;i>n/2;i--){
				cnt+=a[i].a1;
			}
			sort(a+1,a+1+n,cmp2);
			for(int i=n;i>n/2;i--){
				cnt+=a[i].a2;
			}
			cout<<cnt<<"\n";
		}else{
			for(int i=1;i<=n;i++){
				if(a[i].a1<=a[i].a2&&a[i].a1<=a[i].a3){
					cnt+=a[i].a1;
					a[i].a2-=a[i].a1;
					a[i].a3-=a[i].a1;
					a[i].a1=0;
				}else if(a[i].a2<a[i].a1&&a[i].a2<=a[i].a3){
					cnt+=a[i].a2;
					a[i].a1-=a[i].a2;
					a[i].a3-=a[i].a2;
					a[i].a2=0;
				}else{
					cnt+=a[i].a3;
					a[i].a1-=a[i].a3;
					a[i].a2-=a[i].a3;
					a[i].a3=0;
				}
				if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
					a[i].m=min(a[i].a1-a[i].a2,a[i].a1-a[i].a3);
				}else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
					a[i].m=min(a[i].a2-a[i].a1,a[i].a2-a[i].a3);
				}else{
					a[i].m=min(a[i].a3-a[i].a1,a[i].a3-a[i].a2);
				}
			}
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3&&flag[1]<n/2){
					if(flag[1]<n/2){
						flag[1]++;
						cnt+=a[i].a1;
					}else{
						if(flagd[1][2]>0){
							flagd[1][2]--;
							cnt+=a[i].a1;
						}else if(flagd[1][3]>0){
							flagd[1][3]--;
							cnt+=a[i].a1;
						}else if(a[i].a2>a[i].a3){
							flag[2]++;
							cnt+=a[i].a2;
						}else if(a[i].a2==a[i].a3){
							flagd[2][3]++;
							cnt+=a[i].a2;
						}else{
							flag[3]++;
							cnt+=a[i].a3;
						}
					}
				}else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
					if(flag[2]<n/2){
						flag[2]++;
						cnt+=a[i].a2;
					}else if(a[i].a1==a[i].a3){
						flagd[1][3]++;
						cnt+=a[i].a1;
					}else{
						if(flagd[1][2]>0){
							flagd[1][2]--;
							cnt+=a[i].a2;
						}else if(flagd[2][3]>0){
							flagd[2][3]--;
							cnt+=a[i].a2;
						}else if(a[i].a1>=a[i].a3){
							flag[1]++;
							cnt+=a[i].a1;
						}else{
							flag[3]++;
							cnt+=a[i].a3;
						}
					}
				}else{
					if(flag[3]<n/2){
						flag[3]++;
						cnt+=a[i].a3;
					}else if(a[i].a2==a[i].a1){
						flagd[1][2]++;
						cnt+=a[i].a2;
					}else{
						if(flagd[1][3]>0){
							flagd[1][3]--;
							cnt+=a[i].a1;
						}else if(flagd[2][3]>0){
							flagd[2][3]--;
							cnt+=a[i].a1;
						}else if(a[i].a2>=a[i].a1){
							flag[2]++;
							cnt+=a[i].a2;
						}else{
							flag[1]++;
							cnt+=a[i].a1;
						}
					}
				}
			}
			cout<<cnt<<"\n";
		}
		cnt=0,flag1=0,flag2=0;
		for(int i=1;i<=3;i++){
			flag[i]=0;
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=3;j++){
				flagd[i][j]=0;
			}
		}
	}
	return 0;
}