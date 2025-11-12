#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
bool Cmp(int a,int b);
void sit(int n,int m,int s);
int room[15][15];
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i <= n*m;i++)
	    cin >> a[i];
	int r_s = a[1];
	sort(a+1,a+n*m+1,Cmp);
	sit(n,m,r_s);
	cout << endl;
//	for (int i=1;i <= n;i++)
//	    {
//	    	for (int j=1;j <= m;j++)
//	    	    cout << room[i][j] << " ";
//	    	cout << endl;
//		}
	return 0;
}
bool Cmp(int a,int b)
    {
    	return a>b;
	}
void sit(int n,int m,int s)
    {
    	int i = 1;
    	int j = 1;
    	int k = 1;
        bool direction = 1;
        while (a[k] != s)
            {
            	room[i][j] = a[k];
            	if (direction == 1)
            	    i++;
            	    else
            	        i--;
            	if (i > n)
            	    {
            	    	j++;
            	    	i--;
            	    	direction = !direction;
					}
            	if (i < 1)
            	    {
            	    	j++;
            	    	i++;
            	    	direction = !direction;
					}
            	k++;
			}
		cout << j << " " << i << endl;
	}
