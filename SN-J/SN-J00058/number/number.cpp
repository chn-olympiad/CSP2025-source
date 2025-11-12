#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10000000];
	long long a[10000000];
	long long  lens = s.length();
	for (int i=1; i<=lens-1; i++){
		cin>>s;
	}
	long long lena = a.length();
	for (int i=1; i<=lens-1; i++){
		if ('27'<= s[i] && s[i]<='36'){
			a[i]=s[i];
		}
		
	}
	int m=0;
	for (int i=1; i<=lena-1; i++){
		if (a[i]>=0){
			if (a[i]>m){
				m=a[i];
			}
			m=a[i];
		}
	}
	return 0;
}
