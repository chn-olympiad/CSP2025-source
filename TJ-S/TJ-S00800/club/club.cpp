#include <bits/stdc++.h>
using namespace std;
int n;
int li[100002][3];
int thrmax(int a,int b,int c) {
	return max(a,max(b,c));
}
bool cmp1(int a,int b) {
	return li[a][0]>li[b][0];
}
bool cmp2(int a,int b) {
	return li[a][1]>li[b][1];
}
bool cmp3(int a,int b) {
	return li[a][2]>li[b][2];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (int _=0;_<t;_++) {
		cin>>n;
		for (int i=0;i<n;i++) {
			cin>>li[i][0]>>li[i][1]>>li[i][2];
		}
		vector<int> f,s,t;
		for (int i=0;i<n;i++) {
			int kma=thrmax(li[i][0],li[i][1],li[i][2]);
			if (kma==li[i][0]) {
				f.push_back(i);
			}
			else if (kma==li[i][1]) {
				s.push_back(i);
			}
			else {
				t.push_back(i);
			}
		}
		sort(f.begin(),f.end(),cmp1);
		sort(s.begin(),s.end(),cmp2);
		sort(t.begin(),t.end(),cmp3);
		int fc=0,sc=0,tc=0;
		long long fullmayi=0;
		for (int i=0;i<f.size();i++) {
			if (fc<=(n/2)-1) {
				fc++;
				fullmayi+=li[f[i]][0];
			}
			if (i == f.size()-1) {
				continue;
			}
			if (fc==n/2 && (li[f[i]][0]-max(li[f[i]][1],li[f[i]][2]))<(li[f[i+1]][0]-max(li[f[i+1]][1],li[f[i+1]][2]))){
				fullmayi-=li[f[i]][0];
				fullmayi+=li[f[i+1]][0];
				fullmayi+=max(li[f[i]][1],li[f[i]][2]);
				fc++;
			}
		}
		for (int i=0;i<s.size();i++) {
			if (sc<=(n/2)-1) {
				sc++;
				fullmayi+=li[s[i]][1];
			}
			if (i == s.size()-1) {
				continue;
			}
			if (sc==n/2 && li[s[i]][1]-max(li[s[i]][0],li[s[i]][2])<li[s[i+1]][1]-max(li[s[i+1]][0],li[s[i+1]][2])){
				fullmayi-=li[s[i]][1];
				fullmayi+=li[s[i+1]][1];
				fullmayi+=max(li[s[i]][0],li[s[i]][2]);
				sc++;
			}
		}
		for (int i=0;i<t.size();i++) {
			if (tc<=(n/2)-1) {
				tc++;
				fullmayi+=li[t[i]][2];
			}
			if (i == t.size()-1) {
				continue;
			}
			if (tc==n/2 && li[t[i]][2]-max(li[t[i]][0],li[t[i]][1])<li[t[i+1]][2]-max(li[t[i+1]][0],li[t[i+1]][1])){
				fullmayi-=li[t[i]][2];
				fullmayi+=li[t[i+1]][2];
				fullmayi+=max(li[t[i]][0],li[t[i]][1]);
				tc++;
			}
		}
		for (int i=fc;i<f.size();i++) {
			fullmayi+=max(li[f[i]][1],li[f[i]][2]);
		}
		for (int i=sc;i<s.size();i++) {
			fullmayi+=max(li[s[i]][0],li[s[i]][2]);
		}
		for (int i=tc;i<t.size();i++) {
			fullmayi+=max(li[t[i]][0],li[t[i]][1]);
		}
		cout<<fullmayi<<endl;
	}
	return 0;
}
