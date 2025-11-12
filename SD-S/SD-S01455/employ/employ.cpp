#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m,c[114514],ans;
string dif; 
signed main()
{ 	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m>>dif;
	int man[100]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	for(int i=0;i<n;i++) cin>>c[i];
	if(n==m)
	{
		cout<<1<<endl;
		return 0;
	 } 
	do
	{
		int pass=0,nopass=0;
		for(int i=0;i<n;i++)
		{
			if(nopass>=c[man[i]])
			{
				nopass++;
				continue; 
			}
			if(dif[i]=='1') pass++;
			else nopass++;
		}
//		cout<<pass<<endl;
//		for(int i=0;i<n;i++) cout<<man[i]<<" ";
//		cout<<endl;
		if(pass>=m) ans++; 
	}while(next_permutation(man,man+n)); 
	cout<<ans;
	return 0;
 } 
