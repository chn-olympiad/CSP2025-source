#include<bits/stdc++.h>
using namespace std;
string in;
int a[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>in;
    int len=in.size();
    for(int i=0;i<len;i++){
        if(in[i]=='1'){
            a[1]++;
        }
        if(in[i]=='2'){
            a[2]++;
        }
        if(in[i]=='3'){
            a[3]++;
        }
        if(in[i]=='4'){
            a[4]++;
        }
        if(in[i]=='5'){
            a[5]++;
        }
        if(in[i]=='6'){
            a[6]++;
        }
        if(in[i]=='7'){
            a[7]++;
        }
        if(in[i]=='8'){
            a[8]++;
        }
        if(in[i]=='9'){
            a[9]++;
        }
        if(in[i]=='0'){
            a[0]++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}