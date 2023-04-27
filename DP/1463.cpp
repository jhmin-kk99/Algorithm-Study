#include<iostream>
#include<algorithm>
using namespace std;
int d[1000005];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0)d[i] = min(d[i], d[i / 2] + 1);
        if (i % 3 == 0)d[i] = min(d[i], d[i / 3] + 1);
    }
    cout << d[n];

}
//바킹독 실전 알고리즘 강의 참고
//1. 테이블 정의하기
//D[i] = i 를 1로 만들기 위해 필요한 연산 사용 횟수의 최솟값
//
//2. 점화식 찾기
//D[12]=?
//3으로 나누거나 (D[12]=D[4]+1)
//2로 나누거나 (D[12]=D[6]+1)
//1을 빼거나 (D[12]=D[11]+1)
//->min(D[4]+1,D[6]+1,D[11]+1)
//
//D[k]=?
//3으로 나누어지면 3으로 나누거나 (D[k]=D[k/3]+1)
//2로 나누어지면 2로 나누거나 (D[k]=D[k/2]+1)
//1을 빼거나 (D[k]=D[k-1]+1), 이들 중에서 최솟값
//
//3. 초기값 정의하기  
//초기값이 어디까지인지 생각하는 것이 중요
//D[1]=0