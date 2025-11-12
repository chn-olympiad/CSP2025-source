#include<bits/stc++.h>
using namespace std;
int a[100000];
int main(){
    int s,n;
    char z,x,c;
    cin>>s>>n;
    for(int i=1;i<n;i++){
        cin>>z>>x>>c;
        for(int j=1;j<=9;j++){
            if(s<='A'&&s>='Z'||s>='a'&&s<='z'){
                cout<<z<<x<<c;
        }
    }
    cout<<a;
}
    return 0;
}