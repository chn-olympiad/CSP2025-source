#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
struct member
{
	ll fir,sec,thi; 
 } arr[100005];
 bool cmp1(member x,member y)
 {
 	return x.fir>y.fir;
 }
 bool cmp2(member x,member y)
 {
 	return x.sec>y.sec;
 }
  bool cmp3(member x,member y)
 {
 	return x.thi>y.thi;
 }
 ll res=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i].fir>>arr[i].sec>>arr[i].thi;}
		sort(arr,arr+n,cmp1);
		for(ll i=0;i<n/2;i++)
		{
			if(arr[i].fir<arr[i].sec||arr[i].fir<arr[i].thi)continue;
			res+=arr[i].fir;
			arr[i].fir=0;
			arr[i].sec=0;
			arr[i].thi=0;
		}
		sort(arr,arr+n,cmp2);
		for(ll i=0;i<n/2;i++)
		{
			if(arr[i].sec<arr[i].thi)continue;
			res+=arr[i].sec;
			arr[i].fir=0;
			arr[i].sec=0;
			arr[i].thi=0;
		}
		sort(arr,arr+n,cmp3);
		for(ll i=0;i<n/2;i++)
		{
			res+=arr[i].thi;
		}
		cout<<res<<endl;
		res=0;
	 } 
	return 0;
 }

