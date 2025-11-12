#include<bits/stdc++.h>
using namespace std;
int a[100020][5];
int qun1[]={1,1,0,0};
int qun2[]={1,0,1,0};
int qun3[]={0,1,0,1};
int qun4[]={0,0,1,1};
int rett[100020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,c=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++){
			cin>>a[i][j];
			}
			c++;
			rett[c]=a[i][1];
		}
		int ret=0;
		int ans=max(a[1][1],max(a[1][2],a[1][3]));
		int ans_wei=1;
		if(a[1][2]==ans)
		{
			ans_wei++;
		}
		if(a[1][3]==ans)
		{
			ans_wei+=2;
		}
		int ans1=max(a[2][1],max(a[2][2],a[2][3]));
		int ans1_wei=1;
		if(a[2][2]==ans1)
		{
			ans1_wei++;
		}
		if(a[2][3]==ans1)
		{
			ans1_wei+=2;
		}
		if(n==2)
		{
			if(ans1_wei==ans_wei)
			{
				ret=max(ans+a[2][1]+a[2][2]+a[2][3]-max(a[2][1],max(a[2][2],a[2][3]))-min(a[2][1],min(a[2][2],a[2][3])),ans1+a[1][1]+a[1][2]+a[1][3]-max(a[1][1],max(a[1][2],a[1][3]))-min(a[1][1],min(a[1][2],a[1][3])));
			}
			else
			{
				ret=ans+ans1;
			}
			cout<<ret<<endl;
		}
		else if(n==4)
		{
			int ans2=max(a[3][1],max(a[3][2],a[3][3]));
			int ans2_wei=1;
			if(a[3][2]==ans2)
			{
				ans2_wei++;
			}
			if(a[3][3]==ans2)
			{
				ans2_wei+=2;
			}
			int ans3=max(a[4][1],max(a[4][2],a[4][3]));
			int ans3_wei=1;
			if(a[4][2]==ans3)
			{
				ans3_wei++;
			}
			if(a[4][3]==ans3)
			{
				ans3_wei+=2;
			}
			if(ans1_wei==ans_wei&&ans2_wei==ans_wei&&ans3_wei==ans_wei)
			{
				sort(a[1]+1,a[1]+4);
				sort(a[2]+1,a[2]+4);
				sort(a[3]+1,a[3]+4);
				sort(a[4]+1,a[4]+4);
				for(int i=0;i<4;i++)
				{
					int cnt=0;
					if(qun1[i]==1)
					{
						cnt+=a[1][3];
					}
					else
					{
						cnt+=a[1][2];
					}
					if(qun2[i]==1)
					{
						cnt+=a[2][3];
					}
					else
					{
						cnt+=a[2][2];
					}
					if(qun3[i]==1)
					{
						cnt+=a[3][3];
					}
					else
					{
						cnt+=a[3][2];
					}
					if(qun4[i]==1)
					{
						cnt+=a[4][3];
					}
					else
					{
						cnt+=a[4][2];
					}
					ret=max(ret,cnt);
				}
			}
			else
			{
				ret=ans+ans1+ans3+ans2;
			}
			cout<<ret<<endl;
		}
		else
		{
			sort(rett+1,rett+1+c);
			for(int i=n/2+1;i<=n;i++)
			{
				ret+=rett[i];
			}
			cout<<ret;
		}
	}
	return 0;
}
