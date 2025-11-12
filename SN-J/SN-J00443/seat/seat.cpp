#include <bits/stdc++.h>
using namespace std;
int score[10010],n,m,seat,h,l;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>score[i];
	sort(score+1,score+n*m,cmp);
	for(int i=1;i<n*m;i++)
		if(score[i]<score[0]){
			seat=i;
			break;
		}
	
	if(seat%n==0)l=seat/n;
	else l=seat/n+1;
	
	if(l%2==0)h=n-seat%n;
	else if(l==1)h=seat;
	else h=seat%n;
	
	cout<<l<<" "<<h;
}
