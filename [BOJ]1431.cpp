#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 두 문자열을 비교하는 사용자 정의 함수
int compareStrings(string str1, string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    int sum1 = 0;
    int sum2 = 0;

    // 문자열 길이가 다른 때,
    if (len1 != len2)
    {
        return len1 < len2; // 길이가 짧은 문자열이 앞으로 오도록 정렬
    }

    // 문자열 길이가 같을 때, 각 문자열 내의 숫자들의 합으로 비교
    for (int i = 0; i < str1.size(); i++)
    {
        // str1의 숫자들의 합 계산
        if (str1[i] >= '0' && str1[i] <= '9')
        {
            sum1 += int(str1[i]) - '0';
        }
        // str2의 숫자들의 합 계산
        if (str2[i] >= '0' && str2[i] <= '9')
        {
            sum2 += int(str2[i]) - '0';
        }
    }

    // 숫자들의 합이 다를때.
    if (sum1 != sum2)
    {
        return sum1 < sum2; // 합이 작은 문자열이 앞으로 오도록 정렬
    }

    // 사전 순으로 비교
    return str1 < str2;
}

int main()
{
    int count;
    string inputStrings[50];

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> inputStrings[i];
    }

    // 사용자 정의 함수로 문자열 배열 정렬
    sort(inputStrings, inputStrings + count, compareStrings);
    for (int i = 0; i < count; i++)
    {
        cout << inputStrings[i] << "\n";
    }

    return 0;
}
