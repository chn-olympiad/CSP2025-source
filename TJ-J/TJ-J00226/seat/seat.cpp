#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[10001];
int arr[15][15];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "W", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    int mb = a[1];
    sort(a + 1, a + n * m + 1, greater<int>());
    /* for (int i = 1; i <= n * m; i++){
        cout << a[i] << " ";
    } */
    if (n > 1 && n <= 10 && m > 1 && m <= 10){
    	if (n % 2 != 0){
    		int x = 1, y = 1, now = 1, c = 1;
	        for (int z = 1; z <= n / 2 + 1; z++){
	        	for (int i = c; i <= c; i++){
		            for (int j = 1; j <= m; j++, y++){
		                arr[i][j] = a[now];
		                now++;
		                if (arr[i][j] == mb){
		                    cout << x << " " << y;
		                    return 0;
		                }
		            }
	        	}
		        c++, x++;
		        for (int i = c; i <= c; i++){
		            for (int j = m; j >= 1; j--, y--){
		                arr[i][j] = a[now];
		                now++;
		                if (arr[i][j] == mb){
		                    cout << x << " " << y;
		                    return 0;
		                }
		            }
		        }
		        c++, x++;
			}
		}else {
			int x = 1, y = 1, now = 1, c = 1;
	        for (int z = 1; z <= n / 2; z++){
	        	for (int i = c; i <= c; i++){
		            for (int j = 1; j <= m; j++, y++){
		                arr[i][j] = a[now];
		                now++;
		                if (arr[i][j] == mb){
		                    cout << x << " " << y;
		                    return 0;
		                }
		            }
	        	}
		        c++, x++;
		        for (int i = c; i <= c; i++){
		            for (int j = m; j >= 1; j--, y--){
		                arr[i][j] = a[now];
		                now++;
		                if (arr[i][j] == mb){
		                    cout << x << " " << y;
		                    return 0;
		                }
		            }
		        }
		        c++, x++;
			}
		}
    }else if (n > 1 && m == 1){
        for (int i = 1; i <= n * m; i++){
            arr[i][1] = a[i];
            if (arr[i][1] == mb){
                cout << "1" << " " << i;
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}