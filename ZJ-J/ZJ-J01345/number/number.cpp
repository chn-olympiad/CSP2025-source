#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
string s;
char q[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l = s.size();
	int q_size = 0;
	for (int i=0;i < l;i++)
	    {
	    	if (s[i] >= '0' && s[i] <= '9')
	    	    {
	    	    	q_size++;
	    	    	q[q_size] = s[i];
				}
		}
	sort(q+1,q+q_size+1);
	while (q_size != 0)
	    {
	    	cout << q[q_size];
	    	q_size--;
		}
	cout << endl;
	return 0;
}
