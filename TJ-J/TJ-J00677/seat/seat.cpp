#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long sco[1005];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
            cin>>sco[i];
    }
    long long rr=sco[1];
    long long anss=1;
    sort(sco+1,sco+1+n*m,cmp);
    for(int i=1;i<=m;i+=2){
            for(int j=1;j<=n;j++){
                if(sco[anss]==rr){
                    cout<<i<<' '<<j;
                    return 0;
                }
                anss++;
            }
            for(int j=n;j>=1;j--){
                if(sco[anss]==rr){
                    cout<<i+1<<' '<<j;
                    return 0;
                }
                anss++;
            }
        }
    fclose(stdin);
    fclose(stdout);
}
