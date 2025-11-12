#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

struct members{
	int num;
	int dpm[5];
	int loss;
}mem[N];

int n,p;
int tmax[N],tmin[N];
int loss_arr[N][4];
int crowd[5];

bool cmp(members m , members n){
	return m.loss > n.loss;
}

int main(){
    freopen("ttxt.in","r",stdin);
    freopen("ttxt.out","w",stdout);

    memset(crowd,0,sizeof(crowd));

	int ans = 0;
	cin >> n;
	while(n-- > 0){
        ans = 0;
		cin >> p;
		for(int i = 1 ; i<=p ; i++){
			mem[i].num = i;
			cin >> mem[i].dpm[1] >> mem[i].dpm[2] >> mem[i].dpm[3];
			for(int j=1 ; j<=3 ; j++){loss_arr[i][j] = mem[i].dpm[j];}

			sort(loss_arr[i]+1,loss_arr[i]+4);

			mem[i].loss = loss_arr[i][3] - loss_arr[i][1];

			for(int j = 1 ; j<=3 ; j++){
                for(int k=1 ; k<=3 ; k++){
                    if(mem[i].dpm[k] == loss_arr[i][j]){
                        loss_arr[i][j] = k-5;
                        break;
                    }
                }
			}

		}

		sort(mem+1,mem+p+1,cmp);

		for(int i = 1 ; i <= p ; i++){
            for(int j = 1 ; j<=3 ; j++){
                loss_arr[i][j] += 5;
            }
		}

		for(int i = 1 ; i<=p ; i++){
            int maxs = loss_arr[mem[i].num][3];
            int mids = loss_arr[mem[i].num][2];
            int mins = loss_arr[mem[i].num][1];
            if(crowd[maxs] <= (p/2)){
                ans += mem[i].dpm[maxs];
                crowd[maxs]++;
            }
            else if(crowd[mids] <= (p/2)){
                ans += mem[i].dpm[mids];
                crowd[mids]++;
            }
            else{
                ans += mem[i].dpm[mins];
                crowd[mins]++;
            }
		}

		if(n>=1)cout << ans << endl;
		else cout << ans;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}

