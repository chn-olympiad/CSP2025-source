#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct stu {
	int d[3];
	int &operator[](int i) {
		return d[i-1];
	}
};
vector<stu> V;
int D[4];
int c2;
int c3;
int A() {
	vector<int> t;
	for(int i=1; i<=n; i++) {
		t.push_back(V[i][1]);
	}
	sort(t.rbegin(),t.rend());
	int sum=0;
	for(int i=0; i<n/2; i++) {
		sum+=t[i];
	}
	return sum;
}
int B() {
	vector<pair<int,int> >t;
	for(int i=1; i<=n; i++) {
		t.push_back({V[i][1],V[i][2]});
	}
	vector<int>dt1;
	vector<int>dt2;
	sort(t.rbegin(),t.rend());
	int sum=0;
	for(int i=0; i<n/2; i++) {
		sum+=t[i].first;
		dt1.push_back(t[i].second-t[i].first);
	}
	for(int i=n/2; i<n; i++) {
		sum+=t[i].second;
		dt2.push_back(t[i].first-t[i].second);
	}
	for(int i=0; i<n/2; i++) {
		for(int j=0; j<n/2; j++) {
			if(dt1[i]+dt2[j]>0) {
				sum+=dt1[i]+dt2[j];
				dt1[i]=-dt1[i];
				dt2[j]=-dt2[j];
				j=0;
			}
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		c2=c3=0;
		cin>>n;
		V.resize(n+1);
		for(int i=1; i<=n; i++) {
			cin>>V[i][1]>>V[i][2]>>V[i][3];
			c2+=V[i][2];
			c3+=V[i][3];
		}
		if(c3==0) {
			if(c2==0) {
				cout<<A()<<endl;
				return 0;
			}
			cout<<B()<<endl;
			return 0;
		}
	}
	return 0;
}