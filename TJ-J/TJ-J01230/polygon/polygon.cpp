#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin >> n;
    int x[5001];
    int maxx=0;
    for(int i=0;i<n;i++){
        cin >>x[i];
        maxx=max(x[i],maxx);
    }
    sort(x,x+n);
    int cnt=0;
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		for(int k=j+1;k<n;k++){
    			int y[3];
    			y[0]=x[i];
    			y[1]=x[j];
    			y[2]=x[k];
    			sort(y,y+3);
				if(y[0]+y[1]>y[2]){
					cnt++;
				}
			}
		}
	}
	cout << cnt;
    return 0;

}
