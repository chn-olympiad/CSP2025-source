#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
string a;
string b[1000005];
int cnt=1,c=1;
bool cmp(string x,string y){
	return x+y>y+x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			b[cnt]=a[i];
			cnt++;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<b[i];
	}
	return 0;
}
