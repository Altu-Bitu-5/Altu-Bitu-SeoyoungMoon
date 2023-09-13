#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0; // 666이 포함된 숫자를 세는 카운터
    int num = 665; // 검사할 숫자. 665에서 시작해서 1씩 증가시키면서 첫 번째 666부터 탐색

    while (true) {
        num++;
        // to_string 함수를 사용하여 정수를 문자열로 변환한 후 "666" 포함 여부 확인
        if (to_string(num).find("666") != string::npos) {
            count++;
        }
        if (count == n) {
            cout << num << endl;
            break;
        }
    }

    return 0;
}
