#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}	
int nums[100001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string k;cin>>k;
	long long l=0;
	for(int i=0;i<k.length();++i)
	{
		if(k[i]>='0'&&k[i]<='9')
		{
			nums[l]=(k[i]-'0');++l;
		}
	}
	sort(nums,nums+l,cmp);
	for(int i=0;i<l;i++)
	{
		cout<<nums[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}