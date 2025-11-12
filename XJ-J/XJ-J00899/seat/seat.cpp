#include<bits/stdc++.h>
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[11][11],a1,b1=0;
	cin >> n >> m;
	int dx=m*n;
	vector<int> b(dx);
	vector<int> c(dx);
	for(int i=0;i<dx;i++){
        cin >> b[i];
        if(i==0) a1=b[i];
	}
    for(int i=0;i<dx;i++){
        int m=0;
        for(int j=0;j<dx;j++){
            m=max(m,b[j]);
        }
        c[i]=m;
        for(int j=0;j<dx;j++){
            if(m==b[j]){
                b[j]=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i%2==0){
                a[i][j]=c[b1];
                b1++;
                if(a[i][j]==a1){
                    cout << i+1 <<" " << j+1;
                    return 0;
                }
            }
            else{
                a[i][n-j]=c[b1];
                b1++;
                if(a[i][n-j]==a1){
                    cout << i+1 <<" " << n-j+1;
                    return 0;
                }
            }
        }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
