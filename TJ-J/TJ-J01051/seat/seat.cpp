#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cj;
    cin>>n>>m;
    int h=n*m;
    for(int i=1;i<=h;i++){
        cin>>a[i];
    }
    int w=a[1];
    int zl,hh;
    sort(a+1,a+h+1,greater<int>());
    for(int i=1;i<=h;i++){
        if(a[i]==w){
            if(i%n==0){
                zl=i/n;
            }
            else{
                zl=i/n+1;
            }
            if(zl%2!=0){
            	if((i%n)==0){
            		hh=n;
				}
				else{
					hh=i%n;
				}
			}
			else{
				if((i%n)==0){
					hh=1;
				}
				else{
					hh=n-(i%n)+1;
				}
			}
        }
    }
    cout<<zl<<" "<<hh;
    return 0;
}
