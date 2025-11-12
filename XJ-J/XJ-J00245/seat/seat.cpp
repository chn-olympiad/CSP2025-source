#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;//    m有激烈   n有行 
	int a[101]={0};
	for(int i=0;i<n*m;i++) cin>>a[i];
	int ming=a[0];
	sort(a,a+(n*m+1));
	int bian=0;
	for(int i=m*n-1;i>=0;i--)
	{
		if(a[i]==ming)
		{
			bian=m*n-i+1;
			break;
		}
	}
	int zm,zn;//  zm在第几列  zn在第几行 
	if(bian%n==0) zm=bian/n;
	else zm=bian/n+1;
	int sum;
	if(zm%2==1) {sum=n;zn=bian%n;if(bian%n==0) zn=n;}
	else {zn=n-(bian%n-1);if(bian%n==0) zn=1;}
	cout<<zm<<" "<<zn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
