#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int m=0,s=-1,a[1000000];
	cin >> n;
	for (int i = 0;i < n.size();i++){
		if (n[i] >= '0' && n[i] <= '9'){
			if (n[i]=='0')    a[m]=0;
            else if (n[i]=='1')    a[m]=1;
			else if (n[i]=='2')    a[m]=2;
			else if (n[i]=='3')    a[m]=3;
			else if (n[i]=='4')    a[m]=4;
			else if (n[i]=='5')    a[m]=5;
			else if (n[i]=='6')    a[m]=6;
			else if (n[i]=='7')    a[m]=7;
			else if (n[i]=='8')    a[m]=8;
			else    a[m]=9;
			m++;
		}
	}
	for (int i = 0;i < m;i++)
        for (int j = 0;j < m-1;j++)
            if (a[j]<a[j+1])
                swap(a[j],a[j+1]);
    for (int i = 0;i < m;i++)
        cout << a[i];
    return 0;
}