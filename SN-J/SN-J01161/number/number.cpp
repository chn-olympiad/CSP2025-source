#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[105];
	int a[105];
	int num = 0;
	for(int i = 1;i<=105;i++)
	{
		cin >> s[i];
	}
	
	for(int i = 1;i<=105;i++){
		if(s[i]>='1'&&s[i]<='9'){
			a[i] = s[i];
		}
		
	}
	for(int i = 1;i<=105;i++){
		a[i-1] = max(a[i],a[i-1]);
	}
	return 0;
}
