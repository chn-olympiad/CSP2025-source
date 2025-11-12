#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    int qq;
    cin>>qq;
    for(int i=0;i<n*m-1;i++){
        int s;
        cin>>s;
        a[s]++;
    }
    for(int i=100;i>0;i--){
            if(i==qq){
            	cnt++;
                break;
            }
        if(a[i]!=0){
            cnt++;
        }
    }int l=cnt/n;
    int h=cnt%n;
    if(h==0){
    	l-=1;
    	if(l&2==0 or l==0 or l==2){
    		cout<<l+1<<' '<<n;
    		return 0;
		}
		if(l&2==1 or l==1){
			cout<<l+1<<' '<<1;
			return 0;
		}
	}
	if(l&2==0 or l==0 or l==2){
		cout<<l+1<<' '<<h;
	}
	if(l&2==1 or l==1){
		cout<<l+1<<' '<<n-h+1;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
