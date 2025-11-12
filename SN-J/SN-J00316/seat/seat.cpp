//MS Attached to NWPU SN-J00316 Zhang Yuanhao
#include <bits/stdc++.h>
using namespace std;
int a[103],n,m;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int tot=n*m;
	for(int i=1;i<=tot;i++)
		cin >> a[i];
	int littleR=a[1],pos=0;
	sort(a+1,a+tot+1,cmp);
//	for(int i=1;i<=tot;i++) cout << a[i] <<' ';
	for(int i=1;i<=tot;i++)
		if(a[i]==littleR)
			pos=i;
	int col=(pos-1)/n+1;//Calculate Colomn
	int num=pos-(col-1)*n;//The ?th in the colomn
//	cout << col << ' ' << num;
	if(col%2)
	{
		cout << col << ' ' << num;
	}
	else
	{
		cout << col << ' ' << n-num+1;
	}
	return 0;
}
//9:05 Finish Coding
//2 2
//99 100 97 98
//9:11 Finally Pass Small Tests
//9:15 Pass Large Examples
