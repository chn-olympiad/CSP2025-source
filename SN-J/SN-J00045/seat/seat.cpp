//余俊辰 SN-J00045 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int xiaor=a[1];
	sort(a+1,a+m*n+1);
	int seat;
	for(int i=1;i<=m*n;i++)
		if(a[i]==xiaor)
			seat=m*n-i+1;
	int ansc,ansr;//c列r行 
	if(a[m*n+1-seat]==xiaor)
	{
		
		if(seat%n==0)ansc=seat/n;
		else ansc=seat/n+1;
		seat%=n;
		if(ansc%2==1)//单数列 
		{
			if(seat==0)ansr=n;
			else ansr=seat;
		}	
		else
		{
			if(seat==0)ansr=1;
			else ansr=n-seat+1;
		}
	}
	cout<<ansc<<" "<<ansr;
	return 0;
}

