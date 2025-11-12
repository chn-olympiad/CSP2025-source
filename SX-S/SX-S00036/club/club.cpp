#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct A{
	int x,y,z;
	bool flag,flag1,flag2;
}a[N];
int t,n,sum,b[101],c[101];
inline bool cmp(A a,A b){
	return a.x>b.x;
}
inline bool cmp1(A a,A b){
	return a.y>b.y;
}
inline bool cmp2(A a,A b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int num=0;sum=n/2;int js=0;bool pd=false;
		if(n==2){
			for(int i=1;i<=3;i++){
				cin>>b[i];
			}
			for(int i=1;i<=3;i++){
				cin>>c[i];
			}
			num=max(b[1]+c[2],b[1]+c[2]);
			num=max(num,max(b[2]+c[1],b[2]+c[3]));
			num=max(num,max(b[3]+c[2],b[3]+c[1]));
			cout<<num<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].flag=a[i].flag1=a[i].flag2=false;
			if(a[i].y!=0||a[i].z!=0){
				pd=true;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=sum;i++){
			num+=a[i].x;
			a[i].flag=true;
		}
		if(pd==false){
			cout<<num<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].flag==false){num+=a[i].y;a[i].flag=true;js++;a[i].flag2=true;
				if(js>=sum){js=0;break;}
			}else{
				if(a[i].x>a[i].y){a[i].flag1=true;continue;
				}else if(a[i].y>a[i].x){
					a[i].flag2=true;
					num-=a[i].x;
					num+=a[i].y;
					js++;
					if(js>=sum){js=0;break;}
				}
			}
		}
		sort(a+1,a+n+1,cmp2);js=0;
		for(int i=1;i<=n;i++){
			if(a[i].flag==false){
				num+=a[i].z;
				js++;
				if(js>=sum){
					break;
				}
			}else if(a[i].flag1==true){
				if(a[i].x>a[i].z){continue;
				}else if(a[i].z>a[i].x){num-=a[i].x;num+=a[i].z;js++;
					if(js>=sum){break;}
				}
			}else if(a[i].flag2==true){
				if(a[i].y>a[i].z){continue;
				}else if(a[i].z>a[i].y){
					num-=a[i].y;
					num+=a[i].z;
					js++;
					if(js>=sum){break;}
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}