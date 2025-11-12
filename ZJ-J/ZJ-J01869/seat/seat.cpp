#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> vt(n*m+1,-1);
	for(int i=1;i<=n*m;i++)
	{
		cin>>vt[i];
	}
	int Rz=vt[1];
	sort(vt.begin()+1,vt.end(),cmp);
	int pos=find(vt.begin(),vt.end(),Rz)-vt.begin();
	int nb=ceil(double(pos)/n);
	cout<<nb<<" ";
	nb--;
	int fo=pos-nb*n;
	if(nb&1)
	{
		cout<<n-fo+1;
	}
	else
	{
		cout<<fo;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
