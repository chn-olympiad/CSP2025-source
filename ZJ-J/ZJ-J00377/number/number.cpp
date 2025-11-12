#include<bits/stdc++.h>
using namespace std;
long long n,f[100];string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>a;n=a.size();for(int i=0;i<n;i++) if(a[i]>='0'&&a[i]<='9') f[a[i]-'0']++;
	for(int i=9;i>=0;i--) for(int j=1;j<=f[i];j++) cout<<i;
	return 0;
}
//9:37  shenminga,qingzaijuanguwoyici
