#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=1;
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9')
		{
			a[k++]=n[i]-48;
		}
	}
	sort(a+1,a+k,greater<int>());
	for(int i=1;i<k;i++){
		cout<<a[i];
	}
	return 0;
}
