#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n,l=1,r=1,lr,ll;
long long x,k,arr[N],ans;
bool f()
{
	if(l>lr)
	{
		ll=l,lr=r;
		//cout<<"True: "<<l<<" "<<r<<endl;
		return true;
	}
	else
	{
		return false;
	}

}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll=0;lr=0;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	x=arr[1];
	while(l<=r&&r<=n)
	{
		//cout<<"-> "<<l<<" "<<r<<" "<<k<<endl;
		if(x==k)
		{
			if(f())
			{
				ans++;
				//cout<<"-> "<<l<<" "<<r<<endl;
			}
			if(l==r)
				r++,l++,x=(x^arr[r]),x=(x^arr[l-1]);
			else
				l++,x=(x^arr[l-1]);
		}
		else
			if(r<n)
			{
				r++,x=(x^arr[r]);
				//cout<<"R"<<endl;
			}
			else
			{
				l++,x=(x^arr[l-1]);
				//cout<<"L"<<endl;
			}
	}
	//cout<<l<<" "<<r<<endl;
	cout<<ans;
    return 0;
}
