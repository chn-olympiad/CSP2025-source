#include<bits/stdc++.h>
using namespace std;
string n,ans;
char a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=0;
	cin>>n;
	int s=n.size();
	for(int i=0;i<s;i++)
	{
		if(n[i]>='0' && n[i]<='9')
		{
			a[b]=n[i];
			b++;
		}
	}
	sort(a,a+b,greater<char>());
	for(int i=0;i<b;i++)
	{
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}

