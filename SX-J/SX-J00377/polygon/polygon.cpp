#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n,m[111],p=0,d=0;
cin>>n;
for(int i=0;i<n;i++){
cin>>m[i];


}

for(int i=1;i<=n;i++){
p+=m[i];


}
for(int i=1;i<=n;i++){
if(m[i]>=3&&p>2*max(m[i],m[i+1])){
d++;
}
}
cout<<d%998244353;

}