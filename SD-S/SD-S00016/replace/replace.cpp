#include<bits/stdc++.h>
#define pii pair<long long,long long> 
#define ll long long
using namespace std;
const int N = 1e5 + 9;
int n,q;
string s1[N],s2[N],t1,t2;
map<string,string> m;
map<string,int> mm;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
		m[s1[i]] = s2[i];
		mm[s1[i]] = 1;
	}
	while(q--)
	{
		int sum = 0;
		cin >> t1 >> t2;
		int l1 = t1.size();
		int l2 = t2.size(); 
		for(int i = 0;i < l1;i++)
		{
			for(int j = i;j < l1;j++)
			{
				string s; 
				for(int k = i;k <= j;k++)
				{
					s += t1[k];
				}
				if(mm[s])
				{
//					cout << s << " ";
					string a = m[s];
//					cout << m[s] << " ";
					int cnt = 0;
					string s3 = t1;
					for(int k = i;k < a.size() + i;k++)
					{
						s3[k] = a[k - i];
//						cout << a[k - 1] << " ";
					}
//					cout << s3 << " ";
					if(s3 == t2)
					{
						sum ++;
					}
				}
			} 
		}
		cout << sum << endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
