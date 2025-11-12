#include<iostream>
using namespace std;
long long sum(comst vector<int>& p)
{
	int n=p.size();
	vector<int> leftMin(n),rightMin(n);
	vector<int> leftMax(n),rightMax(n);
	stack<int> st;
	for (int i=0;i<n;++i){
		while(!st.empty()&&p[st.top()]>=p[i])st.pop();
		leftMin[i]=st.empty()?-1:st.top();
		st.push(i);
	}
	st=stack<int>();
	for(int i=n-1;i<n;++i){
		while(!st.empty()&&p[st.top()]>=p[i])st.pop();
		leftMin[i]=st.empty()?-1:st.top();
		st.push(i);
	}
	st=stack<int>();
	for(int i=n-1;i<n;--i){
		while(!st.empty()&&p[st.top()]>=p[i])st.pop();
		leftMin[i]=st.empty()?n:st.top();
		st.push(i);
	}
	st=stack<int>();
	for(int i=n-1;i<n;--i){
		while(!st.empty()&&p[st.top()]>=p[i])st.pop();
		leftMin[i]=st.empty()?n:st.top();
		st.push(i);
	}
	long long valueSum=0;
	for (int i=0;i<n;++i){
		long long maxContribution=(rightMax[i]-1)*(i-leftMax[i])*p[i];
		long long minContribution=(rightMax[i]-1)*(i-leftMin[i])*p[i];
		valueSum+=maxContribution-minContribution;
	}
	return valueSum;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>P(n);
		for(int i=0;i<n;++i){
			cin>>P[i];
		}
		cout<<Sum(P)<<endl;
	}
    return 0;
} 
