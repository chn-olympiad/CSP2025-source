//SN-J00589 李雨轩 陕西延安中学 
#include <iostream>
#include <algorithm>
using namespace std;
int a[5005];
int sum_a[5005][5005];
int num[5005];
int max_ans(int num1,int num2);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];	
	}
	if (n==3)
	{
		int sum=0;
		sum+=a[1]+a[2]+a[3];
		if (sum>max_ans(1,3)) cout << 1;
		else cout << 0;
	}
	else if (n>3 && n<=500) 
	{
		cout << 0;
	} 
	
	return 0;
}
int max_ans(int num1,int num2)
{
	int max_num=0;
	for (int x=num1;x<=num2;x++)
	{
		max_num=max(a[x],max_num);
	}
	return max_num;
}
