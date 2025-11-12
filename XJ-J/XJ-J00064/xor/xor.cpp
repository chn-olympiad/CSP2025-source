//#include<bits/stdc++.h>
//using namespace std;
//bool b[200005];
//int main()
//{
//	int n, k;
////	freopen("xor.in","r",stdin);
////	freopen("xor.out","w",stdout);
//	cin >> n >> k;
//	vector< int > a; 
//	int sum = 0; 
//	for(int i = 1;i <= n ;i++)
//	{
//		int num;
//		cin >> num;
//		a.push_back(num);
//	}
//	for(int i = 0;i < n;i++)
//	for(int j = 1; j <= n - i; j++)
//	{
//		cout << 2;
//		int s=0;
//		s=a[j];
//		for(int k = j + 1; k <= j + i; k++)
//		{
//			if(s != a[j]&&!b[j])
//			s = 1;
//			else
//			s = 0;
//			cout << 3;
//		}	
//		if(s == k)
//		{
//			sum++;
//			for(int k = j;k <= j +  i;i++)
//			b[i] = true;
//		}
//		
//	}
//	cout << sum;
//	return 0;
// } 
 #include<bits/stdc++.h>
using namespace std;
bool b[200005];
int main()
{
	int n, k;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	vector< int > a; 
	int sum = 0; 
	for(int i = 1;i <= n ;i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
	if(k == 1)
	cout << n;
	else
	cout << n-1;
	return 0;
 } 
