#include<bits/stdc++.h>
using namespace std;
int t,n,l1,l2,l3,ans;
struct student{
	int a1;
	int a2;
	int a3;
}stu[100010],s1[100010],s2[100010],s3[100010];
bool cmp1(student x,student y){
	return x.a1-max(x.a2,x.a3)>y.a1-max(y.a2,y.a3);
}
bool cmp2(student x,student y){
	return x.a2-max(x.a1,x.a3)>y.a2-max(y.a1,y.a3);
}
bool cmp3(student x,student y){
	return x.a3-max(x.a2,x.a1)>y.a3-max(y.a2,y.a1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&stu[i].a1,&stu[i].a2,&stu[i].a3);
			if(stu[i].a1>=stu[i].a2&&stu[i].a1>=stu[i].a3)
				s1[++l1]=stu[i];
			else if(stu[i].a2>=stu[i].a1&&stu[i].a2>=stu[i].a3)
				s2[++l2]=stu[i];
			else
				s3[++l3]=stu[i];
		}
		if(l1>n/2){
			sort(s1+1,s1+l1+1,cmp1);
			while(l1>n/2){
				if(s1[l1].a2>s1[l1].a3&&l2+1<=n/2)
					s2[++l2]=s1[l1];
				else if(l3+1<=n/2)
					s3[++l3]=s1[l1];
				s1[l1--]={0,0,0};
			}
		}
		if(l2>n/2){
			sort(s2+1,s2+l2+1,cmp2);
			while(l2>n/2){
				if(s2[l2].a1>s2[l2].a3&&l1+1<=n/2)
					s1[++l1]=s2[l2];
				else if(l3+1<=n/2)
					s3[++l3]=s2[l2];
				s2[l2--]={0,0,0};
			}
		}
		if(l3>n/2){
			sort(s3+1,s3+l3+1,cmp3);
			while(l3>n/2){
				if(s3[l3].a1>s3[l3].a2&&l1+1<=n/2)
					s1[++l1]=s3[l3];
				else if(l2+1<=n/2)
					s2[++l2]=s3[l3];
				s3[l3--]={0,0,0};
			}
		}
		for(int i=1;i<=l1;i++)
			ans+=s1[i].a1;
		for(int i=1;i<=l2;i++)
			ans+=s2[i].a2;
		for(int i=1;i<=l3;i++)
			ans+=s3[i].a3;
		printf("%d\n",ans);
		ans=0;
		l1=l2=l3=0;
		for(int i=1;i<=n;i++)
			stu[i]=s1[i]=s2[i]=s3[i]={0,0,0};
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
