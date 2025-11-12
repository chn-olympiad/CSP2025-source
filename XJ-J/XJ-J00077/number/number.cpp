#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int arr[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

	string ss;
	cin>>ss;
	long long sslen=ss.size(),sum=0;
	for(long long i=0;i<sslen;i++)
	{
		if(ss[i]>='0'&&ss[i]<='9')
		{
			arr[sum]=int(ss[i])-48;
			sum++;
		}
	}
	sort(arr,arr+sum+1);
	for(long long i=sum;i>0;i--)
	{
		cout<<arr[i];
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
