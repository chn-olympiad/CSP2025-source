#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+5;
string a;
int n[MAX];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	ios::sync_with_stdio(0);

    cin>>a;
    int p=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
        	n[p]=a[i]-'0';
        	p++;
		}
	}
    sort(n,n+p);
    for(int i=p-1;i>=0;i--){
    	cout<<n[i];
	}
	return 0;
}
