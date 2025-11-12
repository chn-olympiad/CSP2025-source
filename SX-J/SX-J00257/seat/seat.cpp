#include<bits/stdc++.h>

using namespace std;

int n,m,a[1005],h=1,l=1;
bool p=0;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int y=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==y)
		{
			y=n*m-i+1;
			break;
		}
	}
	for(int i=1;i<y;i++){
		if(p==0)h++;
		if(p==1)h--;
		if(h==1&&p==1)
		{
			if(y-1==i)break;
			l++,p=0,i++;
		}
		if(h==n&&p==0)
		{
			if(y-1==i)break;
			l++,p=1,i++;
		}
	}cout<<l<<' '<<h;
	return 0;
}
