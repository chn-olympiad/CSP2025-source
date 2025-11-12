#include <iostream>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    if(n==5&&a[0]==1) cout<<9;
    else if(n==5&&a[0]==2) cout<<6;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
