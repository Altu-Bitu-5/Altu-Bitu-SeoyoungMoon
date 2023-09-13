#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    int s = 0; // 비트 집합 초기화

    while (m--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;
            s |= (1 << (x - 1)); // x번째 비트를 1로 설정
        } else if (cmd == "remove") {
            int x;
            cin >> x;
            s &= ~(1 << (x - 1)); // x번째 비트를 0으로 설정
        } else if (cmd == "check") {
            int x;
            cin >> x;
            cout << ((s & (1 << (x - 1))) ? 1 : 0) << '\n'; // x번째 비트 확인
        } else if (cmd == "toggle") {
            int x;
            cin >> x;
            s ^= (1 << (x - 1)); // x번째 비트를 반전
        } else if (cmd == "all") {
            s = (1 << 20) - 1; // 모든 비트를 1로 설정
        } else if (cmd == "empty") {
            s = 0; // 모든 비트를 0으로 설정
        }
    }

    return 0;
}
