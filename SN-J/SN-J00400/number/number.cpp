//Code Originally Designed by Zhang Aoyi, SN-J00400, Shaanxi NOI CSP-J/S 2025
//Lang: C++, Examination Time: 08:30~12:00
//School: Xi'an Aerospace City No.1 (Junior) High School
//Examination Place: NPU Chang'an Campus
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >qq;
//number.cpp
string s;
vector<int>v;
int a[1000086];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>s;
	int strLen=s.length();
	for(int i=0;i<strLen;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	int vecSiz=v.size();
	for(int i=0;i<vecSiz;i++){
		a[i]=v[i];
	}
	sort(a,a+vecSiz);
	for(int i=vecSiz-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

