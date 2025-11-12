#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
    cin >> a;
    vector<int> b;
    for(int i=0;i<a.size();i++){
        if(int(a[i])==48){
            b.push_back(0);
        }
        else if(int(a[i])==49){
            b.push_back(1);
        }
        else if(int(a[i])==50){
            b.push_back(2);
        }
        else if(int(a[i])==51){
            b.push_back(3);
        }
        else if(int(a[i])==52){
            b.push_back(4);
        }
        else if(int(a[i])==53){
            b.push_back(5);
        }
        else if(int(a[i])==54){
            b.push_back(6);
        }
        else if(int(a[i])==55){
            b.push_back(7);
        }
        else if(int(a[i])==56){
            b.push_back(8);
        }
        else if(int(a[i])==57){
            b.push_back(9);
        }
    }
    for(int i=0;i<b.size();i++){
        int m=0;
        for(int j=0;j<b.size();j++){
            m=max(m,b[j]);
        }
        for(int j=0;j<b.size();j++){
            if(m==b[j]){
                b[j]=0;
                break;
            }
        }
        cout << m;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
