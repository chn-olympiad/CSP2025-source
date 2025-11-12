#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m=0;
	int a[n];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<j;k++){
				int M=2*max(max(a[i],a[j]),a[k]);
				int N=a[i]+a[j]+a[k];
				if(N>M)
				m++;
				for(int l=0;l<k;l++){
						int M=2*max(max(max(a[i],a[j]),a[k]),a[l]);
				int N=a[i]+a[j]+a[k]+a[l];
				if(N>M)
				m++;
					for(int p=0;p<l;p++){
						int M=2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p];
				if(N>M)
				m++;
						for(int q=0;q<p;q++){
								int M=2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q];
				if(N>M)
				m++;
							for(int w=0;w<q;w++){
								
								int M=2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w];
				if(N>M)
				m++;
								for(int I=0;I<w;I++){
								
				int M=2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I];
				if(N>M)
				m++;
					for(int J=0;J<I;J++){
						int M=2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]),a[J]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I]+a[J];
				if(N>M)
				m++;
					for(int K=0;K<J;K++){
						int M=2*max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]),a[J]),a[K]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I]+a[J]+a[K];
				if(N>M)
				m++;
					for(int L=0;L<K;L++){
						int M=2*max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]),a[J]),a[K]),a[L]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I]+a[J]+a[K]+a[L];
				if(N>M)
				m++;
					for(int P=0;P<L;P++){
						int M=2*max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]),a[J]),a[K]),a[L]),a[P]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I]+a[J]+a[K]+a[L]+a[P];
				if(N>M)
				m++;
					for(int Q=0;Q<P;Q++){
						int M=2*max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]),a[J]),a[K]),a[L]),a[P]),a[Q]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I]+a[J]+a[K]+a[L]+a[P]+a[Q];
				if(N>M)
				m++;
					for(int W=0;W<Q;W++){
						int M=2*max(max(max(max(max(max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[p]),a[q]),a[w]),a[I]),a[J]),a[K]),a[L]),a[P]),a[Q]),a[W]);
				int N=a[i]+a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[I]+a[J]+a[K]+a[L]+a[P]+a[Q]+a[W];
				if(N>M)
				m++;
					}
					}
					}
					}
					}
					}
				}}}
				}
				}
			}
		}
			
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
