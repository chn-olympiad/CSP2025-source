#include<bits/stdc++.h>
using namespace std;
struct club{
	int one,two,three,ans;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		int flag1=0,flag2=0,flag3=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].one,&a[i].two,&a[i].three);		
			if(max(max(a[i].one,a[i].two),a[i].three)==a[i].one)a[i].ans=1,flag1++;
			if(max(max(a[i].one,a[i].two),a[i].three)==a[i].two)a[i].ans=2,flag2++;
			if(max(max(a[i].one,a[i].two),a[i].three)==a[i].three)a[i].ans=3,flag3++;
		}
		if(flag1>n/2)
		{
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
					if(a[i].one-max(a[i].three,a[i].two)>a[j].one-max(a[j].three,a[j].two))swap(a[i],a[j]);
			for(int i=1;i<=n/2;i++){
				if(a[i].ans==1 && a[i].two>a[i].three)a[i].ans=2,flag1--;
				else if(a[i].ans==1 && a[i].two>a[i].three)a[i].ans=3,flag1--;
				if(flag1==n/2)break;
			}
		}
		if(flag2>n/2)
		{
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
					if(a[i].two-max(a[i].three,a[i].one)>a[j].two-max(a[j].three,a[j].one))swap(a[i],a[j]);
			for(int i=1;i<=n/2;i++){
				if(a[i].ans==2 && a[i].one>a[i].three)a[i].ans=1,flag2--;
				else if(a[i].ans==2 && a[i].one<a[i].three)a[i].ans=3,flag2--;
				if(flag2==n/2)break;
			}		
		}
		if(flag3>n/2)
		{
			for(int i=1;i<=n;i++)
				for(int j=i;j<=n;j++)
					if(a[i].three-max(a[i].one,a[i].two)>a[j].three-max(a[j].one,a[j].two))swap(a[i],a[j]);
			for(int i=1;i<=n/2;i++){
				if(a[i].ans==3 && a[i].two>a[i].one)a[i].ans=2,flag3--;
				else if(a[i].ans==3 && a[i].two<a[i].one)a[i].ans=1,flag3--;
				if(flag3==n/2)break;
			}		
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].ans==1)sum+=a[i].one;
			if(a[i].ans==2)sum+=a[i].two;
			if(a[i].ans==3)sum+=a[i].three;
		}
		cout<<sum<<endl;
	}
	return 0;
}
