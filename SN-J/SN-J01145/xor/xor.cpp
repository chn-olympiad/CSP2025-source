//韩心尧 SN-J01145 西安滨河学校
#include <bits/stdc++.h>
#define N 500010

using namespace std;

int n,k;
int a[N];
int num_pre[N];//pre[i][j]:二进制下第i位在前j个数中出现的次数
//bool pop[25];//pop[i]：存k的二进制分解，1要求奇数，0要求偶数
int ans;
int lst = -1;
//map<int,int> mp[N],vis;
//set<int> s;

//int chk_ou(int j,int len)
//{
//	int tf;
//	if ((pre[j][lst + 1] % 2 == 1 && len >= 2) || pre[j][lst + 1] % 2 == 0)//中间有偶数（开头为奇数且长度大于等于1 或 开头为偶数
//	{
//
//		tf = 1;
//	}
//	else
//	{
//		tf = 0;
//
//	}
//	return tf;
//}
//int chk_ji(int j,int len)
//{
//	int tf;
//	if ((pre[j][lst + 1] % 2 == 0 && len >= 2) || pre[j][lst + 1] % 2 == 1)//中间有奇数（开头为偶数且长度大于等于1 或 开头为奇数
//	{
//
//		tf = 1;
//	}
//	else
//	{
//		tf = 0;
//		
//	}
//	return tf;
//}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
//		for (int j = 0; j < 20; j++)
//		{
//			if (a[i] & (1 << j))
//			{
//				pre[j][i] = 1;
//			}
//			pre[j][i] += pre[j][i - 1];
//			jo_pre[i] |= (pre[j][i] % 2) << j;
//			
//		}
		num_pre[i] = num_pre[i - 1] ^ a[i];
	}
//	for (int j = 0; j < 20; j++)
//	{
//		if (k & (1 << j))
//		{
//			pop[j] = 1;
//			
//		}
//		//printf("%d & %d = %d\n",k,(1 << j),k & (1 << j));
//		
//	}
	
	//cout<<endl;
//	for (int j = 0;j < 5;j++)
//	{
//		cout << pop[j]<<" ";
//	}
//	cout << endl<<endl;
//	for (int i = 1; i <= n; i++) {
//		
//		for (int j = 0; j < 5; j++)
//		{
//			cout << pre[j][i] << " ";
//		}
//		cout<<endl;
//	}
//	for (int j = 0;j < 5;j++)
//	{
//		cout << jo_pre[j]<<" ";
//	}
//	cout <<endl;
//	for (int i = n;i >= 0;i--)
//	{
//		s.insert(jo_pre[i]);
//		for (auto x : s)
//		{
//			mp[i][x] = mp[i + 1][x] + (x == jo_pre[i]);
//			printf("mp[%d][%d]:%d =  %d + %d\n",i,x,mp[i][x], mp[i - 1][x],(x == jo_pre[i]));
//		}
//	}
lst = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = lst +1;j <= i;j++)
		{
			if ((num_pre[i] ^ num_pre[j - 1]) == k)
			{
				ans++;
				lst = i;
				break;
			}
		}
	}
//	for (int i = 0;i <= n;i++)
//	{
//		cout<< i<<endl;
//		printf("%d\n",vis[jo_pre[i]]);
//		if (vis[jo_pre[i]] == 0)
//		
//		{
//			ans += mp[i][k ^ jo_pre[i]];
//			vis[jo_pre[i]] = 1;
//			printf("####%d ans = %d\n",k ^ jo_pre[i],ans);
//		}
//		printf("%d ans = %d\n",k ^ jo_pre[i],ans);
//	}
//	int cnt = 0;
//	vector<int> v;
//	for (int i = 1; i <= n; i++)
//	{
//		int tf = 1;
//		if (a[i] == 1) cnt++;
//		printf("a[%d] = %d lst = %d\n",i,a[i],lst);
//		for (int j = 0; j < 20; j++)//记得改回20！！！！！！！！！ 
//		{
//			int len = pre[j][i] - pre[j][lst ] ;
//			//printf("\tj = %d len = %d\n",j,len);
//			if (pop[j] == 1)// 想要奇数
//			{
////				if (pre[j][i] % 2 == 1)//这一位为奇数
////				{
////					tf = min(tf,chk_ou(j,len));//tf只会变小（从1到0），不会恢复 
////					printf(" \t\tnow ji ;want ji  need ou chk = %d tf = %d\n",chk_ou(j,len),tf);
////				}
////				else//这一位为偶数
////				{
////					tf = min(tf,chk_ji(j,len));
////					printf(" \t\tnow ou ;want ji  need ji chk = %d tf = %d\n",chk_ji(j,len),tf);
////				}
//				if (pre[j][i] % 2 == 0)
//				{
//					tf = min(tf,chk_ji(j,len));
////					printf(" \t\tnow ou ;want ji  need ji chk = %d tf = %d\n",chk_ji(j,len),tf);
//				}
//			}
//			else//想要偶数 
//			{
//				if (pre[j][i] % 2 == 1)//这一位为奇数
//				{
//					tf = min(tf,chk_ji(j,len));
//					//printf(" \t\tnow ji ;want ou  need ji chk = %d tf = %d\n",chk_ji(j,len),tf);
//				 }
////				else
////				{
////					tf = min(tf,chk_ou(j,len));
////					printf(" \t\tnow ou ;want ou  need ou chk = %d tf = %d\n",chk_ou(j,len),tf);
////				 } 
//			}
//		}
//		if (tf == 1)
//		{
//			ans++;
//			lst = i;
//			//printf("ok ans = %d\n",ans);
//		}
//		
//	}
	
	cout<< ans;
	return 0;
}
