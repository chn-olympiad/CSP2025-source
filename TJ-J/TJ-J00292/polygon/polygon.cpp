#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
   	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
        cin>>v[i];
	}
	sort(v.begin(),v.end());
	if(n<=3){
        if(n==0||n==1||n==2){
            cout<<0;
        }
        else if(n==3){
            int a=v[0];
            int b=v[1];
            int c=v[2];
            if(a+b+c>2*c){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
	}
	return 0;
}
