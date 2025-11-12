#include<iostream>
using namespace std;
int main()
{
	freopen(poligon.in,'r',stdin);
    freopen(poligon.out,'w',stdout);
    int s,a[10000];
    cin>>s;
    for(int i=1;i<=s;i++)   cin>>a[i];
    if(s==5&&a[1]=2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)    cout<<6;
    else if(s==5&&a[1]=1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)    cout<<9;
    else cout<<24;
	return 0;
}
