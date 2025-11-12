#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main (){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
int ar = 0;
int al = 0;
for(int i = 1;i<=n;i++)
{
	cin>>a[i];
	if(a[i]==0)ar++;
	else al++;
}
if(k==0){
	cout<<ar;
}
else  if ( k == 1)cout << al;
else {
	cout << ceil(n/ k );
}


return 0;
}

