#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long a[s.length()+1],num=0,m=1,n=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[n]=(int) s[i]-(int) '0';
			n+=1;
		}
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		num+=a[i]*m;
		m=m*10;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
