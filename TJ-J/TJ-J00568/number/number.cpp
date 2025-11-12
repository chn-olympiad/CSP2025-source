#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[a.length()],f=0;
    for(int i = 0;i<a.length();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[f] = a[i] - '0';
            f++;
        }
    }
    for(int i = 0;i<f;i++){
    	for(int j = i;j<f;j++){
    		if(b[j]>b[i]){
    			int t = b[j];
    			b[j]=b[i];
    			b[i]=t;
			}
		}
	}
    int maxn=0;
    for(int i = 0;i<f;i++){
        maxn*=10;
        maxn+=b[i];
    }
    cout<<maxn;
    return 0;
}
