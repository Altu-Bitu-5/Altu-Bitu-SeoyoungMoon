#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::priority_queue<int> gifts; // 선물의 가치를 관리하기 위한 우선순위 큐

    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if(a == 0) {
            if(gifts.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << gifts.top() << "\n";
                gifts.pop();
            }
        } else {
            for(int j = 0; j < a; ++j) {
                int value;
                std::cin >> value;
                gifts.push(value);
            }
        }
    }

    return 0;
}
