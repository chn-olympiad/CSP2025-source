#include<bits/stdc++.h>
using namespace std;
int a[1000001],mid;
string n;
bool emp(int x,int y){
	return x>y;
	
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
cin>>n;
	for(int i=0;i<n.size();i++)	
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			mid++;
			a[mid]=n[i]-'0';
		}

	}
	sort(a+1,a+mid,emp);
	
	for(int i=1;i<=mid;i++)
	{
		cout<<a[i];
	}
	return 0;
}
