#include<bits/stdc++.h>
using namespace std;
int T,n;
long long sum[4],ans,maxx;
//unsigned long long int x;
bool tpa=0,tpb=0;
struct node
{
	int a,b,c,h;
}arr[100005];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
bool tp(node x,node y)
{
	return max(x.a,x.b)>max(y.a,y.b);
}
void dfs(int step)
{
	if(step>n)
	{
		ans=0;
		for(int i=1;i<=n;i++)
  		{
				if(arr[i].h==1)
					ans+=arr[i].a;
				else if(arr[i].h==2)
					ans+=arr[i].b;
				else
					ans+=arr[i].c;
				//cout<<arr[i].h<<" ";
//				x++;
		}
//		cout<<endl;
//		cout<<"-> "<<ans<<endl;
//		cout<<"---> "<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<endl;
//		if(ans==6)
//			cout<<"@@@@@"<<endl;
		maxx=max(maxx,ans);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(sum[i]>=n/2)
		{
			continue;
		}
		sum[i]++;
		arr[step].h=i;
		dfs(step+1);
		sum[i]--;
	}
}
int main()
{

 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	cin>>T;
 	while(T--)
 	{
		cin>>n;
		sum[1]=0,sum[2]=0,sum[3]=0,ans=0;
		maxx=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			if(arr[i].b!=0||arr[i].c!=0)
				tpa=1;
			if(arr[i].c!=0)
				tpb=1;
		}
		if(tpa==0)
		{
			for(int i=1;i<=n/2;i++)
				ans+=arr[i].a;
			cout<<ans<<endl;
			continue;
		}
		else if(tpa==1&&tpb==0)
		{
			cout<<"@";
			sort(arr+1,arr+1+n,tp);
			for(int i=1;i<=n;i++)
			{
				if(arr[i].a>arr[i].b)
				{
					if(sum[1]<n/2)
					sum[1]++,ans+=arr[i].a;
					else
					sum[2]++,ans+=arr[i].b;
				}
				else if(arr[i].a<arr[i].b)
				{
					if(sum[2]<n/2)
					sum[2]++,ans+=arr[i].b;
					else
					sum[1]++,ans+=arr[i].a;
				}
				else
				{
					if(sum[1]<sum[2])
						sum[1]++;
					else
						sum[2]++;
					ans+=arr[i].a;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		else
		{
			dfs(1);
			cout<<maxx<<endl;
		}

	}
//	cout<<x;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int T,n,sum[4],ans;
struct node
{
	int a,b,c,maxx,h;
}arr[100005];
bool cmp(node x,node y)
{
	return x.maxx>y.maxx;
}
int main()
{
 	//freopen("club.in","r",stdin);
 	//freopen("club.out","w",stdout);
 	cin>>T;
 	while(T--)
 	{
		cin>>n;
		sum[1]=0,sum[2]=0,sum[3]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			if(arr[i].a>arr[i].b&&arr[i].a>arr[i].c)
				arr[i].h=1,arr[i].maxx=arr[i].a;
			else if(arr[i].b>arr[i].c&&arr[i].b>arr[i].a)
				arr[i].h=2,arr[i].maxx=arr[i].b;
			else if(arr[i].c>arr[i].b&&arr[i].c>arr[i].a)
				arr[i].h=3,arr[i].maxx=arr[i].c;
		}
		sort(arr+1,arr+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(arr[i].maxx==-1)
				break;
			if(sum[arr[i].h]<n/2)
			{
				sum[arr[i].h]++;
				ans+=arr[i].maxx;
				arr[i].maxx=-1;
				//cout<<"@@@"<<endl;
			}
			else
			{
				if(arr[i].h==1)
					if(arr[i].b>=arr[i].c)
						arr[i].h=2,arr[i].maxx=arr[i].b;
					else if(arr[i].b<arr[i].c)
						arr[i].h=3,arr[i].maxx=arr[i].c;
				else if(arr[i].h==2)
					if(arr[i].a>=arr[i].c)
						arr[i].h=1,arr[i].maxx=arr[i].a;
					else if(arr[i].a<arr[i].c)
						arr[i].h=3,arr[i].maxx=arr[i].c;
				else
					if(arr[i].a>=arr[i].b)
						arr[i].h=1,arr[i].maxx=arr[i].a;
					else if(arr[i].a<arr[i].b)
						arr[i].h=2,arr[i].maxx=arr[i].b;
				sort(arr+1,arr+1+n,cmp);
				i=0;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
*/
