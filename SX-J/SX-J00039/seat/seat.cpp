#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,c,r,a[105];
	cin >> n >> m;
    for (int i = 1;i <= n*m;i++)
        cin >> a[i];
    w = a[1];
    for (int i = 1;i <= n*m;i++)
        for (int j = 1;j < n*m;j++)
            if (a[j]<a[j+1])
                swap(a[j],a[j+1]);
    for (int i = 1;i <= n*m;i++)
        if (a[i] == w){
        	if (i*1.0/n - floor(i*1.0/n) > 0)
        	    c = i/n+1;
            else
                c = i/n;
            if (c%2 == 1)
                r = i % n;
            else
                r = n+1-i%n;
            break;
		}
    cout << c <<" " << r;
    return 0;
}