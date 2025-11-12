#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
int num[100000]{0};
char a[100000]{'.'};
vector <int> sum[100]{0};
int out{0};
cin>>a;
char charlist[10]={'0','1','2','3','4','5','6','7','8','9'};
int cnt{0};
while(1){
    for(int i{0};i<=10;i++){
        if(charlist[i]==a[cnt]){
            num[cnt]=i;
            }
    }
if(a[cnt]=='\0'){
    break;
}
cnt++;
}
sort(num,num+100000);
for(int j=i;j>=0;j--){
    if(sum[j]=='0'){
        out=out+10^j;
    }
    else{
        out+=out[j]*(10^j);
    }
}
cout<<out;
return 0;
}
