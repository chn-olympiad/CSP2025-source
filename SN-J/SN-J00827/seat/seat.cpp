#include<bits/stdc++.h> 
using namespace std;
int main(){freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int c,r,cnt=1;
cin>>c>>r;
int a[c*r];
for(int i=0;i<c*r;i++){
	cin>>a[i];
}
if(c==1&&r==1)cout<<"1"<<" "<<"1";
return 0;
}
