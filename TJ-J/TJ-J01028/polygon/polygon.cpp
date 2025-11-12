#include <bits/stdc++.h> 

using namespace std;
	
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005],maxx=0;
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		if(a[i] > maxx) maxx = a[i];
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
