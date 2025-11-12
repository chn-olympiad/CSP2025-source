#include <iostream>
#include <algorithm>
#include <vector>

struct Member {
    int s1, s2, s3; // Satisfiement to part1, part2 and part3
};

int max(int a, int b, int c, int d) {
    return std::max(a, std::max(b, std::max(c, d)));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    FILE *ifp = freopen("club.in", "r", stdin);
    FILE *ofp = freopen("club.out", "w+", stdout);

    int T;
    std::cin >> T;

    while(T--) {
        int n;
        std::cin >> n;
        std::vector<Member> members(n + 1);
        bool condition_A = true, condition_B = true;
        for(int i = 1; i <= n; std::cin >> members[i].s1 >> members[i].s2 >> members[i].s3, (members[i].s2 != 0 ? condition_A = false : false), (members[i].s3 != 0 ? condition_B = false : false), ++i); // Input the members array
        if(!condition_B) {
            condition_A = false;
        }
        if(!condition_B) { // Force search
            std::vector<std::vector<std::vector<int>>> dp(n / 2 + 1, std::vector<std::vector<int>>(n / 2 + 1, std::vector<int>(n / 2 + 1, 0)));
            for(int i = n; i >= 1; --i) {
                const Member &mem = members[i];
                for(int j = n / 2; j >= 0; --j) {
                    for(int k = n / 2; k >= 0; --k) {
                        for(int l = n / 2; l >= 0; --l) {
                            bool jok = true, kok = true, lok = true;
                            if(j < 1) {
                                jok = false;
                            }
                            if(k < 1) {
                                kok = false;
                            }
                            if(l < 1) {
                                lok = false;
                            }
                            dp[j][k][l] = max(dp[j][k][l], jok ? dp[j - 1][k][l] + mem.s1 : 0, kok ? dp[j][k - 1][l] + mem.s2 : 0, lok ? dp[j][k][l - 1] + mem.s3 : 0);
                            // std::cout << dp[j][k][l] << ' ';
                        }
                    }
                }
            }
            std::cout << dp[n / 2][n / 2][n / 2] << std::endl;
        } else if(condition_A) { // Satisfy the condition A
            std::sort(members.begin() + 1, members.end(), std::move([](const Member &A, const Member &B) {
                return A.s1 > B.s1;
            }));
            int result = 0;
            for(int i = 1; i <= n / 2; ++i) {
                result += members[i].s1;
            }
            std::cout << result << std::endl;
        } else { // Condition B
            std::vector<std::vector<int>> dp(n / 2 + 1, std::vector<int>(n / 2 + 1, 0));
            for(int i = n; i >= 1; --i) {
                const Member &mem = members[i];
                for(int j = n / 2; j >= 0; --j) {
                    for(int k = n / 2; k >= 0; --k) {
                        bool jok = true, kok = true;
                        if(j < 1) {
                            jok = false;
                        }
                        if(k < 1) {
                            kok = false;
                        }
                        dp[j][k] = std::max(dp[j][k], std::max(jok ? dp[j - 1][k] + mem.s1 : 0, kok ? dp[j][k - 1] + mem.s2 : 0));
                        // std::cout << dp[j][k][l] << ' ';
                    }
                }
            }
            std::cout << dp[n / 2][n / 2] << std::endl;
        }
    }

    fclose(ifp);
    fclose(ofp);
    return 0;
}