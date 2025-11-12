#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
struct man{
	ll fir,sec,thi;
}a[114514];
man max1[114514],max2[114514],max3[114514];
ll t,n,ans,k1,k2,k3;
bool cmp1(man x,man y)
{
	return x.fir>y.fir;
}
bool cmp2(man x,man y)
{
	return x.sec>y.sec;
}
bool cmp3(man x,man y)
{
	return x.thi>y.thi;
}
bool cmp11(man x,man y)
{
	return x.fir+max(y.sec,y.thi)>y.fir+max(x.sec,x.thi);
}
bool cmp12(man x,man y)
{
	return x.sec+max(y.fir,y.thi)>y.sec+max(x.fir,x.thi);
}
bool cmp13(man x,man y)
{
	return x.thi+max(y.sec,y.fir)>y.thi+max(x.sec,x.fir);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		k1=0;
		k2=0;
		k3=0;
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i].fir>>a[i].sec>>a[i].thi;
			if(a[i].fir>=a[i].sec&&a[i].fir>=a[i].thi) 
				max1[++k1]=a[i];
			else if(a[i].fir<=a[i].sec&&a[i].sec>=a[i].thi) 
				max2[++k2]=a[i];
			else
				max3[++k3]=a[i];
		}
		sort(max1+1,max1+1+k1,cmp1);
		sort(max2+1,max2+1+k2,cmp2);
		sort(max3+1,max3+1+k3,cmp3);
//		cout<<"max1:"<<endl;
		if(k1<=n/2)
		{
			for(ll i=1;i<=k1;i++)
			{
//				cout<<max1[i].fir<<" "<<max1[i].sec<<" "<<max1[i].thi<<endl;
				ans+=max1[i].fir;
			}
//			cout<<ans<<endl<<endl;
		}
		else
		{
			sort(max1+1,max1+1+k1,cmp11);
			for(ll i=1;i<=n/2;i++)
			{
//				cout<<max1[i].fir<<" "<<max1[i].sec<<" "<<max1[i].thi<<endl;
				ans+=max1[i].fir;
			}
			for(ll i=n/2+1;i<=k1;i++)
			{
//				cout<<max1[i].sec<<" "<<max1[i].thi<<endl;
				ans+=max(max1[i].sec,max1[i].thi);
			}
		}
//		cout<<"max2:"<<endl;
		if(k2<=n/2)
		{
			for(ll i=1;i<=k2;i++)
			{
//				cout<<max2[i].fir<<" "<<max2[i].sec<<" "<<max2[i].thi<<endl;
				ans+=max2[i].sec;
			}
//			cout<<ans<<endl<<endl;
		}
		else
		{
			sort(max2+1,max2+1+k2,cmp12);
			for(ll i=1;i<=n/2;i++)
			{
//				cout<<max2[i].fir<<" "<<max2[i].sec<<" "<<max2[i].thi<<endl;
				ans+=max2[i].sec;
			}
			for(ll i=n/2+1;i<=k2;i++)
			{
//				cout<<max2[i].fir<<" "<<max2[i].thi<<endl;
				ans+=max(max2[i].fir,max2[i].thi);
			}
		}
//		cout<<"max3:"<<endl;
		if(k3<=n/2)
		{
			for(ll i=1;i<=k3;i++)
			{
//				cout<<max3[i].fir<<" "<<max3[i].sec<<" "<<max3[i].thi<<endl;
				ans+=max3[i].thi;
//				cout<<ans<<endl;
			}
//			cout<<ans<<endl<<endl;
		}
		else
		{
			sort(max3+1,max3+1+k3,cmp13);
			for(ll i=1;i<=n/2;i++)
			{
//				cout<<max3[i].fir<<" "<<max3[i].sec<<" "<<max3[i].thi<<endl;
				ans+=max3[i].thi;
			}
			for(ll i=n/2+1;i<=k3;i++)
			{
//				cout<<max3[i].fir<<" "<<max3[i].sec<<endl;
				ans+=max(max3[i].sec,max3[i].fir);
//				cout<<ans<<endl;
			}
		}
//		cout<<endl<<"total:"<<endl;
		cout<<ans<<endl;
//		cout<<endl;
	}
	return 0;
}
//wc!!!我居然ac了t1!!!
//sto sto sto sto 西西弗 orz orz orz orz 