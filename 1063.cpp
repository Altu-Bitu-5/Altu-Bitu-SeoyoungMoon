#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 50;
const vector<string> DIRECTIONS = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

// dx와 dy를 사용하여 움직임의 방향을 표현
const map<string, pair<int, int>> MOVE = {
    {"R", {0, 1}},
    {"L", {0, -1}},
    {"B", {-1, 0}},
    {"T", {1, 0}},
    {"RT", {1, 1}},
    {"LT", {1, -1}},
    {"RB", {-1, 1}},
    {"LB", {-1, -1}},
};

// 좌표를 받아 체스판 범위 내에 있는지 확인하는 함수
bool in_bound(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

// 메인 함수
int main() {
    // 위치 및 입력 변수 초기화
    string king_pos, stone_pos, direction;
    int n;
    cin >> king_pos >> stone_pos >> n;

    // 좌표는 (행, 열) 형식으로 저장
    pair<int, int> king = {king_pos[1] - '0', king_pos[0] - 'A' + 1};
    pair<int, int> stone = {stone_pos[1] - '0', stone_pos[0] - 'A' + 1};

    // n번의 움직임에 대해 처리
    for (int i = 0; i < n; ++i) {
        cin >> direction;

        // 예상 이동 위치 계산
        int nx = king.first + MOVE.at(direction).first;
        int ny = king.second + MOVE.at(direction).second;

        // 예상 위치가 체스판 내에 있고 돌의 위치와 겹치지 않는 경우
        if (in_bound(nx, ny) && (nx != stone.first || ny != stone.second)) {
            king.first = nx;
            king.second = ny;
        }
        // 예상 위치가 돌의 위치와 겹치는 경우
        else if (nx == stone.first && ny == stone.second) {
            int sx = stone.first + MOVE.at(direction).first;
            int sy = stone.second + MOVE.at(direction).second;

            // 돌도 체스판 내에 있을 경우
            if (in_bound(sx, sy)) {
                stone.first = sx;
                stone.second = sy;
                king.first = nx;
                king.second = ny;
            }
        }
    }

    // 결과 출력
    cout << (char)('A' + king.second - 1) << king.first << '\n';
    cout << (char)('A' + stone.second - 1) << stone.first;

    return 0;
}
