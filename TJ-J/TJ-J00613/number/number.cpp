#include <bits/stdc++.h>
using namespace std;
string s;
int n,a[1000],sum;
bool j(int a,int b){
	return a>b;
}
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	//#Shang4Shan3Ruo6Shui4
	cin>>s;
	int len=s.length();
	for(int i=0;i<=len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum,j);
	for(int i=0;i<sum;i++){
		cout<<a[sum-i-1];
	}
	return 0;
}
