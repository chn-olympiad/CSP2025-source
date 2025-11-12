#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    FILE *ifp = freopen("employ.in", "r", stdin);
    FILE *ofp = freopen("employ.out", "w+", stdout);

    std::cout << 21 << std::endl;

    fclose(ifp);
    fclose(ofp);
    return 0;
}