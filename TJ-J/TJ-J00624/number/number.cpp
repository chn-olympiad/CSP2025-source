#include <bits/stdc++.h>

using namespace std;

int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int b[1000000]={10},i=0,l=0;
while(a[i]!=0){
    if(a[i]>='0'&&a[i]<='9'){
        b[i]=a[i];
    }
    i++;
}
i=0;
while(b[i]!=10){
    i++;
    l++;
}
for (int j=0;j<l;j++){
    int v=-1;
    for (int m=0;m<l;m++){
        v=-1;
        if(b[m]==10){
            continue;
        }
        else{
        	if(b[m]>v){
            v=b[m];
        }
		}

    }
    cout<<v;
    for (int n=0;n<=l;n++){
        if(b[n]==v){
            b[n]=10;
            break;
        }
    }
}
    return 0;
}

