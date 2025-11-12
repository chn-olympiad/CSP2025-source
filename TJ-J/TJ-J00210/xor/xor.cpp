//#include <bits/stdc++.h>//这题这方法包超时的牢弟 左右指针来个暴力再说，能骗一点是一点 彳亍，一分没拿 
//using namespace std;
//struct fuck
//{
//	long long num;
//	string xorn;
//	bool use;
//}a[500005];
//string to2(long long x)
//{
//	string str;
//	while(x)
//	{
//		char temp = (x % 2) + '0';
//		str = temp + str;
//		x/=2;
//	}
//	return str;
//}
//string xorn(string x,string y)
//{
//	long long len1 = x.length(),len2 = y.length();
//	long long len3 = max(len1,len2);
//	string ans = "";
//	long long cnt = 0;
//	if(len1<len2)
//	{
//		for(int i = len1;i<len2;i++)
//			x[i] = '0';
//	}
//	else
//	{
//		for(int i = len2;i<len1;i++)
//			y[i] = '0';
//	}
//	int i;
//	for(i=0;i<len3;i++)
//	{
//		if(x[i] == y[i])
//			ans  = "0"+ans;
//		else
//			ans = "1"+ans;
//	}
//	return ans;
//}
//long long to10(string x)
//{
//	long long i,len3 = x.length(),cnt = 0;
//	for(i=0;i<len3;i++)
//	{
//		cnt+=pow(2,i)*(x[i]-'0');
//	}
//	return cnt;
//}
//long long n,k,ans;
//int main()
//{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
//	cin>>n>>k;
//	int i;
//	long long L = 1,R,x;
//	for(i=1;i<=n;i++)
//	{
//		cin>>a[i].num;
//		a[i].xorn = to2(a[i].num);
//	}
//	int j;
//	for(i=1;i<=n;i++)
//	{
//		for(j=1;R<=n;j++)
//		{
//			L = j,R+=L+i-1;
//			if(i==1 && a[L].num == k && a[L].use == 0)
//			{
//				ans++;
//				a[L].use = 1;
//			}
//			else
//			{
//				bool flag =1;
//				string temp = a[L].xorn;
//				for(int q = L+1;q<=R;q++)
//				{
//					if(a[q].use == 1)
//					{
//						flag = 0;
//						break;
//					}
//					temp = xorn(a[q].xorn,temp);
//				}
//				if(to10(temp) == k && flag)
//				{
//					ans++;
//				}
//			}
//		}
//	}
//	cout<<ans+1;
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	if(x == y && x!=0 && y!=0)
		return 0;
	else
		return 1;
}
struct s
{
	int num;
	bool use;
}a[105];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans;
	cin>>n>>k;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i].num;
	}
	for(int i =1;i<=n;i++)
	{
		if(a[i].num == k && a[i].use == 0)
		{
			ans++;
			a[i].use = 1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+i<=n;j++)
		{
				if(a[j].use == 1)
				{
					continue;
				}
				bool flag =1;
				int temp = 0;
				temp = a[j].num;
				for(int q = j+1;q<=j+i;q++)
				{
					if(a[q].use == 1)
					{
						flag = 0;
						break;
					}
					temp+=cmp(a[q].num,temp);
				}
				if(flag && temp == k)
				{
					ans++;
					for(int q=j;q<=j+i;q++)
						a[q].use = 1;
				}	
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
