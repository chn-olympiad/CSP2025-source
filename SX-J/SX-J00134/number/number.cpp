#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string n;
long long len,a[N];
long long c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	len=n.size();
	for(int i=0;i<len;i++){
		if(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9')
			a[i]=n[i];
	}
	sort(a+1,a+len+1);
	for(int i=0;i<len;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
            cout<<n[i];
        else
        	return 0;
	}
	return 0;
}