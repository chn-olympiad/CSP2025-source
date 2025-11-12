#include<bits/stdc++.h>
using namespace std;

int nor(int A,int B)
{
	int cnt=0;
	while(A>0||B>0)
	{
		cnt*=10;
		if(A%2!=B%2)
		{
			cnt++;
		}
		A/=2;
		B/=2;
	}
	int n=0,cnt2=cnt;
	//cout<<cnt2<<" "<<cnt<<endl;
	while(cnt>0)
	{
		//cout<<cnt<<" ";
		n++;
		cnt/=10;
	}
	cnt=0;
	//cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		cnt+=cnt2%10;
		//cout<<cnt<<endl;
		cnt*=2;
		cnt2/=10;
	}
	return cnt;
}

int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cout<<nor(15,9);
} 
