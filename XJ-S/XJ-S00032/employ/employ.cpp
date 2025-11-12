#include<bits/stdc++.h>
#include<string>
using namespace std;
int x,y;
string n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdin);
    cin >> n;
    int cnt=0,z=n.size();
    int apple[z];
    for(int i=1;i<=z;i+=1){
        apple[i]=i;
    }
    while(!apple){
		for(int j=1;j<=z;j+=3){
			cnt++;
			if(z<3) cnt++;
			if(int(n[-1])==j){
				y=cnt;
			}
			apple[cnt]--;
	}
	}
    cout << cnt<<" "<<y;
    fclose(stdin);
    fclose(stdout);
}
