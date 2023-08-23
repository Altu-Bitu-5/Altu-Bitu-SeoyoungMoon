#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); // 입출력 속도 개선
    cin.tie(0);
    cout.tie(0);

    int setSize, queryStringCount;
    cin >> setSize >> queryStringCount;

    vector<string> setStrings(setSize); // 주어진 집합 S의 문자열 저장
    vector<string> matchedStrings;

    // 집합 S의 문자열 입력 받기
    for (int i = 0; i < setSize; i++)
        cin >> setStrings[i];

    // 문자열을 정렬하여 binary_search가 가능하게 함
    sort(setStrings.begin(), setStrings.end());

    string query;
    int matchingCount = 0;

    // 입력 문자열 중 집합 S에 포함된 문자열 찾기
    for (int i = 0; i < queryStringCount; i++)
    {
        cin >> query;
        if (binary_search(setStrings.begin(), setStrings.end(), query))
        {
            matchingCount++;
            matchedStrings.push_back(query); // 일치하는 문자열 저장
        }
    }

    // 결과 출력: 집합 S에 포함된 문자열의 수
    cout << matchingCount << '\n';

    return 0;
}
