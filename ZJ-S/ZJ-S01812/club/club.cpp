#include<bits/stdc++.h>
using namespace std;
int N;
long long ans;
int x,y,z;
int num[100005];
int m;
struct node{
	int a,b,c;
}stu[100005];
int n;
int compare(int a,int b,int c){
	if(a>=b&&a>=c)return a;
	if(b>=a&&b>=c)return b;
	else return c;
}
int com(int b,int c){
	if(b>c)return b;
	else return c;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>N;
	while(N--){
		x=0,y=0,z=0;
		cin>>n;
		ans=0;
		memset(num,0,sizeof(num));
		m=0;
		for(register int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
			if(stu[i].a>stu[i].b&&stu[i].a>stu[i].c)x++;
			if(stu[i].b>stu[i].a&&stu[i].b>stu[i].c)y++;
			if(stu[i].c>stu[i].a&&stu[i].c>stu[i].b)z++;
			ans+=compare(stu[i].a,stu[i].b,stu[i].c);
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout<<ans<<"\n";
		}
		else{
			x=compare(x,y,z);
			if(y>n/2)
				for(register int i=1;i<=n;i++)
					swap(stu[i].a,stu[i].b);
			if(z>n/2)
				for(register int i=1;i<=n;i++)
					swap(stu[i].a,stu[i].c);
			for(register int i=1;i<=n;i++){
				if(stu[i].a>stu[i].b&&stu[i].a>stu[i].c){
					m++;
					num[m]=stu[i].a-com(stu[i].b,stu[i].c);
				}
			}
			sort(num+1,num+m+1);
			for(register int i=1;i<=x-n/2;i++)ans-=num[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
