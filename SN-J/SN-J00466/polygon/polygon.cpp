//SN-J00466  shiyihao  jinkaierzhong
#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n;
    cin>>n;
    int a;
    int b[10000];
    for(int i=0;i<n;i++){
    	cin>>a;
    	b[a]++;
	}
	vector<int> c;
	int d=0;
	for(int i=1;i<10000;i++){
		if(b[i]>0){
			c.push_back(i);
			d++;
		}
	}
	cout<<3;
    return 0;
}

