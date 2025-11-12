#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector<int> a;
int t[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }
    int l2=a.size();
    if(l2<=1000000){
        for(int i=0;i<l2;i++){
            t[a[i]]++;
        }
        for(int i=9;i>=0;i--){
            while(t[i]--){
                cout<<i;
            }
        }
    }else{
		for(int j=9;j>=0;j--){
			for(int i=0;i<l2;i++){
				if(a[i]==j){
					cout<<j;
				}
			}
		}
    }
    return 0;
}
