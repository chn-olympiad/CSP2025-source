#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);


// 思路：只要前面（>=2）的小棒长度大于我将要新选取的小棒A长度 那么sum++；
// 如果不满足条件也将小棒A的长度加进来，选取后一个进行判断；
// 当所有固定开头的可能都判断后，将开头前移一个；
// 注意：要用sort函数将长度数组从小到大排列才行；
// 但要保证每轮我们都将选取一个作为小棒A 其位置为Ai，只需对i以前的位置进行判断即可
//        1     2     3     4      5
	int n,a[5005];
	long long sum=0;
	cin>>n;                                       
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)//表示每一个小棒A的位置 
	{
		int sumlen=0;//初始化小棒长度总合 
		int she=2;
		for(int j=1;j<=i-2;j++)//排头的选取可能 
		{
			
			for(int o=j;o<i;o++)
			{
				sumlen+=a[o];
				if(sumlen>a[i])
				{
					sum+=i-o;
					sumlen=0;
					break;
				}
			}
		}
		sumlen=0;
		for(int j=1;j<=i-2;j++)
		{
			for(int she=2;she<i-1;she++)
			{
				if(she<=j) continue;
				int cnt=j;
				while(cnt<i)
				{
				
					if(cnt!=she)
					{
						sumlen+=a[cnt];
					}
					if(sumlen>a[i]) 
					{
						sum++;
					} 
					cnt++;
				}
				sumlen=0;
			}
		}
		
		
	}
	cout<<sum%998244353;
	return 0;
}
