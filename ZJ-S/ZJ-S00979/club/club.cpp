#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+5;
int arr[N][6];
bool cmp1(int a[],int b[])
{
	int a1=a[4],b1=b[4];
	return arr[a1]>arr[b1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	bool flag=true;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int nx[4]={0,0,0,0},ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			int ma_1=-0x3f3f3f,ma_2=-0x3f3f3f,mak_1,mak_2;
			for(int j=1;j<=3;j++)
			{
			if(arr[i][j]>ma_1) {
				ma_2=ma_1;
				mak_2=mak_1;
				ma_1=arr[i][j];
				mak_1=j;
			
			}
			else if(arr[i][j]>ma_2){
				ma_2=arr[i][j];
				mak_2=i;
				}}
			arr[i][4]=mak_1,arr[i][5]=mak_2;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				if(arr[arr[j][4]]<arr[arr[j+1][4]]) swap(arr[j],arr[j+1]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			int a=arr[i][4],b=arr[i][5];
			if(nx[a]<n/2){
				ans+=arr[i][a];
				nx[a]++;
			}
			else{
				nx[b]++;
				ans+=arr[i][b];
							}
		}
		cout<<ans<<endl;
	}
	return 0;
}
