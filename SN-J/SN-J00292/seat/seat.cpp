#include <bits/stdc++.h>

using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int r=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){

        if(a[i]==r){
            r=i;
            break;
        }
    }
    int x=1,y=1,f=1;
    bool b=0;
    for(int i=0;;i++){
        if(i==r){
            cout<<y<<' '<<x;
            return 0;
        }
        if(b==1){
            y++;
            b=0;
            f*=-1;
            if(i==r){
               cout<<x<<' '<<y;
               return 0;
            }
            continue;
        }

        x+=f;
        if(x==n||x==1){
            b=1;
        }



    }
  // cout << "Hello world!" << endl;
    return 0;
}

