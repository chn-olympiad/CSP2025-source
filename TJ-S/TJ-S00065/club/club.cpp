#include<bits/stdc++.h>
using namespace std;
int n,t,o;
int c[3]={0};
vector<int> v;
void zhs(int a[][3],int sc[]){/*
    int da[n]={0};
    for(int h=0;h<n;h++){
    for(int g=0;g<3;g++){
		if((da[h]<=a[h][g])&&(c[g]<=n/2)) da[h]=a[h][g];
		c[g]++;
	}}
	for(int q=0;q<n;q++) sc[o]+=da[q];*/
	int q;
	for(int h=0;h<3;h++){
		q=a[0][h];
    for(int g=1;g<n;g++){
    for(int p=0;p<3;p++){
    	q+=a[g][p];
    	v.push_back(q);
	}}}
	for(int e=0;e<v.size();e++){
		if(sc[o]<=v[e]) sc[o]=v[e];
	}
	return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int sc[t];
    for(o=0;o<t;o++){
            cin>>n;
            int a[n][3]={0};
    for(int z=0;z<n;z++){
        for(int u=0;u<3;u++){
            cin>>a[z][u];
        }
    }
    zhs(a,sc);
	}
	for(int i=0;i<t;i++) cout<<sc[i]<<endl;
    return 0;
}
