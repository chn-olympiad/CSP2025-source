#include<bits/stdc++.h>
using namespace std;
int t,n,f[100005];
struct stu{
	int x,y,z;
}a[100005];
bool cmp(stu x,stu y){
	int mx=max(x.x,max(x.y,x.z)),my=max(y.x,max(y.y,y.z));
	if(mx>my)return true;
	if(mx==my){
		if(x.x>y.x)return true;
		if(x.y>y.y)return true;
		if(x.z>y.z)return true;
	}
	else return false;
}
bool cmp1(stu x,stu y){
	return x.x>y.x;
}
bool cmp2(stu x,stu y){
	return x.x>x.y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sum1=0,sum2=0,sum3=0,ans=0,num1=0,num2=0;
		for(int i=1;i<=n;i++){
			int d,e,f;
			cin>>d>>e>>f;
			a[i].x=d,a[i].y=e,a[i].z=f;
			sum1+=d,sum2+=e,sum3+=f;
		}
		if(sum3==0){
			if(sum2==0){
				sort(a+1,a+1+n,cmp1);
				for(int i=1;i<=n>>1;i++)ans+=a[i].x;
				cout<<ans;
				continue;
			}
			sort(a+1,a+1+n,cmp2);
			int FUCKCCF;
			for(int i=1;i<=n;i++){
				if(a[i].x<a[i].y){
					FUCKCCF=i;
					break;
				}
			}
			if(FUCKCCF<=n/2)for(int i=1;i<=FUCKCCF;i++)num1+=a[i].x;
			else{
				for(int i=1;i<=n/2;i++)num1+=a[i].x;
				for(int i=n/2+1;i<=n;i++)num2+=a[i].y;
			}
			cout<<num1+num2<<endl;
			continue;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		int maxo=n>>1,c1=0,c2=0,c3=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			int md=0;
			if(a[i].x>a[i].y&&a[i].y>a[i].z)md=1;
			if(a[i].y>a[i].x&&a[i].y>a[i].z)md=2;
			if(a[i].z>a[i].y&&a[i].z>a[i].x)md=3;
			if(md==1&&c1<maxo||!md&&a[i].x==a[i].y&&c1<maxo||!md&&a[i].x==a[i].z&&c1<maxo){
				c1++;
				ans+=a[i].x;
				continue;
			}
			else if(md==2&&c2<maxo||!md&&a[i].x==a[i].y&&c2<maxo||!md&&a[i].y==a[i].z&&c2<maxo){
				c2++;
				ans+=a[i].y;
				continue;
			}
			else if(md==3&&c3<maxo||!md&&a[i].x==a[i].z&&c3<maxo||!md&&a[i].y==a[i].z&&c3<maxo){
				c3++;
				ans+=a[i].z;
				continue;
			}
			else{
				if(c1<maxo){
					c1++;
					ans+=a[i].x;
				}
				else if(c2<maxo){
					c2++;
					ans+=a[i].y;
				}
				else if(c3<maxo){
					c3++;
					ans+=a[i].z;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}