#include<bits/stdc++.h>
using namespace std;
int arr[1005];
string s;
bool z(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
	long long n=1;
	n=s.size();
	long long m=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
			arr[i]=s[i]-'0';
		}
	}
    sort(arr,arr+m+1,z);
    for(int j=0;j<m;j++){
	    cout<<arr[j];
	}
	return 0;
}