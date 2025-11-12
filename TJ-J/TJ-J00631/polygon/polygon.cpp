#include<iostream>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int a;
    cin>>a;
    long long b[1001]= {0};
    for(int i=0;i<a;i++){
        cin>>b[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
